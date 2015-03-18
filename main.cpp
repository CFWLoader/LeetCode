#include <iostream>
#include <unistd.h>

using namespace std;

void *thread_method(void* args) {
    sleep(1);
    cout << "pid: " << getpid() << "  Thread id:  " << pthread_self() << endl;
}

int main() {
    pthread_t th;
    pthread_create(&th, 0, thread_method, 0);
    pthread_join(th, 0);
    cout << "Hello, World!" << endl;
    return 0;
}