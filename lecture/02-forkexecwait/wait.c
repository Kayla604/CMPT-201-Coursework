#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  pid_t pid = fork();

  if (pid == 0) {
    execlp("ls", "ls", "-al", NULL);
  } else {
    int status = 0;
    waitpid(pid, &status, 0);
    if (WIFEXITED(status)) {
      printf("Reason: %d\n", WEXITSTATUS(status));
    }
  }

  return 0;
}
