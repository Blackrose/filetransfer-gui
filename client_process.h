#ifndef __CLIENT_PROCESS__
#define __CLIENT_PROCESS__
#ifdef __cplusplus
extern "C" {
#endif

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <sys/types.h>
//#include <sys/socket.h>
#include <fcntl.h>
//#include <sys/types.h>
#include <sys/stat.h>
#include "common.h"


#define DEFAULT_CLIENT_TIME_OUT 2


//void client_process(int sockfd, SSL *ssl);

int send_command_to_server( char *user_input, command_type_t type);
#ifdef __cplusplus
}
#endif


#endif
