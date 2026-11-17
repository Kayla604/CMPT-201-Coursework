#include <stdio.h>
#include <unistd.h>

int main() {
  pid_t pid = fork();

  if (pid == -1) {
    perror("Fork failed\n");
    exit(EXIT_FAILURE);
  } else if (pid == 0) {
    if (execlp("ls", "ls", "-a", "-l", "-h", NULL) == -1) {
      perror("Exec failed\n");
      exit(EXIT_FAILURE);
    }
  } else {
    char *args[] = {"ls", "-a", NULL};
    if (execvp("ls", args) == -1) {
      perror("Exec failed\n");
      exit(EXIT_FAILURE);
    }
  }
}
