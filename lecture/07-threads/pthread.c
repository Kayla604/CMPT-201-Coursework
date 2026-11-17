#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void *newThread(char *word) {
  printf("%s", word);
  printf("%d", gettid());
  printf("%d", strlen(word));

  return (void *)42;
}

int main() {
  pthread_t tid;

  pthread_create(&tid, NULL, newThread, "Banana");

  void *ret_val = 0;
  pthread_join(tid, &ret_val);
  printf("%ul", (uint64_t)ret_val);
  return 0;
}
