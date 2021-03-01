#include "common.h"
#include <mqueue.h>
#define SERVER_QUEUE_NAME   "/sender-reciver"
#define QUEUE_PERMISSIONS 0660
#define MAX_MESSAGES 10
#define MAX_MSG_SIZE 256
#define MSG_BUFFER_SIZE MAX_MSG_SIZE + 10
int main (int argc, char **argv)
{
    char client_queue_name [64];
    mqd_t mqd_server_reciver, mqd_client_reciver;
    sprintf (client_queue_name, "/sp-example-client-%d", getpid ());
    struct mq_attr attr;
    attr.mq_flags = 0;
    attr.mq_maxmsg = MAX_MESSAGES;
    attr.mq_msgsize = MAX_MSG_SIZE;
    attr.mq_curmsgs = 0;
    if ((mqd_client_reciver = mq_open (client_queue_name, O_RDONLY | O_CREAT, QUEUE_PERMISSIONS, &attr)) == -1) {
        perror ("Client: mq_open (client)");
        exit (1);
    }
    if ((mqd_server_reciver = mq_open (SERVER_QUEUE_NAME, O_WRONLY)) == -1) {
        perror ("Client: mq_open (server)");
        exit (1);
    }
    char in_buffer [MSG_BUFFER_SIZE];
    printf ("Ask for a token_number (Press <ENTER>): ");
    char temp_buf [10];
    while (fgets (temp_buf, 2, stdin)) {
        if (mq_send (mqd_server_reciver, client_queue_name, strlen (client_queue_name) + 1, 0) == -1) {
            perror ("Client: Not able to send message to server");
            continue;
        }
        if (mq_receive (mqd_client_reciver, in_buffer, MSG_BUFFER_SIZE, NULL) == -1) {
            perror ("Client: mq_receive");
            exit (1);
        }
        printf ("Client: token_number received from server: %s\n\n", in_buffer);
        printf ("Ask for a token_number (Press ): ");
    }
    if (mq_close (mqd_client_reciver) == -1) {
        perror ("Client: mq_close");
        exit (1);
    }
    if (mq_unlink (client_queue_name) == -1) {
        perror ("Client: mq_unlink");
        exit (1);
    }
    printf ("Client: Goodbye\n");
    exit (0);
}