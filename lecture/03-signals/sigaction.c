#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void handler(int something) { write(STDOUT_FILENO, "CTRL-C pressed\n", 15); }

int main(void) {
  struct sigaction action;
  action.sa_handler = handler;
  action.sa_flags = 0;
  sigemptyset(&action.sa_mask);

  sigaction(SIGINT, &action, NULL);
  while (1) {
    sleep(1);
  }
}
