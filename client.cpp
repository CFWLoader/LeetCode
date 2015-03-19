//
// Created by cfwloader on 3/19/15.
//

#include <iostream>
#include "utils/Socket.h"

using namespace std;

int main(int argc, char* argv[]){
    Socket socket("127.0.0.1", 4991);
    cout << "Status:" << socket.connect() << endl;
    return 0;
}
