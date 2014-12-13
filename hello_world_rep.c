#include <zmq.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include <errno.h>

/* Reply server */

int main (void) {
    void *context = zmq_ctx_new();
    // Server socket
    void *responder = zmq_socket(context, ZMQ_REP);
    zmq_bind(responder, "tcp://*:5555");

    while(true) {
        char buffer [10];
        // Receive a single part message with max length of 10 from the socket
        // and store in the buffer.
        zmq_recv(responder, buffer, 10, 0);
        if (strlen(buffer) != 0)
            printf("Fuck the, %s!\n", buffer);
    }
    return 0;
}

