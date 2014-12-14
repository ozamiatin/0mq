#include <zmq.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>
#include "sugar.h"

/* Broadcast publisher */

int main (void) {
    void *context = zmq_ctx_new();
    void *publisher = zmq_socket(context, ZMQ_PUB);
    if (zmq_bind(publisher, "tcp://*:5556") == -1)
        printf("%s\n", zmq_strerror(errno));

    srandom((unsigned) time(NULL));
    while(true) {
        sleep(1);
        char update[20];
        sprintf(update, "%05d %d %d",
             randof(10000), randof(215) - 80, randof(50) + 10);
        printf("%s\n", update);
        s_send(publisher, update);
    }
    zmq_close(publisher);
    zmq_ctx_destroy(context);
    return 0;
}
