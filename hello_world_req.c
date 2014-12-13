#include <zmq.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include <errno.h>

/* Request client */

int main (void) {
    void *context = zmq_ctx_new();
    // Client socket
    void *requester = zmq_socket(context, ZMQ_REQ);
    zmq_connect(requester, "tcp://localhost:5555");

    while(true) {
        // Send a single part message with length of 5 and content "World" to
        // the socket.
        zmq_send(requester, "system", 6, 0);
    }
    return 0;
}
