#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  pid_t pid = fork();
  if (pid == -1) {
    perror("Fork failed");
    exit(EXIT_FAILURE);
  } else if (pid == 0) {
    if (execl("/bin/ls", "/bin/ls", "-a", "-l", NULL) == -1) {
      perror("Exec failed");
      exit(EXIT_FAILURE);
    }
  } else {
    int wstatus;
    if (waitpid(pid, &wstatus, 0) == -1) {
      perror("Wait failed");
      exit(EXIT_FAILURE);
    } else if (WIFEXITED(wstatus)) {
      printf("Exit Status: %d\n", WEXITSTATUS(wstatus));
    }
  }
}
