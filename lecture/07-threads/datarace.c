#include <pthread.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

const int MAX = 10000000;
int cnt = 0;

void *add(void *unused) {
  for (int i = 0; i < MAX; i++) {
    cnt++;
  }
  return NULL;
}

int main() {

  pthread_t id1;
  if (pthread_create(&id1, NULL, add, NULL) != 0) {
    perror("Unable to create thread.");
    exit(EXIT_FAILURE);
  }

  pthread_t id2;
  if (pthread_create(&id2, NULL, add, NULL) != 0) {
    perror("Unable to create thread.");
    exit(EXIT_FAILURE);
  }

  if (pthread_join(id1, NULL) != 0) {
    perror("Unable to join");
    exit(EXIT_FAILURE);
  }

  if (pthread_join(id2, NULL) != 0) {
    perror("Unable to join");
    exit(EXIT_FAILURE);
  }

  printf("%d\n", cnt);
}
