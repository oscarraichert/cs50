#include <ctype.h>
#include <stdio.h>
#include <string.h>

typedef struct {
  char character;
  int value;
} Letter;

int calculate_player_total(Letter *letters, char *player_input, int letters_length);

int main() {
  char player_1_input[100] = {0};
  char player_2_input[100] = {0};

  Letter letters[] = {
      {'a', 1}, {'b', 3}, {'c', 3},  {'d', 2}, {'e', 1},  {'f', 4}, {'g', 2},
      {'h', 4}, {'i', 1}, {'j', 8},  {'k', 5}, {'l', 1},  {'m', 3}, {'n', 1},
      {'o', 1}, {'p', 3}, {'q', 10}, {'r', 1}, {'s', 1},  {'t', 1}, {'u', 1},
      {'v', 4}, {'w', 4}, {'x', 8},  {'y', 4}, {'z', 10}, 
  };

  printf("Player 1: ");
  scanf("%s", player_1_input);

  printf("Player 2: ");
  scanf("%s", player_2_input);

  int letters_len = sizeof(letters) / sizeof(letters[0]);

  int player_1_total = calculate_player_total(letters, player_1_input, letters_len);
  int player_2_total = calculate_player_total(letters, player_2_input, letters_len);

  if (player_1_total > player_2_total) {
    printf("Player 1 wins!\n");
  } else if (player_1_total < player_2_total) {
    printf("Player 2 wins!\n");
  } else if (player_1_total == player_2_total) {
    printf("Tie!\n");
  }
}

int calculate_player_total(Letter *letters, char *player_input, int letters_length) {
  int total = 0;

  for (int i = 0; i < strlen(player_input); i++) {
    for (int j = 0; j < letters_length; j++) {
      if (letters[j].character == tolower(player_input[i])) {
        total += letters[j].value;
      }
    }
  }

  return total;
}