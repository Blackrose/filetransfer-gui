#ifndef __CLIENT__
#define __CLIENT__

#ifdef __cplusplus
extern "C" {
#endif




int connect_to_server(char *pt, char *adr);
int login(char *user, char *passwd);
void command_to_server(char *command);
void client_process();
char* handle_server_ack();
int handle_user_input( char *user_input);


void test(char *t);
#ifdef __cplusplus
}
#endif

#endif
