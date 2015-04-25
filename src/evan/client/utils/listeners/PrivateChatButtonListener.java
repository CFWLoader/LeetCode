package evan.client.utils.listeners;

import evan.client.utils.ChatClient;

import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.io.IOException;

/**
 * Created by cfwloader on 4/24/15.
 */
public class PrivateChatButtonListener implements ActionListener {

    private ChatClient chatClient;

    private Thread privateRoomThread;

    public PrivateChatButtonListener(ChatClient chatClient) {
        this.chatClient = chatClient;
    }

    @Override
    public void actionPerformed(ActionEvent e) {

        String privateRequest = "request-privateChat-" + chatClient.getGlobalUsername();

        try {
            chatClient.getOutput().writeUTF(privateRequest);
            chatClient.getOutput().flush();
        } catch (IOException e1) {
            e1.printStackTrace();
        }

        privateRoomThread = new Thread(new PrivateRoomThread());

        privateRoomThread.start();
    }

    private class PrivateRoomThread implements Runnable{

        @Override
        public void run() {
            final Frame frame = new Frame("Private room");

            frame.setLocation(600, 150);
            frame.setSize(320, 240);

            frame.addWindowListener(new WindowAdapter() {
                @Override
                public void windowClosing(WindowEvent e) {
                    super.windowClosing(e);

                    frame.dispose();
                }
            });

            frame.setVisible(true);
        }
    }
}
