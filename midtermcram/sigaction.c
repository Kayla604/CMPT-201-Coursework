#include <signal.h>
#include <stdio.h>
#include <string.h>

char *message = "Ctrl-C pressed\n";

void sighandler(int signum) { write(STDOUT_FILENO, message, strlen(message)); }

int main() {
  struct sigaction act;
  act.sa_handler = sighandler;
  act.sa_flags = 0;
  sigemptyset(&act.sa_mask);

  if (sigaction(SIGINT, &act, NULL) == -1) {
    perror();
    exit(EXIT_FAILURE);
  }
}
