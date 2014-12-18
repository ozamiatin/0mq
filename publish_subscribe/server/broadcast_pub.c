#include <zmq.h>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>
//#include "sugar.h"

/* Broadcast publisher */

int main (void) {
    void *context = zmq_ctx_new();
    void *publisher = zmq_socket(context, ZMQ_PUB);
    if (zmq_bind(publisher, "tcp://*:5556") == -1)
        printf("%s\n", zmq_strerror(errno));

    //srandom((unsigned) time(NULL));
    while(true) {
        sleep(1);
        char update[20];
        sprintf(update, "%05d %d %d",
             rand() % 10000, rand() % 215 - 80, rand() % 50 + 10);
        printf("%s\n", update);
        zmq_send(publisher, update, 20, 0);
    }
    zmq_close(publisher);
    zmq_ctx_destroy(context);
    return 0;
}
