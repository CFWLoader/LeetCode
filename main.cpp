#include <iostream>
#include <unistd.h>
#include "utils/ServerSocket.h"

using namespace std;

void *thread_method(void* args) {
    sleep(1);
    cout << "pid: " << getpid() << "  Thread id:  " << pthread_self() << endl;
}

int main() {
    /*
    pthread_t th;
    pthread_create(&th, 0, thread_method, 0);
    pthread_join(th, 0);
    cout << "Hello, World!" << endl;
    */
    ServerSocket serverSocket(4991);
    serverSocket.isInitialized()? cout << "Done." << endl : cout << "Failed." << endl;
    Socket* socket = 0;
    while(true){
        socket = serverSocket.accept();
        cout << "A client connected." << endl;
        delete socket;
    }
    return 0;
}