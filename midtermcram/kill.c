#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

static char *message = "CTRL-C Pressed\n";

void sighandler(int signum) { write(STDOUT_FILENO, message, strlen(message)); }

int main() {
  pid_t pid = fork();
  if (pid == -1) {
    perror("Fork failed");
    exit(EXIT_FAILURE);
  } else if (pid == 0) {
    while (1) {
      sleep(5);
      if (kill(getppid(), SIGINT) == -1) {
        perror("Kill failed");
        exit(EXIT_FAILURE);
      }
    }
  } else {
    struct sigaction act;
    act.sa_handler = sighandler;
    act.sa_flags = 0;
    sigemptyset(&act.sa_mask);

    if (sigaction(SIGINT, &act, NULL) == -1) {
      perror("Sigaction failed");
      exit(EXIT_FAILURE);
    }

    while (1) {
      sleep(1);
    }
  }
}
