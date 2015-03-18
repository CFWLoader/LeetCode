import javax.xml.soap.Text;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.io.*;
import java.net.Socket;
import java.nio.Buffer;
import java.util.Date;

/**
 * Created by cfwloader on 3/16/15.
 */
public class ChatClient extends Frame {

    private TextField textField = new TextField(50);

    private TextArea textArea = new TextArea(40, 80);

    private Socket socket;

    private PrintWriter output;

    private BufferedReader input;

    private Thread massageListenThread;

    public static void main(String[] args){
        new ChatClient().launchFrame();
    }

    public void launchFrame(){

        this.setLocation(600, 150);
        this.setSize(960, 540);
        this.setTitle("Chat Room");

        this.add(textArea, BorderLayout.NORTH);
        this.add(textField, BorderLayout.SOUTH);
        this.pack();

        this.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                try {
                    input.close();
                    output.close();
                    socket.close();
                } catch (IOException e1) {
                    e1.printStackTrace();
                    File exceptionFile = new File("errorlog.txt");
                    try {
                        FileOutputStream outputStream = new FileOutputStream(exceptionFile);
                        PrintWriter printWriter = new PrintWriter(outputStream);
                        for(int i = 0; i < e1.getStackTrace().length; ++i) {
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

        textField.addActionListener(new TextFieldListener());

        this.connect();

        massageListenThread = new Thread(new MassageListenThread(input, textArea));
        massageListenThread.start();

        this.setVisible(true);
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
            output.println(str);
            output.flush();
            textField.setText("");
        }
    }

    public void connect(){
        try {
            socket = new Socket("127.0.0.1", 4991);
            output = new PrintWriter(socket.getOutputStream());
            input = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        } catch (IOException e) {
            e.printStackTrace();
            System.exit(-1);
        }
    }

    private class MassageListenThread implements Runnable{

        private BufferedReader input;

        private TextArea textArea;

        private MassageListenThread(BufferedReader input, TextArea textArea) {
            this.input = input;
            this.textArea = textArea;
        }

        @Override
        public void run() {
            String words;
            while(true){
                try {
                    words = input.readLine();
                    if(words == null)break;
                    textArea.append(String.valueOf(new Date(System.currentTimeMillis())) + "\n");
                    textArea.append("    " + words + "\n\n");
                } catch (IOException e) {
                    e.printStackTrace();
                    input = null;
                    textArea = null;
                }
            }

            input = null;
            textArea = null;
        }
    }
}
