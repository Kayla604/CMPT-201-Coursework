#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  pid_t processID = fork();

  if (processID == 0) {
    printf("Parent's PID: %d\n", getppid());
    printf("Child's PID: %d\n", getpid());
  } else {
    printf("Parent's PID: %d\n", getpid());
    printf("Child's PID: %d\n", processID);
  }
  return 0;
}
