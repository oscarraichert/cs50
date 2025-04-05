#include <stdio.h>

int main() {
  char input[30];

  printf("What's your name?\n");
  scanf("%s", input);

  printf("hello, %s\n", input);
}