#define _POSIX_C_SOURCE 200809
#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static char *message = "CTRL-C Pressed\n";
void handle_sigint(int signum) { write(STDOUT_FILENO, message, strlen(message)); }

int main() {
  pid_t pid = fork();
  if (pid == -1) {
    perror("Unable to fork");
    exit(EXIT_FAILURE);
  }

  if (pid != 0) {
    struct sigaction act;
    act.sa_handler = handle_sigint;
    act.sa_flags = 0;
    sigemptyset(&act.sa_mask);

    int ret = sigaction(SIGINT, &act, NULL);
    if (ret == -1) {
      perror("Sigaction() failed");
      exit(EXIT_FAILURE);
    }

    printf("Parent now dozing...\n");
    while (true) {
      sleep(1);
    }
  } else {
    while (true) {
      sleep(2);
      printf("HEY Parent!\n");
      if (kill(getppid(), SIGINT) == -1) {
        perror("Unable to send signal to parent.");
        exit(EXIT_FAILURE);
      }
    }
  }
}
