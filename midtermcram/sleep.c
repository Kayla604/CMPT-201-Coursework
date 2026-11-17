#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main() {
  char *str = "Hello world!\n";
  fork();
  for (int i = 0; i < strlen(str); i++) {
    printf("%c", str[i]);
    fflush(stdout);
    sleep(3);
  }
}
