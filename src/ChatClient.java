import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.io.IOException;
import java.net.Socket;
import java.util.Date;

/**
 * Created by cfwloader on 3/16/15.
 */
public class ChatClient extends Frame {

    private TextField textField = new TextField(50);

    private TextArea textArea = new TextArea(40, 80);

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
                System.exit(0);
            }
        });

        textField.addActionListener(new TextFieldListener());

        this.connect();

        this.setVisible(true);
    }

    private class TextFieldListener implements ActionListener {

        @Override
        public void actionPerformed(ActionEvent e) {
            String str = textField.getText().trim();
            //textArea.setText(str);
            textArea.append(String.valueOf(new Date(System.currentTimeMillis())) + "\n");
            textArea.append("    " + str + "\n\n");
            textField.setText("");
        }
    }

    public void connect(){
        try {
            Socket socket = new Socket("127.0.0.1", 4991);
        } catch (IOException e) {
            e.printStackTrace();
            System.exit(-1);
        }
    }
}
