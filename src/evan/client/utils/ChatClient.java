package evan.client.utils;

import evan.client.exceptions.LoginFailedException;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.io.*;
import java.net.Socket;
import java.util.Date;

/**
 * Created by cfwloader on 3/16/15.
 */
public class ChatClient extends Frame {

    private Panel panel;

    private TextField textField = new TextField(50);

    private TextArea textArea = new TextArea(40, 80);

    private Socket socket;

    private DataOutputStream output;

    private DataInputStream input;

    private MessageListenThread massageListener;

    private Thread massageListenThread;

    /*
    public static void main(String[] args){
        ChatClient chatClient = new ChatClient();

        if(chatClient.loginFrame() == 0){

            chatClient.removeAll();

            chatClient.launchFrame();
        }
        //new ChatClient().launchFrame();
    }
    */

    public int loginFrame(){

        this.setLocation(750, 400);
        setSize(320, 160);

        Button loginButton = new Button("Login");

        TextField usernameTextField = new TextField(40);
        TextField passwordTextField = new TextField(40);

        this.add(usernameTextField, BorderLayout.NORTH);
        this.add(passwordTextField);
        this.add(loginButton, BorderLayout.AFTER_LAST_LINE);
        this.pack();

        this.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                //System.out.println("Closing event triggered.");
                close();
            }
        });

        //System.out.println("Event added.");

        textField.addActionListener(new TextFieldListener());

        //textField.addActionListener(new TextFieldListener());

        this.connect();

        massageListener = new MessageListenThread(this, input, textArea);
        massageListenThread = new Thread(massageListener);
        //massageListenThread.start();

        this.setVisible(true);

        LoginButtonListener loginButtonListener = new LoginButtonListener(usernameTextField, passwordTextField);

        loginButton.addActionListener(loginButtonListener);

        /*
        String returnCode = null;

        while(returnCode == null){
            returnCode = loginButtonListener.getReturnCode();
        }

        if(!returnCode.equals("ack")){
            System.out.println(returnCode);
            this.close();
        }
        */

        while (loginButtonListener.getReturnCode() == null);

        return 0;
    }

    public void launchFrame(){

        this.setLocation(600, 150);
        this.setSize(960, 540);
        this.setTitle("Chat Room");

        panel.setLayout(new BoxLayout(panel, BoxLayout.Y_AXIS));

        panel.add(new Label("房间中的用户"));

        this.add(textArea, BorderLayout.CENTER);
        this.add(textField, BorderLayout.SOUTH);
        this.add(panel, BorderLayout.EAST);
        this.pack();

        //System.out.println("Frame launched");

        /*
        this.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                //System.out.println("Closing event triggered.");
                try {
                    massageListener.setStopRequest(true);
                    input.close();
                    output.close();
                    socket.close();
                } catch (IOException e1) {
                    e1.printStackTrace();
                    File exceptionFile = new File("errorlog.txt");
                    try {
                        FileOutputStream outputStream = new FileOutputStream(exceptionFile);
                        PrintWriter printWriter = new PrintWriter(outputStream);
                        for (int i = 0; i < e1.getStackTrace().length; ++i) {
                            printWriter.println(e1.getStackTrace()[i]);
                        }
                    } catch (FileNotFoundException e2) {
                        e2.printStackTrace();
                        System.out.println("Fatal error.");
                        System.exit(-4);
                    }
                }
                System.exit(0);
            }
        });
        */

        //System.out.println("Event added.");

        //textField.addActionListener(new TextFieldListener());

        //this.connect();

        /*
            massageListener = new MassageListenThread(input, textArea);
            massageListenThread = new Thread(massageListener);
            massageListenThread.start();
        */

        this.setVisible(true);
    }

    public void requestHandle(String requestString){

    }

    public void connect(){
        try {
            socket = new Socket("127.0.0.1", 4991);
            output = new DataOutputStream(socket.getOutputStream());
            input = new DataInputStream(socket.getInputStream());
        } catch (IOException e) {
            e.printStackTrace();
            System.exit(-1);
        }
    }

    public void close(){
        try {
            massageListener.setStopRequest(true);
            input.close();
            output.close();
            socket.close();
        } catch (IOException e1) {
            e1.printStackTrace();
            File exceptionFile = new File("errorlog.txt");
            try {
                FileOutputStream outputStream = new FileOutputStream(exceptionFile);
                PrintWriter printWriter = new PrintWriter(outputStream);
                for (int i = 0; i < e1.getStackTrace().length; ++i) {
                    printWriter.println(e1.getStackTrace()[i]);
                }
            } catch (FileNotFoundException e2) {
                e2.printStackTrace();
                System.out.println("Fatal error.");
                System.exit(-4);
            }
        }
        System.exit(0);
    }

    private class TextFieldListener implements ActionListener {

        @Override
        public void actionPerformed(ActionEvent e) {
            String str = textField.getText().trim();
            //textArea.setText(str);
            /*
            textArea.append(String.valueOf(new Date(System.currentTimeMillis())) + "\n");
            textArea.append("    " + str + "\n\n");
            */
            try {
                output.writeUTF(str);
                output.flush();
            } catch (IOException e1) {
                e1.printStackTrace();
            }

            textField.setText("");
        }
    }

    private class LoginButtonListener implements ActionListener{

        private TextField username;

        private TextField password;

        private String returnCode = null;

        public LoginButtonListener(TextField username, TextField password) {
            this.username = username;
            this.password = password;
        }

        @Override
        public void actionPerformed(ActionEvent e) {
            String loginStr = "request-login-" + username.getText().trim() + "-" + password.getText().trim();
            /*
            System.out.println(username.getText().trim());
            System.out.println(password.getText().trim());
            */
            try{
                output.writeUTF(loginStr);
                output.flush();
            } catch (IOException e1) {
                e1.printStackTrace();
            }

            try {

                //System.out.println("Waiting return Code");

                //System.out.println(System.currentTimeMillis());

                returnCode = input.readUTF();

                //System.out.println("Return code got.");

            } catch (IOException e1) {
                //e1.printStackTrace();
                returnCode = "failed";
            }

            //System.out.println(returnCode);
            if(returnCode.trim().equals("ack")){
                removeAll();

                launchFrame();

                massageListenThread.start();
            }else if(returnCode.trim().equals("repeated")){

                username.setText("用户已登陆");

            }
        }

        public String getReturnCode() {
            return returnCode;
        }
    }
}