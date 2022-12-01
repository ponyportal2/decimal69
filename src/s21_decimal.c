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
  char a[AB_SIZE] = "87584758623475897345878784953789";
  char b[AB_SIZE] = "4623764782364762374";
  // char a[AB_SIZE] = "9";
  // char b[AB_SIZE] = "9";
  reverse(a);
  reverse(b);
  // char result[RES_SIZE][RAZR_SIZE] = {0};

  // RESULT ALLOC:
  // -------------
  char** result = calloc(RES_SIZE, sizeof(char*));
  for (int i = 0; i < RES_SIZE; i++) {
    result[i] = calloc(RAZR_SIZE, sizeof(char));
  }

  decimAddFirstStep(a, b, result);
  decimAddSecondStep(result);
  int resultSize = sizeDetector(result);
  reverseCharMatrix(result, resultSize);
  printer(result);

  // strcpy(a, "87584758623475897345878784953789");
  // strcpy(b, "4623764782364762374");
  // reverse(a);
  // reverse(b);

  // decimSubFirstStep(a, b, result);
  // decimSubSecondStep(result);
  // resultSize = sizeDetector(result);
  // reverseCharMatrix(result, resultSize);
  // printer(result);

  // FREEING:
  // --------
  for (int i = 0; i < 1024; i++) {
    if (result[i]) free(result[i]);
  }
  if (result) free(result);

  return 0;
}

void decimAddFirstStep(char* a, char* b, char** result) {
  bool aEnded = false;
  bool bEnded = false;
  int i = 0;
  int j = 0;
  char* tempForItoa = calloc(1024, sizeof(char));
  bool whileBreak = false;
  while (whileBreak == false) {
    // printf("a:[%c], b:[%c]\n", a[i], b[i]);
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
  if (tempForItoa) free(tempForItoa);
}

void decimAddSecondStep(char** result) {
  int i = 0;
  char* tempForItoa1 = calloc(1024, sizeof(char));
  // char* tempForItoa2 = calloc(1024, sizeof(char));
  while (strlen(get(result, i)) > 0) {
    if (atoi(result[i]) > 9) {
      // place(atoi(result[i]), result, tempForItoa1, i);
      if (result[i + 1][0] != '\0') {
        itoa(atoi(result[i + 1]) + 1, tempForItoa1, 10);
        strcpy(result[i + 1], tempForItoa1);
      } else {
        result[i + 1][0] = '1';
        // result[i + 1][0] = '1';
        // printf("[%s]", result[i + 1]);
      }
      minusTen(result[i]);
    }

    i++;
  }
  if (tempForItoa1) free(tempForItoa1);
  // if (tempForItoa2) free(tempForItoa2);
}

void minusTen(char* input) {
  input[0] = input[1];
  input[1] = '\0';
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
    // printf("[%s]", inputArr[n - i - 1]);
    strcpy(inputArr[n - i - 1], tempStr);
    // printf("[%s]", tempStr);
    i++;
  }
}

void reverseString(char* inputArr) {
  int i = 0;
  int n = strlen(inputArr);
  while (inputArr[i] != '\0') {
    char tempChar = inputArr[i];
    inputArr[i] = inputArr[n - i - 1];
    inputArr[n - i - 1] = tempChar;
  }
}

int sizeDetector(char** result) {
  int i = 0;
  while (strlen(result[i]) > 0) {
    // printf("i:[%i]", i);
    // printf("s:[%s]\n", result[i]);
    i++;
  }
  return i;
}

void printer(char** result) {
  int i = 0;
  while (strlen(result[i]) > 0) {
    printf("[%s]", result[i]);
    i++;
  }
  printf("\n");
}

// HOMYACHU:
// ------------

// void decimSubFirstStep(char* a, char* b, char** result) {
//   bool aEnded = false;
//   bool bEnded = false;
//   int i = 0;
//   int j = 0;
//   char* tempForItoa = calloc(1024, sizeof(char));
//   bool whileBreak = false;
//   while (whileBreak == false) {
//     // printf("a:[%c], b:[%c]\n", a[i], b[i]);
//     if (a[i] == '\0') aEnded = true;
//     if (b[i] == '\0') bEnded = true;
//     if (aEnded == true && bEnded == true) {
//       whileBreak = true;
//     }
//     sint current = 0;
//     if (aEnded != true && bEnded != true) {
//       current = (a[i] - '0') - (b[i] - '0');
//       // printf("b:[%i]", current);
//       // printf("a:[%i]\n", current);
//       place(current, result, tempForItoa, j);
//     } else if (aEnded) {
//       current = (b[i] - '0');
//       place(current, result, tempForItoa, j);
//     } else if (bEnded) {
//       current = (a[i] - '0');
//       place(current, result, tempForItoa, j);
//     }
//     j++;
//     i++;
//   }
//   if (tempForItoa) free(tempForItoa);
// }

// void decimSubSecondStep(char** result) {
//   int i = 0;
//   char* tempForItoa1 = calloc(1024, sizeof(char));
//   char* tempForItoa2 = calloc(1024, sizeof(char));
//   while (strlen(get(result, i)) > 0) {
//     if (atoi(result[i]) > 9) {
//       itoa(atoi(result[i + 1]) + 1, tempForItoa1, 10);
//       strcpy(result[i + 1], tempForItoa1);
//       minusTen(result[i]);
//       // itoa(atoi(result[i]) - 10, tempForItoa2, 10);
//       // strcpy(result[i], tempForItoa2);
//     }
//     i++;
//   }
//   if (tempForItoa1) free(tempForItoa1);
//   if (tempForItoa2) free(tempForItoa2);
// }

// printf("[%s]\n", get(result, j));

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

// int main() {
//   char* abcd = calloc(64, sizeof(char));
//   strcpy(abcd, "33456232423");

//   unsigned long long int ind1 = 13242344432423;

//   memcpy(&ind1, abcd, 8);
//   printf("%lli", ind1);

//   char* abcd2 = calloc(64, sizeof(char));
//   strcpy(abcd2, "33456232423");

//   unsigned long long int ind2 = 13242344432423;

//   memcpy(abcd2, &ind2, 8);
//   printf("%s", abcd2);

//   if (abcd) free(abcd);
//   if (abcd2) free(abcd2);
// }

// itoa(atoi(result[i]) - 10, tempForItoa2, 10);
// strcpy(result[i], tempForItoa2);
