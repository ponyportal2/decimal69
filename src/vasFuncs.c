#include "vasFuncs.h"

int s21_add_pos_10String(char* a, char* b, char* result) {
  // DONT FORGET THAT v10StringFirstStep REQUIRES ADDITION/SUBTRACTION SPECIFIER
  int dotPos = 0;
  char localA[VAS_INPUT_SIZE_MAX + 1] = {0};
  char localB[VAS_INPUT_SIZE_MAX + 1] = {0};
  strcpy(localA, a);
  strcpy(localB, b);

  char** localResult = calloc(VAS_MULTIPLY_SUBPRODUCTS, sizeof(char*));
  for (int i = 0; i < VAS_MULTIPLY_SUBPRODUCTS; i++) {
    localResult[i] = calloc(VAS_MULTIPLY_SUBPRODUCT_SIZE, sizeof(char));
  }

  deDot(localA, localB, &dotPos);

  reverseString(localA);
  reverseString(localB);

  // dont forget sub/add specifier:
  v10StringFirstStep(localA, localB, localResult, true);
  v10StringSecondStepAdd(localResult);
  int resultSize = matrixSizeDetector(localResult);
  reverseCharMatrix(localResult, resultSize);
  char outputString[1024] = {0};
  matrixToString(localResult, outputString);

  if (outputString[dotPos - 1] != '\0') {
    reAddZero(outputString, dotPos);
  }

  for (int i = 0; i < VAS_MULTIPLY_SUBPRODUCTS; i++) {
    if (localResult[i]) free(localResult[i]);
  }
  if (localResult) free(localResult);

  strcpy(result, outputString);

  return 1;  // fix return later
}

// SUBTRACTION ONLY WORKS IF THE FIRST NUMBER IS BIGGER,
// IF THE FIRST NUMBER IS SMALLER THEN
// SWAP THE NUMBERS AND APPEND A MINUS INSTEAD
int s21_sub_pos_10String(char* a, char* b, char* result) {
  // DONT FORGET THAT v10StringFirstStep REQUIRES ADDITION/SUBTRACTION SPECIFIER
  int dotPos = 0;
  char localA[VAS_INPUT_SIZE_MAX + 1] = {0};
  char localB[VAS_INPUT_SIZE_MAX + 1] = {0};
  strcpy(localA, a);
  strcpy(localB, b);

  char** localResult = calloc(VAS_MULTIPLY_SUBPRODUCTS, sizeof(char*));
  for (int i = 0; i < VAS_MULTIPLY_SUBPRODUCTS; i++) {
    localResult[i] = calloc(VAS_MULTIPLY_SUBPRODUCT_SIZE, sizeof(char));
  }

  deDot(localA, localB, &dotPos);

  reverseString(localA);
  reverseString(localB);

  // dont forget sub/add specifier:
  v10StringFirstStep(localA, localB, localResult, false);
  v10StringSecondStepSub(localResult);
  int resultSize = matrixSizeDetector(localResult);
  reverseCharMatrix(localResult, resultSize);
  char outputString[1024] = {0};
  matrixToString(localResult, outputString);

  if (outputString[dotPos - 1] != '\0') {
    reAddZero(outputString, dotPos);
  }

  for (int i = 0; i < VAS_MULTIPLY_SUBPRODUCTS; i++) {
    if (localResult[i]) free(localResult[i]);
  }
  if (localResult) free(localResult);

  strcpy(result, outputString);

  return 1;  // fix return later
}

void v10StringFirstStep(char* a, char* b, char** localResult, bool isAddition) {
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
      place(current, localResult, tempForItoa, j);
    } else if (AEnded) {
      current = (b[i] - '0');
      place(current, localResult, tempForItoa, j);
    } else if (BEnded) {
      current = (a[i] - '0');
      place(current, localResult, tempForItoa, j);
    }
    j++;
    i++;
  }
  if (tempForItoa) free(tempForItoa);
}

void v10StringSecondStepAdd(char** localResult) {
  int i = 0;
  char* tempForItoa = calloc(1024, sizeof(char));
  while (s21_strlen(localResult[i]) > 0) {
    if (atoi(localResult[i]) > 9) {
      if (localResult[i + 1][0] != '\0') {
        itoa(atoi(localResult[i + 1]) + 1, tempForItoa);
        strcpy(localResult[i + 1], tempForItoa);
      } else {
        localResult[i + 1][0] = '1';
      }
      minusTen(localResult[i]);
    }
    i++;
  }
  if (tempForItoa) free(tempForItoa);
}

void v10StringSecondStepSub(char** localResult) {
  int i = 0;
  char* tempForItoa = calloc(1024, sizeof(char));
  while (s21_strlen(localResult[i]) > 0) {
    if (atoi(localResult[i]) < 0) {
      if (s21_strlen(localResult[i + 1]) > 0) {
        itoa(atoi(localResult[i + 1]) - 1, tempForItoa);
        strcpy(localResult[i + 1], tempForItoa);
        itoa(10 + atoi(localResult[i]), tempForItoa);
        strcpy(localResult[i], tempForItoa);
      }
    }
    i++;
  }
  if (tempForItoa) free(tempForItoa);
}

// -----------------------------------
// DECIM MULTI:
// -----------------------------------
void decimMulti(char* a, char* b) {
  char*** subProducts = calloc(VAS_ATOMS_MAX, sizeof(char**));
  for (int i = 0; i < VAS_ATOMS_MAX; i++) {
    subProducts[i] = calloc(VAS_ATOMS_MAX, sizeof(char*));
    for (int j = 0; j < VAS_ATOMS_MAX; j++) {
      subProducts[i][j] = calloc(VAS_ATOM_SIZE, sizeof(char));
    }
  }
  // bool AEnded = false;
  // bool BEnded = false;
  // int curLineResult = -2147483640;
  char* tempForItoa = calloc(1024, sizeof(char));
  // bool whileBreak = false;
  int aLen = s21_strlen(a);
  int bLen = s21_strlen(b);

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
  // v10StringSecondStepSub(localResult);
  for (size_t i = 0; i < VAS_ATOMS_MAX; i++) {
    int resultSize = matrixSizeDetector(subProducts[i]);
    reverseCharMatrix(subProducts[i], resultSize);
    char outputString[1024] = {0};
    if (subProducts[i][0][0] != '\0') {
      matrixPrinter(subProducts[i]);
    }
    matrixToString(subProducts[i], outputString);
    // reAddZero(outputString, dotPos);
    // if (s21_strlen(outputString) > 0) {
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
  //     place(current, localResult, tempForItoa, j);
  //     printf("[%s]\n", get(localResult, j));
  //   } else if (AEnded) {
  //     current = (b[i] - '0');
  //     place(current, localResult, tempForItoa, j);
  //   } else if (BEnded) {
  //     current = (a[i] - '0');
  //     place(current, localResult, tempForItoa, j);
  //   }
  //   j++;
  //   i++;
  // }
  if (tempForItoa) free(tempForItoa);

  for (int i = 0; i < VAS_ATOMS_MAX; i++) {
    for (int j = 0; j < VAS_ATOMS_MAX; j++) {
      if (subProducts[i][j]) free(subProducts[i][j]);
    }
    if (subProducts[i]) free(subProducts[i]);
  }
  if (subProducts) free(subProducts);

  // int i = 0;
  // char* tempForItoa1 = calloc(1024, sizeof(char));
  // while (s21_strlen(get(localResult, i)) > 0) {
  //   if (atoi(localResult[i]) > 9) {
  //     if (localResult[i + 1][0] != '\0') {
  //       itoa(atoi(localResult[i + 1]) + 1, tempForItoa1);
  //       strcpy(localResult[i + 1], tempForItoa1);
  //     } else {
  //       localResult[i + 1][0] = '1';
  //     }
  //     minusTen(localResult[i]);
  //   }
  //   i++;
  // }
  // if (firstStr) free(firstStr);
}
// -----------------------------------
// DECIM MULTI END
// -----------------------------------

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

void minusTen(char* input) {
  input[0] = input[1];
  input[1] = '\0';
}

void matrixToString(char** input, char* output) {
  int i = 0;
  while (s21_strlen(input[i]) > 0) {
    strcat(output, input[i]);
    i++;
  }
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
  reverseString(src);
}

void reverseString(char* string) {
  char temp[VAS_REVERSE_MAXLINE];
  strcpy(temp, string);
  int length = s21_strlen(string);
  int i;
  for (i = 0; i < length; i++) string[i] = temp[length - i - 1];
  string[i] = '\0';
}

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

void reverseStringAlt(char* inputArr) {
  int i = 0;
  int n = s21_strlen(inputArr);
  while (inputArr[i] != '\0') {
    char tempChar = inputArr[i];
    inputArr[i] = inputArr[n - i - 1];
    inputArr[n - i - 1] = tempChar;
  }
}

int matrixSizeDetector(char** localResult) {
  int i = 0;
  while (s21_strlen(localResult[i]) > 0) {
    i++;
  }
  return i;
}

void matrixPrinter(char** localResult) {
  int i = 0;
  printf("out: [");
  do {
    if (i == 0) {
      printf("%2s", localResult[i]);
    } else {
      printf(",%2s", localResult[i]);
    }
    i++;
  } while (s21_strlen(localResult[i]) > 0);
  printf("]\n");
}

void deDot(char* a, char* b, int* dotPos) {
  char aCpy[VAS_INPUT_SIZE_MAX + 1] = {0};
  strcpy(aCpy, a);

  char bCpy[VAS_INPUT_SIZE_MAX + 1] = {0};
  strcpy(bCpy, b);
  // -----------------------WHAT IS NEEDED:------------------------
  // char a[TEST_VALUE_SIZE] = "        875.84758623475897345878784953789";
  // char b[TEST_VALUE_SIZE] = "46237647823.64762374000000000000000000000";
  // --------------------------------------------------------------
  bool AEnded = false;
  bool BEnded = false;
  bool ADotFound = false;
  bool BDotFound = false;
  bool ADotParsed = false;
  bool BDotParsed = false;
  char ALeftPart[VAS_INPUT_SIZE_MAX * 2] = {0};
  char BLeftPart[VAS_INPUT_SIZE_MAX * 2] = {0};
  char ARightPart[VAS_INPUT_SIZE_MAX + 1] = {0};
  char BRightPart[VAS_INPUT_SIZE_MAX + 1] = {0};
  int i = 0;
  int j = 0;
  bool whileBreak = false;
  while (whileBreak == false) {
    // printf("[%c][%c]\n", a[i], b[j]);
    // printf("\nDEBUG\n")
    if (AEnded == false || ADotFound == false) {
      if (a[i] == '\0') {
        AEnded = true;
      } else if (a[i] == '.') {
        ADotFound = true;
      }
    }

    if (BEnded == false || BDotFound == false) {
      if (b[j] == '\0') {
        BEnded = true;
      } else if (b[j] == '.') {
        BDotFound = true;
      }
    }

    if (ADotFound == true && ADotParsed == false) {
      // printf("\n1\n");
      strcpy(ALeftPart, strtok(aCpy, "."));
      strcpy(ARightPart, strtok(NULL, "."));
      ADotParsed = true;
    }

    if (BDotFound == true && BDotParsed == false) {
      // printf("\n2\n");
      strcpy(BLeftPart, strtok(bCpy, "."));
      strcpy(BRightPart, strtok(NULL, "."));
      BDotParsed = true;
    }

    if ((AEnded == true && BEnded == true) ||
        (AEnded == true && BDotParsed == true) ||
        (ADotParsed == true && BDotParsed == true) ||
        (ADotParsed == true && BEnded == true)) {
      whileBreak = true;
    }

    if (AEnded == false && ADotFound == false) i++;
    if (BEnded == false && BDotFound == false) j++;
  }

  *dotPos = addZerosAndReturnDotPos(ARightPart, BRightPart);

  if (ADotFound == false) {
    strcpy(ALeftPart, a);
    strcat(a, ARightPart);
    // no need to deDot
  } else {
    strcat(ALeftPart, ARightPart);
    strcpy(a, ALeftPart);
  }

  if (BDotFound == false) {
    strcpy(BLeftPart, b);
    strcat(b, BRightPart);
    // no need to deDot
  } else {
    strcat(BLeftPart, BRightPart);
    strcpy(b, BLeftPart);
  }
}

int addZerosAndReturnDotPos(char* a, char* b) {
  int dotPos = -1;
  int i = 0;
  size_t biggerStrlen =
      s21_strlen(a) > s21_strlen(b) ? s21_strlen(a) : s21_strlen(b);
  while (s21_strlen(a) < biggerStrlen || s21_strlen(b) < biggerStrlen) {
    if (s21_strlen(a) < s21_strlen(b)) {
      a[s21_strlen(a) + i] = '0';
    } else {
      b[s21_strlen(b) + i] = '0';
    }
  }
  dotPos = s21_strlen(a);
  return dotPos;
}

void reAddZero(char* input, int dotPos) {
  char tempStr[1024] = {0};
  strncat(tempStr, input, s21_strlen(input) - dotPos);
  strcat(tempStr, ".");
  strcat(tempStr, (char*)input + s21_strlen(input) - dotPos);
  strcpy(input, tempStr);
}

bool s21_match(const char* inputCharArr, char inputChar) {
  int match = false;
  int i = 0;
  while (inputCharArr[i] != '\0') {
    if (inputCharArr[i] == inputChar) {
      match = true;
    }
    i++;
  }
  return match;
}

size_t s21_strlen(const char* str) {
  size_t len = 0;
  while (*str != '\0') {
    str++;
    len++;
  }
  return (size_t)len;
}

// HOMYACHU:
// ------------

// char localResult[RES_SIZE][RAZR_SIZE] = {0}; // static initialization
// variant

// char** secStr = calloc(RES_SIZE, sizeof(char*));
// for (int i = 0; i < RES_SIZE; i++) {
//   localResult[i] = calloc(RAZRYADS_SIZE, sizeof(char));
// }

// if (secStr) free(secStr);

// printf("[%s]", inputArr[n - i - 1]);

// char tempForItoa[1024] = {0};

// printf("i:[%i]", i);
// printf("s:[%s]\n", localResult[i]);

// char* tempForItoa2 = calloc(1024, sizeof(char));

// localResult[i + 1][0] = '1';
// printf("[%s]", localResult[i + 1]);

// if (tempForItoa1) free(tempForItoa1);
// if (tempForItoa2) free(tempForItoa2);

// place(atoi(localResult[i]), localResult, tempForItoa1, i);

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

// void decimSubFirstStep(char* a, char* b, char** localResult) {
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
//       place(current, localResult, tempForItoa, j);
//     } else if (AEnded) {
//       current = (b[i] - '0');
//       place(current, localResult, tempForItoa, j);
//     } else if (BEnded) {
//       current = (a[i] - '0');
//       place(current, localResult, tempForItoa, j);
//     }
//     j++;
//     i++;
//   }
//   if (tempForItoa) free(tempForItoa);
// }

// printf("[%s]\n", get(localResult, j));

// printf("\nDEBUG\n");
// printf("[%c][%c]\n", a[i], b[i]);

// int s21_atoi(char* str) {
//   int length = s21strlen(str);
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

// itoa(atoi(localResult[i]) - 10, tempForItoa2, 10);
// strcpy(localResult[i], tempForItoa2);

// size_t s21strlen(const char* str) {
//   size_t len = 0;
//   while (*str != '\0') {
//     str++;
//     len++;
//   }
//   return (size_t)len;
// }
