import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

/**
 * Created by cfwloader on 3/17/15.
 */
public class ChatServer {

    private ServerSocket serverSocket;

    public static void main(String[] args){

        ChatServer chatServer = new ChatServer();

        while(true){
            try {
                Socket socket = chatServer.serverSocket.accept();
                System.out.println("A client joint.");
            } catch (IOException e) {
                e.printStackTrace();
                System.out.println("A client failed to connect.");
            }
        }
    }

    ChatServer(){
        try {
            serverSocket = new ServerSocket(4991);
        } catch (IOException e) {
            e.printStackTrace();
            System.exit(-1);
        }
    }
}
