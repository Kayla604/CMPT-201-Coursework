#include <stdio.h>
#include <unistd.h>

int main() {
  pid_t pid = fork();
  if (pid == -1) {
    perror("Fork failed\n");
    exit(EXIT_FAILURE);
  } else if (pid == 0) {
    printf("Parent: %d\n", getppid());
    printf("Child: %d\n", getpid());
  } else {
    printf("Parent: %d\n", getpid());
    printf("Child: %d\n", pid);
  }
}
