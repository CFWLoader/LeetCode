package evan.client.utils.thread;

import evan.client.utils.listeners.PrivateRoomFrame;

/**
 * Created by cfwloader on 4/25/15.
 */
public class PrivateRoomThread implements Runnable {

    private PrivateRoomFrame privateRoomFrame;

    public PrivateRoomThread(PrivateRoomFrame privateRoomFrame) {
        this.privateRoomFrame = privateRoomFrame;
    }

    @Override
    public void run() {

        privateRoomFrame.launch();

    }
}
