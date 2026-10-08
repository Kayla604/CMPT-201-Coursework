#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool find_first_digit(char *data, int n, char **pdigit) {
  for (int i = 0; i < n; i++) {
    if (isdigit(data[i])
    {
      *pdigit = &data[i];
      return true;
    }
  }
  return false;
}
