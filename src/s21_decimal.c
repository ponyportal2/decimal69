#include "s21_decimal.h"

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define sint char
#define MAXLINE 2048

int main() {
  char a[1024] = "8326731548612467647832";
  char b[1024] = "8326731548612467647833";
  char result[1024][1024] = {0};
  // for (int i = 0; i < 1024; i++) {
  //   char* result = calloc(1024, sizeof(char));
  // }

  decAdd(a, b, result);
  printf("\nDEBUG\n");
  int i = 0;
  while (strlen(result[i]) > 0) {
    printf("[%s]", result[i]);
    i++;
  }

  return 0;
}

void decAdd(char a[1024], char b[1024], char result[][1024]) {
  bool aEnded = false;
  bool bEnded = false;
  int i = 0;
  int j = 0;
  char* tempForItoa = calloc(1024, sizeof(char));
  while (aEnded != true && bEnded != true) {
    if (a[i] == '\0') aEnded = true;
    if (b[i] == '\0') bEnded = true;
    if (aEnded != true && bEnded != true) {
      // printf("\nDEBUG\n");
      // printf("[%c][%c]\n", a[i], b[i]);
      sint current = (a[i] - '0') + (b[i] - '0');
      itoa((int)current, tempForItoa, 10);
      strcpy(result[j], tempForItoa);
      printf("[%s]\n", result[j]);
    }
    j++;
    i++;
  }
  free(tempForItoa);
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
  char temp[MAXLINE];
  strcpy(temp, string);
  int length = strlen(string);
  int i;
  for (i = 0; i < length; i++) string[i] = temp[length - i - 1];
  string[i] = '\0';
}

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