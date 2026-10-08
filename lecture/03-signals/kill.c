#define _POSIX_C_SOURCE 200809
#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static char *message = "CTRL-C Pressed\n";
void handler(int signal) { write(STDOUT_FILENO, message, strlen(message)); }

int main() {
  struct sigaction act; // I FORGOT THAT THIS WAS SUPPOSED TO ONLY GO WITH THE PARENTTTTTTTT
  act.sa_handler = handler;
  act.sa_flags = 0;
  sigemptyset(&act.sa_mask);

  pid_t pid = fork();

  if (pid == 0) {
    while (true) {
      sleep(5);
      kill(getppid(), SIGINT);
    }
  } else if (pid == -1) {
    perror("Fork failed\n");
    exit(EXIT_FAILURE);
  } else {
    sigaction(SIGINT, &act, NULL);
    while (true) {
      sleep(1);
    }
  }
}
