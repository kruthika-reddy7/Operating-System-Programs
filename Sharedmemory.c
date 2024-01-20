#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() {
  // Create a shared memory segment.
  int shmid = shmget((key_t)12345, 1024, IPC_CREAT | 0666);
  if (shmid == -1) {
    perror("shmget");
    exit(1);
  }

  // Attach the shared memory segment to the address space of the process.
  void *shared_memory = shmat(shmid, NULL, 0);
  if (shared_memory == NULL) {
    perror("shmat");
    exit(1);
  }

  // Write to the shared memory segment.
  strcpy((char *)shared_memory, "Hello, world!");

  // Detach the shared memory segment from the address space of the process.
  shmdt(shared_memory);

  return 0;
}

