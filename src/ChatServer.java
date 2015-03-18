import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;

/**
 * Created by cfwloader on 3/17/15.
 */
public class ChatServer {

    private ServerSocket serverSocket;

    public static void main(String[] args) {

        ChatServer chatServer = new ChatServer();

        while (true) {
            try {
                Socket socket = chatServer.serverSocket.accept();
                System.out.println("A client joint." + socket.getPort());
                Thread clientServiceThread = new Thread(new ClientService(socket));
                clientServiceThread.start();
            } catch (IOException e) {
                e.printStackTrace();
                System.out.println("A client failed to connect.");
            }
        }
    }

    ChatServer() {
        try {
            serverSocket = new ServerSocket(4991);
        } catch (IOException e) {
            e.printStackTrace();
            System.exit(-1);
        }
    }

    private static class ClientService implements Runnable {

        private Socket clientSocket;

        private BufferedReader inputStream;

        ClientService(Socket socket) {
            clientSocket = socket;
            try {
                inputStream = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
            } catch (IOException e) {
                e.printStackTrace();
            }/* finally {

                clientSocket = null;
                try {
                    clientSocket.close();
                } catch (IOException e) {
                    e.printStackTrace();
                    System.exit(-2);
                }
            }*/
        }

        @Override
        public void run() {
            String words;
            while (true) {
                try {
                    words = inputStream.readLine();
                    if(words == null)break;
                    System.out.println(words);
                } catch (IOException e) {
                    e.printStackTrace();
                }/* finally {
                    try {
                        inputStream.close();
                        clientSocket.close();
                    } catch (IOException e) {
                        e.printStackTrace();
                        System.exit(-3);
                    }
                }*/
            }
            try {
                inputStream.close();
                clientSocket.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }
}
