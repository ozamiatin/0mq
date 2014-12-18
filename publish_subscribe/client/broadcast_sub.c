#include <string.h>
#include <zmq.h>
#include <stdbool.h>

/* Broadcast subscriber */

int main () {
    void *context = zmq_ctx_new();
    void *subscriber = zmq_socket(context, ZMQ_SUB);
    if (zmq_connect(subscriber, "tcp://localhost:5556") == -1)
        printf("Error: %s\n", zmq_strerror(errno));

    zmq_setsockopt(subscriber, ZMQ_SUBSCRIBE, 0, 0);

    while(true) {
        char update[20];
        zmq_recv(subscriber, update, 20, 0);
        if (strlen(update) == 0)
            printf("No message\n");
        else
            printf("%s\n", update);
    }
    zmq_close(subscriber);
    zmq_ctx_destroy(context);
    return 0;
}
