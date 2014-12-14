/* Helpers and wrappers */
#include <zmq.h>
#include <string.h>
#include <stdlib.h>
#include "sugar.h"

int s_send (void *socket, char *string) {
    return zmq_send (socket, string, strlen (string), ZMQ_SNDMORE);
}
