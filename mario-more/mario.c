#include <stdio.h>
#include <stdlib.h>

// Height: 4
//    #  #
//   ##  ##
//  ###  ###
// ####  ####

void print_row(int bricks, int height);

int main() {
  char input[10];
  int height;

  do {
    printf("Height: ");
    scanf("%s", input);

    height = atoi(input);

  } while (height < 1 || height > 8);

  for (int i = 0; i < height; i++) {
    print_row(i + 1, height);
  }
}

void print_row(int bricks, int height) {
  int blanks = height - bricks;
  for (int i = 0; i < height; i++) {
    if (i < blanks) {
      printf(" ");
    } else {
      printf("#");
    }
  }

  printf("  ");

  for (int i = 0; i < bricks; i++) {
    printf("#");
  }
  printf("\n");
}