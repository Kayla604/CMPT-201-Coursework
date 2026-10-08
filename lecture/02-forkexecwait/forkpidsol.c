#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  printf("Start PID=%d, parent PID=%d\n", getpid(), getppid());
  pid_t pid = fork();

  if (pid == 0) {
    printf("CHILD: PID=%d, parentPID=%d\n", getpid(), getppid());
  } else {
    printf("PARENT: PID=%d, childPID=%d\n", getpid(), pid);
  }
}
