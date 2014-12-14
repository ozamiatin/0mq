#ifndef SUGAR
#define SUGAR
int s_send (void *socket, char *string);
#define randof(num)  (int) ((float) (num) * random() / (RAND_MAX + 1.0))
#endif
