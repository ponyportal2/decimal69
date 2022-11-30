#include "s21_decimal.h"

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define AB_SIZE 256
#define RES_SIZE 1024

int main() {
  // char a[AB_SIZE] = "8326731548612467647832";
  // char b[AB_SIZE] = "8326731548612467647833";
  char a[AB_SIZE] = "1111111111111111111111";
  char b[AB_SIZE] = "19";
  // char result[RES_SIZE][RAZR_SIZE] = {0};

  // RESULT ALLOC:
  // -------------
  char** result = calloc(RES_SIZE, sizeof(char*));
  for (int i = 0; i < RES_SIZE; i++) {
    result[i] = calloc(RAZR_SIZE, sizeof(char));
  }

  decAdd(a, b, result);

  int resultSize = sizeDetector(result);

  decAddSecondStep(result);

  reverseCharMatrix(result, resultSize);
  printer(result);
  // FREEING:
  // --------
  for (int i = 0; i < 1024; i++) {
    free(result[i]);
  }
  free(result);

  return 0;
}

void decAddFirstStep(char* a, char* b, char** result) {
  bool aEnded = false;
  bool bEnded = false;
  int i = 0;
  int j = 0;
  char* tempForItoa = calloc(1024, sizeof(char));
  bool whileBreak = false;
  while (whileBreak == false) {
    printf("a:[%c], b:[%c]\n", a[i], b[i]);
    if (a[i] == '\0') aEnded = true;
    if (b[i] == '\0') bEnded = true;
    if (aEnded == true && bEnded == true) {
      whileBreak = true;
    }
    sint current = 0;
    if (aEnded != true && bEnded != true) {
      current = (a[i] - '0') + (b[i] - '0');
      place(current, result, tempForItoa, j);
      // printf("[%s]\n", get(result, j));
    } else if (aEnded) {
      current = (b[i] - '0');
      place(current, result, tempForItoa, j);
    } else if (bEnded) {
      current = (a[i] - '0');
      place(current, result, tempForItoa, j);
    }
    j++;
    i++;
  }
  free(tempForItoa);
}

void decAddSecondStep(char** result) {
  int i = 0;
  while (result[i] != '\0') {
    decAddFirstStep(result[i], result[i + 1], result);
  }
}

void place(sint current, char** result, char* tempForItoa, int j) {
  itoa((int)current, tempForItoa, 10);
  strcpy(get(result, j), tempForItoa);
}

void itoa(long long num, char* src, int radix) {
  int i = 0, j = 0;
  int digit;
  if (num < 0) {
    src[0] = '-';
    j++;
  }
  while (num >= pow(radix, i)) {
    digit = (int)(num / pow(radix, i)) % radix;
    src[i++] =
        (digit >= 0 && digit <= 9) ? (char)(digit + 48) : (char)(digit + 65);
  }
  src[i] = '\0';
  reverse(src);
}

void reverse(char* string) {
  char temp[MAXLINE_FOR_REVERSE];
  strcpy(temp, string);
  int length = strlen(string);
  int i;
  for (i = 0; i < length; i++) string[i] = temp[length - i - 1];
  string[i] = '\0';
}

char* get(char** result, int i) {
  if (i < RAZR_SIZE) {
    return (char*)result[i];
  } else {
    perror("OVERFLOW");
    return NULL;
  }
}

void reverseCharMatrix(char** inputArr, int n) {
  int i = 0;
  while (((n - i - 1) - i) > 0) {
    char tempStr[1024] = {0};
    strcpy(tempStr, inputArr[i]);
    strcpy(inputArr[i], inputArr[n - i - 1]);
    strcpy(inputArr[n - i - 1], tempStr);
    i++;
  }
}

int sizeDetector(char** result) {
  int i = 0;
  while (strlen(get(result, i)) > 0) {
    i++;
  }
  return i;
}

void printer(char** result) {
  int i = 0;
  while (strlen(get(result, i)) > 0) {
    printf("[%s]", get(result, i));
    i++;
  }
}

// HOMYACHU:

// printf("\nDEBUG\n");
// printf("[%c][%c]\n", a[i], b[i]);

// int s21_atoi(char* str) {
//   int length = s21_strlen(str);
//   int returnValue = 0;
//   int sign = 1;
//   int i = 0;
//   while (s21_match("\t \n", str[i])) {
//     i++;
//   }
//   for (; i < length; i++) {
//     if (str[i] == '+' || str[i] == '-') {
//       if (str[i] == '-') {
//         sign = -1;
//       }
//       i++;
//     }
//     if (!(str[i] >= '0' && str[i] <= '9')) {
//       break;
//     }
//     returnValue = returnValue * 10 + (str[i] - 48);
//   }
//   return sign * returnValue;
// }

// bool s21_match(const char* inputCharArr, char inputChar) {
//   int match = false;
//   int i = 0;
//   while (inputCharArr[i] != '\0') {
//     if (inputCharArr[i] == inputChar) {
//       match = true;
//     }
//     i++;
//   }
//   return match;
// }
