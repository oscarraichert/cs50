#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int validate_digits(char *input, char *flag);
int validate_checksum(char *input);

int main() {
  char input[20] = {0};
  char flag[20] = {0};
  long long number = 0;

  do {
    printf("Number: ");
    scanf("%s", input);

    number = atoll(input);
  } while (number < 1);

  int valid_checksum = validate_checksum(input);

  if (!valid_checksum) {
    strcat(flag, "INVALID");
    printf("%s\n", flag);
    return 0;
  }

  int valid_digits = validate_digits(input, flag);

  if (!valid_digits) {
    printf("%s\n", flag);
    return 0;
  }

  printf("%s\n", flag);
}

int validate_digits(char *input, char *flag) {
  if (strlen(input) == 15 && input[0] == '3' &&
      (input[1] == '4' || input[1] == '7')) {
    strcat(flag, "AMEX");
    return 1;
  }

  else if (strlen(input) == 16 && input[0] == '5' &&
           (input[1] - '0' >= 1 && input[1] - '0' <= 5)) {
    strcat(flag, "MASTERCARD");
    return 1;
  }

  else if ((strlen(input) == 13 || strlen(input) == 16) && input[0] == '4') {
    strcat(flag, "VISA");
    return 1;
  }

  else {
    strcat(flag, "INVALID");
    return 0;
  }
}

int validate_checksum(char *input) {
  int checksum = 0;
  int num_len = strlen(input);
  int is_odd = num_len % 2 > 0;
  char digits[num_len];
  digits[0] = 0;
  int digits_index = 0;

  for (int i = 0; i < num_len; i++) {
    if (is_odd == 1) {
      char current_digit[3] = {0};

      if (i % 2 > 0) {
        sprintf(current_digit, "%d", (input[i] - '0') * 2);
      } else {
        sprintf(current_digit, "%d", input[i] - '0');
      }
      strcat(digits, current_digit);
    }

    else if (!is_odd) {
      char current_digit[3] = {0};

      if (i % 2 == 0) {
        sprintf(current_digit, "%d", (input[i] - '0') * 2);
      } else {
        sprintf(current_digit, "%d", input[i] - '0');
      }
      strcat(digits, current_digit);
    }

    digits_index++;
  }

  for (int i = 0; i < strlen(digits); i++) {
    checksum += digits[i] - '0';
  }

  if (checksum % 10 == 0) {
    return 1;
  } else
    return 0;
}