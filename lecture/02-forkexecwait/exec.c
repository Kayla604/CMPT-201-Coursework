#include <stdio.h>
#include <unistd.h>

int main() {
  if (fork() == 0) {
    execls("ls", "ls", "-alh", (char *)NULL);
  } else {
    execlp("ls", "ls", "-a", (char *)NULL);
  }
}
