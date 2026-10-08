#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  pid_t pid = fork();

  if (pid == 0) {

    char *args[] = {"echo", "hello", "world", NULL};
    execvp("echo", args);
  } else {
    execlp("ls", "ls", "-alh", NULL);
  }
}
