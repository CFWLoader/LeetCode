package evan.server.utils;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.EOFException;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

/**
 * Created by cfwloader on 4/16/15.
 */
public class ClientService extends Thread implements Comparable<ClientService>{

    private ChatServer host;

    private Socket clientSocket;

    private DataInputStream inputStream;

    private DataOutputStream outputStream;

    private String username;

    public ClientService(ChatServer chatServer, Socket socket) {

        this.host = chatServer;

        clientSocket = socket;

        try {
            inputStream = new DataInputStream(clientSocket.getInputStream());
            outputStream = new DataOutputStream(clientSocket.getOutputStream());
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
                words = inputStream.readUTF();
                if(words == null)break;
                System.out.println(words);
                host.broadcast(username + ": " + words);
            } catch (EOFException eof){
                break;
            } catch (IOException e) {
                break;
                //e.printStackTrace();
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
            inputStream.close();

            host.getClients().remove(this);
            System.out.println("Client: " + clientSocket.getPort() + " exited.");

            clientSocket.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public DataOutputStream getOutputStream() {
        return outputStream;
    }

    public DataInputStream getInputStream() {
        return inputStream;
    }

    @Override
    public int compareTo(ClientService o) {
        if(o == null)return -1;
        if(this == o)return 0;
        else return 1;
    }

    public String getUsername() {
        return username;
    }

    public void setUsername(String username) {
        this.username = username;
    }
}
