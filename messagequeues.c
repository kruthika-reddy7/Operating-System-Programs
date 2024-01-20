#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

typedef struct {
  long mtype; // message type
  char mtext[100]; // message text
} message_t;

int main() {
  // Generate a unique key for the message queue.
  int key = ftok(".", 1);

  // Create the message queue.
  int msqid = msgget(key, IPC_CREAT | 0666);
  if (msqid == -1) {
    perror("msgget");
    exit(1);
  }

  // Send a message to the queue.
  message_t msg;
  msg.mtype = 1;
  strcpy(msg.mtext, "Hello, world!");
  if (msgsnd(msqid, &msg, sizeof(message_t), 0) == -1) {
    perror("msgsnd");
    exit(1);
  }

  // Receive a message from the queue.
  message_t recv_msg;
  if (msgrcv(msqid, &recv_msg, sizeof(message_t), 1, 0) == -1) {
    perror("msgrcv");
    exit(1);
  }

  // Print the received message.
  printf("Received message: %s\n", recv_msg.mtext);

  // Destroy the message queue.
  msgctl(msqid, IPC_RMID, NULL);

  return 0;
}


