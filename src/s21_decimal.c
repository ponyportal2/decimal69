#include "s21_decimal.h"

void matrixToString(char** input, char* output) {
  int i = 0;
  while (s21_strlen(input[i]) > 0) {
    strcat(output, input[i]);
    i++;
  }
}

void decimFirstStep(char* a, char* b, char** result, bool isAddition) {
  bool AEnded = false;
  bool BEnded = false;
  int i = 0;
  int j = 0;
  char* tempForItoa = calloc(1024, sizeof(char));
  bool whileBreak = false;
  while (whileBreak == false) {
    // printf("a:[%c], b:[%c]\n", a[i], b[i]);
    if (a[i] == '\0') AEnded = true;
    if (b[i] == '\0') BEnded = true;
    if (AEnded == true && BEnded == true) {
      whileBreak = true;
    }
    int current = 0;
    if (AEnded != true && BEnded != true) {
      if (isAddition) current = (a[i] - '0') + (b[i] - '0');
      if (isAddition == false) current = (a[i] - '0') - (b[i] - '0');
      place(current, result, tempForItoa, j);
    } else if (AEnded) {
      current = (b[i] - '0');
      place(current, result, tempForItoa, j);
    } else if (BEnded) {
      current = (a[i] - '0');
      place(current, result, tempForItoa, j);
    }
    j++;
    i++;
  }
  if (tempForItoa) free(tempForItoa);
}

void decimSecondStepAdd(char** result) {
  int i = 0;
  char* tempForItoa = calloc(1024, sizeof(char));
  while (strlen(result[i]) > 0) {
    if (atoi(result[i]) > 9) {
      if (result[i + 1][0] != '\0') {
        itoa(atoi(result[i + 1]) + 1, tempForItoa);
        strcpy(result[i + 1], tempForItoa);
      } else {
        result[i + 1][0] = '1';
      }
      minusTen(result[i]);
    }
    i++;
  }
  if (tempForItoa) free(tempForItoa);
}

void decimSecondStepSub(char** result) {
  int i = 0;
  char* tempForItoa = calloc(1024, sizeof(char));
  while (strlen(result[i]) > 0) {
    if (atoi(result[i]) < 0) {
      if (strlen(result[i + 1]) > 0) {
        itoa(atoi(result[i + 1]) - 1, tempForItoa);
        strcpy(result[i + 1], tempForItoa);
        itoa(10 + atoi(result[i]), tempForItoa);
        strcpy(result[i], tempForItoa);
      }
    }
    i++;
  }
  if (tempForItoa) free(tempForItoa);
}

void minusTen(char* input) {
  input[0] = input[1];
  input[1] = '\0';
}

void place(int current, char** inputMatrix, char* tempForItoa, int j) {
  // printf("[%i]", current);
  if (current < 0) {
    itoa(current, tempForItoa);
    // printf("[%s]\n", tempForItoa);
  } else {
    itoa(current, tempForItoa);
    // printf("[%s]\n", tempForItoa);
  }
  if (strcmp(tempForItoa, "-48") == 0) {
    strcpy(inputMatrix[j], "\0");
  } else {
    strcpy(inputMatrix[j], tempForItoa);
  }
  // printf("[%s]\n", inputMatrix[j]);
}

void itoa(long long num, char* src) {
  int i = 0, j = 0;
  int digit;
  int radix;
  radix = 10;
  while ((num >= pow(radix, i) && num > 0) ||
         (num <= -pow(radix, i) && num < 0)) {
    digit = (int)(num / pow(radix, i++)) % radix;
    if (num < 0) digit = -digit;
    src[j++] =
        (digit >= 0 && digit <= 9) ? (char)(digit + 48) : (char)(digit + 65);
  }
  if (num == 0) src[j++] = 48;
  if (num < 0) src[j++] = '-';
  src[j] = '\0';
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

// char* get(char** result, int i) {
//   if (i < ATOM_SIZE) {
//     return (char*)result[i];
//   } else {
//     perror("OVERFLOW");
//     return NULL;
//   }
// }

void reverseCharMatrix(char** inputArr, int n) {
  int i = 0;
  while (((n - i - 1) - i) > 0) {
    char tempStr[1024] = {0};
    strcpy(tempStr, inputArr[i]);
    strcpy(inputArr[i], inputArr[n - i - 1]);
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
  while (s21_strlen(result[i]) > 0) {
    i++;
  }
  return i;
}

void printer(char** result) {
  int i = 0;
  printf("out: [");
  do {
    if (i == 0) {
      printf("%2s", result[i]);
    } else {
      printf(",%2s", result[i]);
    }
    i++;
  } while (s21_strlen(result[i]) > 0);
  printf("]\n");
}

size_t s21_strlen(const char* str) {
  size_t len = 0;
  while (*str != '\0') {
    str++;
    len++;
  }
  return (size_t)len;
}

void deDot(char* a, char* b, int* dotPos) {
  char aCpy[MAX_INPUT_SIZE] = {0};
  strcpy(aCpy, a);

  char bCpy[MAX_INPUT_SIZE] = {0};
  strcpy(bCpy, b);
  // -----------------------WHAT IS NEEDED:------------------------
  // char a[AB_SIZE] = "        875.84758623475897345878784953789";
  // char b[AB_SIZE] = "46237647823.64762374000000000000000000000";
  // --------------------------------------------------------------
  bool AEnded = false;
  bool BEnded = false;
  bool ADotFound = false;
  bool BDotFound = false;
  bool ADotParsed = false;
  bool BDotParsed = false;
  char ALeftPart[1024] = {0};
  char BLeftPart[1024] = {0};
  char ARightPart[1024] = {0};
  char BRightPart[1024] = {0};
  int i = 0;
  int j = 0;
  bool whileBreak = false;
  while (whileBreak == false) {
    if (AEnded == false && ADotFound == false) {
      if (a[i] == '\0') {
        AEnded = true;
      } else if (a[i] == '.') {
        ADotFound = true;
      }
    }

    if (BEnded == false && BDotFound == false) {
      if (b[j] == '\0') {
        BEnded = true;
      } else if (b[j] == '.') {
        BDotFound = true;
      }
    }

    if (ADotFound == true || ADotParsed == false) {
      strcpy(ALeftPart, strtok(aCpy, "."));
      strcpy(ARightPart, strtok(NULL, "."));
      ADotParsed = true;
    }
    if (BDotFound == true || BDotParsed == false) {
      strcpy(BLeftPart, strtok(bCpy, "."));
      strcpy(BRightPart, strtok(NULL, "."));
      BDotParsed = true;
    }

    if ((AEnded == true && BEnded == true) &&
        (ADotFound == false && BDotFound == false)) {
      // no dot found
      whileBreak = true;
    } else if (AEnded == true && BEnded == true) {
      whileBreak = true;
    } else if (ADotParsed == true && BDotParsed == true) {
      whileBreak = true;
    }

    if (AEnded == false && ADotFound == false) i++;
    if (BEnded == false && BDotFound == false) j++;
  }

  *dotPos = addZerosAndReturnDotPos(ARightPart, BRightPart);

  strcat(ALeftPart, ARightPart);
  strcat(BLeftPart, BRightPart);

  strcpy(a, ALeftPart);
  strcpy(b, BLeftPart);
}

int addZerosAndReturnDotPos(char* a, char* b) {
  int dotPos = -1;
  int i = 0;
  size_t biggerStrlen = strlen(a) > strlen(b) ? strlen(a) : strlen(b);
  while (strlen(a) < biggerStrlen || strlen(b) < biggerStrlen) {
    if (strlen(a) < strlen(b)) {
      a[strlen(a) + i] = '0';
    } else {
      b[strlen(b) + i] = '0';
    }
  }
  dotPos = strlen(a);
  return dotPos;
}

void reAddZero(char* input, int dotPos) {
  char tempStr[1024] = {0};
  strncat(tempStr, input, strlen(input) - dotPos);
  strcat(tempStr, ".");
  strcat(tempStr, (char*)input + strlen(input) - dotPos);
  strcpy(input, tempStr);
}

void decimMulti(char* a, char* b) {
  // UGLY NECESSARY CALLOCS:
  // -----------------------
  char*** subProducts = calloc(MAX_ATOMS, sizeof(char**));
  for (int i = 0; i < MAX_ATOMS; i++) {
    subProducts[i] = calloc(MAX_ATOMS, sizeof(char*));
    for (int j = 0; j < MAX_ATOMS; j++) {
      subProducts[i][j] = calloc(ATOM_SIZE, sizeof(char));
    }
  }

  // bool AEnded = false;
  // bool BEnded = false;
  // int curLineResult = -2147483640;
  char* tempForItoa = calloc(1024, sizeof(char));
  // bool whileBreak = false;
  int aLen = strlen(a);
  int bLen = strlen(b);

  for (int ai = 0; ai < aLen; ai++) {
    for (int bi = 0; bi < bLen; bi++) {
      if ((b[bi] - '0') == 0) {
        // do nothing
      } else {
        int current = (a[ai] - '0') * (b[bi] - '0');
        place(current, subProducts[bi], tempForItoa, ai);
      }
    }
  }

  // decimSecondStepSub(result);
  for (size_t i = 0; i < MAX_ATOMS; i++) {
    int resultSize = sizeDetector(subProducts[i]);
    reverseCharMatrix(subProducts[i], resultSize);
    char outputString[1024] = {0};
    if (subProducts[i][0][0] != '\0') {
      printer(subProducts[i]);
    }
    matrixToString(subProducts[i], outputString);
    // reAddZero(outputString, dotPos);
    // if (strlen(outputString) > 0) {
    //   printf("%s\n", outputString);
    // }
  }

  // while (whileBreak == false) {
  //   if (a[i] == '\0') AEnded = true;
  //   if (b[i] == '\0') BEnded = true;
  //   if (AEnded == true && BEnded == true) {
  //     whileBreak = true;
  //   }
  //   int current = 0;
  //   if (AEnded != true && BEnded != true) {
  //     current = (a[i] - '0') * (b[i] - '0');
  //     place(current, result, tempForItoa, j);
  //     printf("[%s]\n", get(result, j));
  //   } else if (AEnded) {
  //     current = (b[i] - '0');
  //     place(current, result, tempForItoa, j);
  //   } else if (BEnded) {
  //     current = (a[i] - '0');
  //     place(current, result, tempForItoa, j);
  //   }
  //   j++;
  //   i++;
  // }
  if (tempForItoa) free(tempForItoa);

  for (int i = 0; i < MAX_ATOMS; i++) {
    for (int j = 0; j < MAX_ATOMS; j++) {
      if (subProducts[i][j]) free(subProducts[i][j]);
    }
    if (subProducts[i]) free(subProducts[i]);
  }
  if (subProducts) free(subProducts);

  // int i = 0;
  // char* tempForItoa1 = calloc(1024, sizeof(char));
  // while (strlen(get(result, i)) > 0) {
  //   if (atoi(result[i]) > 9) {
  //     if (result[i + 1][0] != '\0') {
  //       itoa(atoi(result[i + 1]) + 1, tempForItoa1);
  //       strcpy(result[i + 1], tempForItoa1);
  //     } else {
  //       result[i + 1][0] = '1';
  //     }
  //     minusTen(result[i]);
  //   }
  //   i++;
  // }

  // if (firstStr) free(firstStr);
}

// HOMYACHU:
// ------------

// char** secStr = calloc(RES_SIZE, sizeof(char*));
// for (int i = 0; i < RES_SIZE; i++) {
//   result[i] = calloc(RAZRYADS_SIZE, sizeof(char));
// }
// -----------------------

// if (secStr) free(secStr);

// printf("[%s]", inputArr[n - i - 1]);

// char tempForItoa[1024] = {0};

// printf("i:[%i]", i);
// printf("s:[%s]\n", result[i]);

// char* tempForItoa2 = calloc(1024, sizeof(char));

// result[i + 1][0] = '1';
// printf("[%s]", result[i + 1]);

// if (tempForItoa1) free(tempForItoa1);
// if (tempForItoa2) free(tempForItoa2);

// place(atoi(result[i]), result, tempForItoa1, i);

// printf("[%s]\n", a);
// printf("[%s]\n\n", b);

// int finalDotPos = 0;

// printf("a:[%c], b:[%c]\n", a[i], b[i]);

// int MultiTable(int a, int b) {
//   int returnValue = -2147483640;
//   if (a == 0 || b == 0) {
//     returnValue = 0;
//   } else if (a == 1) {
//     returnValue = b;
//   } else if (b == 1) {
//     returnValue = a;
//   } else {
//     int two[10] = {0,1,2,4,6,8,10,12,14,16,18,20};
//     int three[10] = {0,1,2,4,6,8,10,12,14,16,18,20};
//   }
// };

// printf("[\n%c]", a[i]);
// printf("[\n%c]", b[j]);

// void decimSubFirstStep(char* a, char* b, char** result) {
//   bool AEnded = false;
//   bool BEnded = false;
//   int i = 0;
//   int j = 0;
//   char* tempForItoa = calloc(1024, sizeof(char));
//   bool whileBreak = false;
//   while (whileBreak == false) {
//     // printf("a:[%c], b:[%c]\n", a[i], b[i]);
//     if (a[i] == '\0') AEnded = true;
//     if (b[i] == '\0') BEnded = true;
//     if (AEnded == true && BEnded == true) {
//       whileBreak = true;
//     }
//     sint current = 0;
//     if (AEnded != true && BEnded != true) {
//       current = (a[i] - '0') - (b[i] - '0');
//       // printf("b:[%i]", current);
//       // printf("a:[%i]\n", current);
//       place(current, result, tempForItoa, j);
//     } else if (AEnded) {
//       current = (b[i] - '0');
//       place(current, result, tempForItoa, j);
//     } else if (BEnded) {
//       current = (a[i] - '0');
//       place(current, result, tempForItoa, j);
//     }
//     j++;
//     i++;
//   }
//   if (tempForItoa) free(tempForItoa);
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
