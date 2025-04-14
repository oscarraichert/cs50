#include <stdio.h>

#define ALPHABET_LENGTH 26

struct Letter {
  char character;
  int value;
};

void populate_letters(struct Letter *letters, int length);

int main() {
  char player_1_input[100] = {0};
  char player_2_input[100] = {0};

  struct Letter letters[] = {
      {'a', 1}, {'b', 3}, {'c', 3},  {'d', 2}, {'e', 1},  {'f', 4}, {'g', 2},
      {'h', 4}, {'i', 1}, {'j', 8},  {'k', 5}, {'l', 1},  {'m', 3}, {'n', 1},
      {'o', 1}, {'p', 3}, {'q', 10}, {'r', 1}, {'s', 1},  {'t', 1}, {'u', 1},
      {'v', 4}, {'w', 4}, {'x', 8},  {'y', 4}, {'z', 10},
  };

  for (int i = 0; i < ALPHABET_LENGTH; i++) {
    printf("letter: %c\nvalue: %d\n", letters[i].character, letters[i].value);
  }

  //   printf("Player 1: ");
  //   scanf("%s", player_1_input);

  //   printf("%s\n", player_1_input);

  //   printf("Player 2: ");
  //   scanf("%s", player_2_input);

  //   printf("%s\n", player_2_input);
}