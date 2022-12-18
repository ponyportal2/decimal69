#include "kerFuncs.h"

void dottedToDegree(char *strDot, char *noDot, int *degree, int *sign) {
  *sign = 1;
  int j = 0;
  bool startPlus = false;
  for (int i = 0; i < (int)strlen(strDot); i++) {
    if (strDot[i] == '-') {
      i++;
      *sign = -1;
    }
    if (strDot[i] == '.') {
      startPlus = true;
      i++;
    }
    if (startPlus) {
      *degree = *degree + 1;
    }
    noDot[j] = strDot[i];
    j++;
  }
  noDot[j] = '\0';
}

void degreeToDotted(char *strDot, char *noDot, int degree, int sign) {
  int j = 0;
  bool lessZero = false;
  if (sign == -1) {
    strDot[0] = '-';
    j++;
  }
  if ((int)strlen(noDot) <= degree) {
    lessZero = true;
    strDot[j] = '0';
    strDot[j + 1] = '.';
    j = j + 2;
    degree--;
    while ((int)strlen(noDot) < degree) {
      strDot[j] = '0';
      j++;
      degree--;
    }
  }
  for (int i = 0; i < (int)strlen(noDot); i++, j++) {
    if (i == (int)strlen(noDot) - degree && !lessZero) {
      strDot[j] = '.';
      j++;
    }
    strDot[j] = noDot[i];
  }
  strDot[j] = '\0';
}

unsigned int signDegreeToNumber(int sign, int degree) {
  char binaryString[33];
  if (sign == 1) {
    binaryString[0] = '0';
  } else {
    binaryString[0] = '1';
  }
  for (int i = 1; i < 32; i++) {
    binaryString[i] = '0';
  }
  binaryString[32] = '\0';
  char binaryStack[40] = {'\0'};
  int i = 0;
  while (degree != 0) {
    if (degree % 2 == 1) {
      binaryStack[i] = '1';
    } else {
      binaryStack[i] = '0';
    }
    i++;
    degree = degree / 2;
  }
  for (int i = 15, j = 0; j < (int)strlen(binaryStack); i--, j++) {
    binaryString[i] = binaryStack[j];
  }
  return strtol(binaryString, NULL, 2);
}

void findDegreeSign(unsigned int decimalBit3, int *degree, int *sign) {
  if (decimalBit3 == 0) {
    *degree = 0;
    *sign = 1;
  } else {
    char binaryStack[40] = {'\0'};
    char binaryString[33];
    for (int i = 0; i < 32; i++) {
      binaryString[i] = '0';
    }
    binaryString[32] = '\0';
    int i = 0;
    while (decimalBit3 != 0) {
      if (decimalBit3 % 2 == 1) {
        binaryStack[i] = '1';
      } else {
        binaryStack[i] = '0';
      }
      i++;
      decimalBit3 = decimalBit3 / 2;
    }
    for (int j = 31, i = 0; i <= (int)strlen(binaryStack) - 1; i++, j--) {
      binaryString[j] = binaryStack[i];
    }
    if (binaryString[0] == '0') {
      *sign = 1;
    } else {
      *sign = -1;
    }
    int countToZero = 16;
    i = 31;
    while (countToZero != 0) {
      countToZero--;
      i--;
    }
    char degreeString[10] = {'\0'};
    int countDegree = 7;
    while (countDegree >= 0 && i != 0) {
      degreeString[countDegree] = binaryString[i];
      i--;
      countDegree--;
    }
    *degree = strtol(degreeString, NULL, 2);
  }
}

void binaryToDecimal(s21_decimal *decimal, char *binaryFull, int degree,
                     int sign) {
  int lengthBin = (int)strlen(binaryFull) - 1;
  for (int j = 0; j <= 2; j++) {
    char binaryPart[33];
    for (int i = 0; i < 32; i++) {
      binaryPart[i] = '0';
    }
    binaryPart[32] = '\0';
    int i = 31;
    while (lengthBin >= 0 && i >= 0) {
      binaryPart[i] = binaryFull[lengthBin];
      lengthBin--;
      i--;
    }
    (*decimal).bits[j] = strtol(binaryPart, NULL, 2);
  }
  char binaryString[33];
  if (sign == 1) {
    binaryString[0] = '0';
  } else {
    binaryString[0] = '1';
  }
  for (int i = 1; i < 32; i++) {
    binaryString[i] = '0';
  }
  binaryString[32] = '\0';
  char binaryStack[40] = {'\0'};
  int i = 0;
  while (degree != 0) {
    if (degree % 2 == 1) {
      binaryStack[i] = '1';
    } else {
      binaryStack[i] = '0';
    }
    i++;
    degree = degree / 2;
  }
  for (int i = 15, j = 0; j < (int)strlen(binaryStack); i--, j++) {
    binaryString[i] = binaryStack[j];
  }
  (*decimal).bits[3] = strtol(binaryString, NULL, 2);
}

void decimalToBinary(s21_decimal decimal, char *binaryFull) {
  for (int o = 2; o >= 0; o--) {
    // printf("%u\n", decimal.bits[o]);
    char binaryString[33];
    char binaryStack[45] = {'\0'};
    for (int i = 0; i < 32; i++) {
      binaryString[i] = '0';
    }
    binaryString[32] = '\0';
    int i = 0;
    while (decimal.bits[o] != 0) {
      if (decimal.bits[o] % 2 == 1) {
        binaryStack[i] = '1';
      } else {
        binaryStack[i] = '0';
      }
      i++;
      decimal.bits[o] = decimal.bits[o] / 2;
    }
    binaryStack[i] = '\0';
    i--;
    while (i >= 0 && binaryStack[i] == '0') {
      i--;
    }
    for (int j = 31, k = 0; k <= i; k++, j--) {
      binaryString[j] = binaryStack[k];
    }
    strcat(binaryFull, binaryString);
  }
  // printf("%s\n", binaryFull);
}

void binaryToString(char *binaryFull, char *decimalString) {
  int zeroCounter = 0;
  int numCounter = 0;
  while (binaryFull[0] != '\0') {
    int R = 0;
    char binaryStack[KER_SIZE] = "";
    for (int i = 0; i < (int)strlen(binaryFull); i++) {
      R = 2 * R + binaryFull[i] - '0';
      if (R >= 10) {
        binaryStack[i] = '1';
        R -= 10;
      } else {
        binaryStack[i] = '0';
      }
    }
    decimalString[numCounter] = R + 48;
    numCounter++;
    binaryStack[strlen(binaryFull) - zeroCounter] = '\0';
    int j = 0;
    while (binaryStack[j] == '0') {
      j++;
    }
    for (int i = 0, k = j; i < (int)strlen(binaryStack) - j; i++, k++) {
      binaryFull[i] = binaryStack[k];
    }
    binaryFull[strlen(binaryStack) - j] = '\0';
    zeroCounter = 0;
  }
  decimalString[numCounter] = '\0';
  char invert;
  for (int i = 0; i < (int)strlen(decimalString) / 2; i++) {
    invert = decimalString[i];
    decimalString[i] = decimalString[strlen(decimalString) - 1 - i];
    decimalString[strlen(decimalString) - 1 - i] = invert;
  }
}

bool stringToBinaryHelp(const char *decimalString, char *binaryString) {
  char binaryStack[KER_SIZE] = {'\0'};
  char decimalStr[KER_SIZE] = {0};
  strcpy(decimalStr, decimalString);
  int additive = 0;
  int next_additive;
  int k = 0;
  bool overflow = false;
  bool toBreak = true;
  if ((int)(decimalStr[strlen(decimalStr) - 1] - '0') % 2 == 1) {
    binaryStack[k] = '1';
  } else {
    binaryStack[k] = '0';
  }
  k++;
  while (toBreak) {
    additive = 0;
    int j = 0;
    while (decimalStr[j] == '0') {
      j++;
    }
    if (j == (int)strlen(decimalStr)) {
      toBreak = false;
    }
    while (decimalStr[j] != '\0') {
      if ((int)(decimalStr[j] - '0') % 2 == 1) {
        next_additive = 5;
      } else {
        next_additive = 0;
      }
      int newNum = ((int)(decimalStr[j] - '0')) / 2 + additive;
      decimalStr[j] = newNum + '0';
      additive = next_additive;
      j++;
    }
    if ((int)(decimalStr[strlen(decimalStr) - 1] - '0') % 2 == 1) {
      binaryStack[k] = '1';
    } else {
      binaryStack[k] = '0';
    }
    k++;
  }
  int i = (int)strlen(binaryStack) - 1;
  while (binaryStack[i] == '0') {
    i--;
  }
  for (int j = 0; i >= 0; i--, j++) {
    binaryString[j] = binaryStack[i];
    if (i == 0) {
      binaryString[j + 1] = '\0';
    }
  }
  if (strlen(binaryString) > 96) {
    overflow = true;
  }
  return overflow;
}

bool stringToBinary(const char *decimalString, char *binaryString,
                    int *degree) {
  stringToBinaryHelp(decimalString, binaryString);
  bool overflow = false;
  char rememberLast;
  char decimalNew[KER_SIZE] = {0};
  strcpy(decimalNew, decimalString);
  static bool needToRound = false;
  rememberLast = decimalNew[strlen(decimalNew) - 1];

  // printf("%d\n", *degree);
  if (strlen(binaryString) > 96 && *degree == 0) {
    overflow = true;
  } else if ((strlen(binaryString) > 96 && *degree > 0) ||
             (*degree > 28 && strlen(binaryString) > 1)) {
    decimalNew[strlen(decimalNew) - 1] = '\0';
    needToRound = true;
    *degree -= 1;
    for (int i = 0; i < (int)strlen(binaryString); i++) {
      binaryString[i] = '\0';
    }
    // printf("%d ", cycle);
    overflow = stringToBinary(decimalNew, binaryString, degree);
    // printf("d :%d %s\n", overflow, binaryString);
    // printf("%s\n", binaryString);
  }
  if (needToRound) {
    bankRound(rememberLast, binaryString, decimalNew, &overflow);
  }
  // printf("%s\n", binaryString);
  delZeros(binaryString, decimalNew, degree, &overflow);
  needToRound = false;
  // printf("%s\n", binaryString);
  return overflow;
}

void bankRound(char rememberLast, char *binaryString, char *decimalNew,
               bool *overflow) {
  //  printf("%s\n", decimalNew);

  if (rememberLast > '5' ||
      (rememberLast == '5' && decimalNew[strlen(decimalNew) - 1] % 2 == 1)) {
    int lastNumCounter = 1;
    while (decimalNew[strlen(decimalNew) - lastNumCounter] == '9') {
      decimalNew[strlen(decimalNew) - lastNumCounter] = '0';
      lastNumCounter++;
    }
    decimalNew[strlen(decimalNew) - lastNumCounter]++;
    if (decimalNew[0] == '0') {
      decimalNew[0] = '1';
      decimalNew[strlen(decimalNew) + 1] = '\0';
      decimalNew[strlen(decimalNew)] = '0';
    }
    for (int i = 0; i < (int)strlen(binaryString); i++) {
      binaryString[i] = '\0';
    }
    *overflow = stringToBinaryHelp(decimalNew, binaryString);
    // printf("%s\n", decimalNew);
  }
}

void delZeros(char *binaryString, char *decimalNew, int *degree,
              bool *overflow) {
  if (strlen(binaryString) < 97) {
    if (decimalNew[strlen(decimalNew) - 1] == '0' && *degree > 0) {
      while (decimalNew[strlen(decimalNew) - 1] == '0' && *degree > 0) {
        decimalNew[strlen(decimalNew) - 1] = '\0';
        *degree -= 1;
      }
      for (int i = 0; i < (int)strlen(binaryString); i++) {
        binaryString[i] = '\0';
      }
      *overflow = stringToBinaryHelp(decimalNew, binaryString);
    }
  }
}

int s21_from_int_to_decimal(int src, s21_decimal *decimal) {
  if (src < 0) {
    (*decimal).bits[3] = 2147483648;
  } else {
    (*decimal).bits[3] = 0;
  }
  (*decimal).bits[0] = abs(src);
  (*decimal).bits[1] = 0;
  (*decimal).bits[2] = 0;
  //   printf("%d\n", (*decimal).bits[0]);
  //  float asd = 1236556433.25241675;
  //  printf("%.20f\n", asd);
  return 0;
}

int s21_from_float_to_decimal(float src, s21_decimal *decimal) {
  int returnValue = 0;
  int sign = 0, degree = 0;
  int string = 0;
  long double zeroCount = 1;
  long double saveSrc = src;
  if (fabs(src) > 0 && fabs(src) < 1e-28) {
    returnValue = 1;
    (*decimal).bits[0] = 0;
    (*decimal).bits[1] = 0;
    (*decimal).bits[2] = 0;
    (*decimal).bits[3] = 0;
  } else if (src > 79228162514264337593543950335. ||
             src < -79228162514264337593543950335. || isinf(src) ||
             isinf(-src)) {
    returnValue = 1;
  } else if (src != 0) {
    if (saveSrc < 0) {
      saveSrc = saveSrc * (-1);
      sign = -1;
    } else {
      sign = 1;
    }
    int eightNum = 0;
    if ((int)saveSrc == 0) {
      while ((int)saveSrc == 0) {
        saveSrc = saveSrc * 10;
        degree++;
      }
      for (int i = 2; i <= 7 && degree <= 28; i++, degree++) {
        saveSrc = saveSrc * 10;
      }
      eightNum = (int)(saveSrc * 10) % 10;
      string = (int)saveSrc;
      if (eightNum >= 5) {
        string++;
      }
    } else if (saveSrc < 1000000) {
      while (saveSrc < 1000000) {
        saveSrc = saveSrc * 10;
        degree++;
      }
      eightNum = (int)(saveSrc * 10) % 10;
      string = (int)saveSrc;
      if (eightNum >= 5) {
        string++;
      }
    } else {
      while (saveSrc > 10000000) {
        saveSrc = saveSrc / 10;
        zeroCount *= 10;
      }
      eightNum = (int)(saveSrc * 10) % 10;
      string = (int)saveSrc;
      if (eightNum >= 5) {
        string++;
      }
    }
    char stringToDec[KER_SIZE];
    sprintf(stringToDec, "%d", string);
    // printf("%s\n", stringToDec);
    while (zeroCount != 1) {
      stringToDec[strlen(stringToDec) + 1] = '\0';
      stringToDec[strlen(stringToDec)] = '0';
      zeroCount /= 10;
    }
    char binaryString[KER_SIZE] = {'\0'};
    while (stringToDec[strlen(stringToDec) - 1] == '0') {
      stringToDec[strlen(stringToDec) - 1] = '\0';
      degree--;
    }
    //  printf("%s\n", stringToDec);
    stringToBinary(stringToDec, binaryString, &degree);
    binaryToDecimal(decimal, binaryString, degree, sign);
  } else {
    (*decimal).bits[0] = 0;
    (*decimal).bits[1] = 0;
    (*decimal).bits[2] = 0;
    (*decimal).bits[3] = 0;
  }

  //  printf("%u\n%u\n%u\n%u\n", (*decimal).bits[2], (*decimal).bits[1],
  //  (*decimal).bits[0], (*decimal).bits[3]);
  return returnValue;
}

int s21_from_decimal_to_int(s21_decimal decimal, int *dst) {
  int returnValue;
  char binaryFull[110] = {'\0'};
  char binaryPart[40] = {'\0'};
  char decimalString[35] = {'\0'};
  int sign = 0, degree = 0;
  decimalToBinary(decimal, binaryFull);
  binaryToString(binaryFull, decimalString);
  findDegreeSign(decimal.bits[3], &degree, &sign);
  while (degree > 0 && strlen(decimalString) != 0) {
    decimalString[strlen(decimalString) - 1] = '\0';
    degree--;
  }
  stringToBinary(decimalString, binaryPart, 0);
  if (strlen(binaryPart) > 31) {
    returnValue = 1;
  } else {
    *dst = sign * strtol(binaryPart, NULL, 2);
    returnValue = 0;
  }
  return returnValue;
}

int s21_from_decimal_to_float(s21_decimal decimal, float *dst) {
  int returnValue = 0;
  if ((void *)dst != NULL) {
    char binaryFull[110] = {'\0'};
    char decimalString[35] = {'\0'};
    int sign = 0, degree = 0;
    decimalToBinary(decimal, binaryFull);
    binaryToString(binaryFull, decimalString);
    findDegreeSign(decimal.bits[3], &degree, &sign);
    // printf("%s\n", decimalString);
    *dst = decimalString[0] - '0';
    double degreeCount = 10;
    long double result = decimalString[0] - '0';
    int leftPart = (int)strlen(decimalString) - 1 - degree;
    for (int i = 1; i < (int)strlen(decimalString); i++) {
      if (leftPart > 0) {
        result = result * 10 + decimalString[i] - '0';
        leftPart--;
      } else {
        result = result + (decimalString[i] - '0') / degreeCount;
        degreeCount *= 10;
      }
    }
    *dst = sign * (float)result;
  } else {
    returnValue = 1;
  }
  // printf("%e\n", *dst);
  return returnValue;
}

int s21_round(s21_decimal value, s21_decimal *result) {
  bool overflow = false;
  char binaryFull[110] = {'\0'};
  char decimalString[35] = {'\0'};
  int degree = 0, sign = 0;
  decimalToBinary(value, binaryFull);
  binaryToString(binaryFull, decimalString);
  findDegreeSign(value.bits[3], &degree, &sign);
  //  printf("%d\n", degree);
  int i = (int)strlen(decimalString) - 1;
  char rememberLast = '\0';
  // printf("%s\n", decimalString);
  while (degree != 0 && i >= 0) {
    rememberLast = decimalString[i];
    decimalString[i] = '\0';
    degree--;
    i--;
  }
  if (rememberLast >= '5') {
    while (decimalString[i] == '9') {
      decimalString[i] = '0';
      i--;
    }
    decimalString[i]++;
    if (decimalString[0] == '0') {
      decimalString[0] = '1';
      decimalString[strlen(decimalString) + 1] = '\0';
      decimalString[strlen(decimalString)] = '0';
    }
    if (i == -1 && degree == 0) {
      decimalString[0] = '1';
    } else if (degree > 0) {
      decimalString[0] = '0';
    }
  }
  degree = 0;
  // printf("%s\n", decimalString);
  char binaryString[110] = {'\0'};
  overflow = stringToBinary(decimalString, binaryString, &degree);
  //  printf("%s\n", binaryString);

  if (overflow == false) {
    binaryToDecimal(result, binaryString, degree, sign);
  }
  //   printf("%u\n%u\n%u\n%u\n", (*result).bits[2], (*result).bits[1],
  //   (*result).bits[0], (*result).bits[3]);
  return overflow;
}

int s21_floor(s21_decimal value, s21_decimal *result) {
  bool overflow = false;
  char binaryFull[110] = {'\0'};
  char decimalString[35] = {'\0'};
  int degree = 0, sign = 0;
  decimalToBinary(value, binaryFull);
  binaryToString(binaryFull, decimalString);
  findDegreeSign(value.bits[3], &degree, &sign);
  // printf("%d\n", degree);

  //   printf("%d\n", degree);
  int i = (int)strlen(decimalString) - 1;
  // char rememberLast = '\0';
  while (degree != 0 && i >= 0) {
    // rememberLast = decimalString[i];
    decimalString[i] = '\0';
    degree--;
    i--;
  }
  if (sign == -1) {
    while (decimalString[i] == '9') {
      decimalString[i] = '0';
      i--;
    }
    decimalString[i]++;
    if (decimalString[0] == '0') {
      decimalString[0] = '1';
      decimalString[strlen(decimalString) + 1] = '\0';
      decimalString[strlen(decimalString)] = '0';
    } else if (decimalString[0] == '\0') {
      decimalString[0] = '1';
      decimalString[1] = '\0';
      degree = 0;
    }
  } else if (degree != 0) {
    decimalString[0] = '0';
    decimalString[1] = '\0';
    degree = 0;
  }
  // printf("%s\n", decimalString);
  char binaryString[110] = {'\0'};
  overflow = stringToBinary(decimalString, binaryString, &degree);
  //  printf("%s\n", binaryString);
  if (overflow == false) {
    binaryToDecimal(result, binaryString, degree, sign);
  }

  //   printf("%u\n%u\n%u\n", (*result).bits[2], (*result).bits[1],
  //   (*result).bits[0]);
  return overflow;
}

int s21_truncate(s21_decimal value, s21_decimal *result) {
  bool overflow = false;
  char binaryFull[110] = {'\0'};
  char decimalString[35] = {'\0'};
  int degree = 0, sign = 0;
  decimalToBinary(value, binaryFull);
  binaryToString(binaryFull, decimalString);
  findDegreeSign(value.bits[3], &degree, &sign);
  //  printf("%d\n", degree);
  int i = (int)strlen(decimalString) - 1;
  //   printf("%s\n", decimalString);
  while (degree != 0 && i >= 0) {
    decimalString[i] = '\0';
    degree--;
    i--;
  }
  //  printf("%s\n", decimalString);
  char binaryString[110] = {'\0'};
  overflow = stringToBinary(decimalString, binaryString, &degree);
  //  printf("%s\n", binaryString);
  if (overflow == false) {
    binaryToDecimal(result, binaryString, degree, sign);
  }
  //  printf("%u\n%u\n%u\n", (*result).bits[2], (*result).bits[1],
  //  (*result).bits[0]);
  return overflow;
}

int s21_negate(s21_decimal value, s21_decimal *result) {
  char reverseString[33] = {'\0'};
  char oldString[33];
  for (int i = 0; i < 32; i++) {
    oldString[i] = '0';
  }
  oldString[32] = '\0';
  int i = 0;
  while (value.bits[3] != 0) {
    if (value.bits[3] % 2 == 1) {
      oldString[i] = '1';
    } else {
      oldString[i] = '0';
    }
    i++;
    value.bits[3] = value.bits[3] / 2;
  }
  for (int j = 31, k = 0; k <= 31; k++, j--) {
    reverseString[j] = oldString[k];
  }
  if (oldString[31] == '0') {
    reverseString[0] = '1';
  } else {
    reverseString[0] = '0';
  }
  reverseString[32] = '\0';
  (*result).bits[0] = value.bits[0];
  (*result).bits[1] = value.bits[1];
  (*result).bits[2] = value.bits[2];
  (*result).bits[3] = strtol(reverseString, NULL, 2);
  // printf("%s\n", reverseString);
  //  printf("%ld\n", strtol(reverseString, NULL, 2));
  return 0;
}

int s21_is_less(s21_decimal first, s21_decimal second) {
  int returnValue = 0;
  if (convertForCompare(first, second) == 2) {
    returnValue = 1;
  }
  return returnValue;
}

int s21_is_less_or_equal(s21_decimal first, s21_decimal second) {
  int returnValue = 0;
  if (convertForCompare(first, second) != 1) {
    returnValue = 1;
  }
  return returnValue;
}

int s21_is_greater(s21_decimal first, s21_decimal second) {
  int returnValue = 0;
  if (convertForCompare(first, second) == 1) {
    returnValue = 1;
  }
  return returnValue;
}

int s21_is_greater_or_equal(s21_decimal first, s21_decimal second) {
  int returnValue = 0;
  if (convertForCompare(first, second) != 2) {
    returnValue = 1;
  }
  return returnValue;
}

int s21_is_equal(s21_decimal first, s21_decimal second) {
  int returnValue = 0;
  if (convertForCompare(first, second) == 0) {
    returnValue = 1;
  }
  return returnValue;
}

int s21_is_not_equal(s21_decimal first, s21_decimal second) {
  int returnValue = 0;
  if (convertForCompare(first, second) != 0) {
    returnValue = 1;
  }
  return returnValue;
}

int convertForCompare(s21_decimal first, s21_decimal second) {
  char binaryFirst[KER_SIZE] = {'\0'};
  char decimalFirst[KER_SIZE] = {'\0'};
  int degreeFirst = 0, signFirst = 0;
  decimalToBinary(first, binaryFirst);
  binaryToString(binaryFirst, decimalFirst);
  findDegreeSign(first.bits[3], &degreeFirst, &signFirst);

  char binarySecond[KER_SIZE] = {'\0'};
  char decimalSecond[KER_SIZE] = {'\0'};
  int degreeSecond = 0, signSecond = 0;
  decimalToBinary(second, binarySecond);
  binaryToString(binarySecond, decimalSecond);
  findDegreeSign(second.bits[3], &degreeSecond, &signSecond);

  return compareString(decimalFirst, decimalSecond, degreeFirst, signFirst,
                       degreeSecond, signSecond);
}

int compareString(const char *firstString, const char *secondString,
                  int firstDegree, int firstSign, int secondDegree,
                  int secondSign) {
  char firstCopy[KER_SIZE] = {'\0'};
  char secondCopy[KER_SIZE] = {'\0'};
  strcpy(firstCopy, firstString);
  strcpy(secondCopy, secondString);
  int returnValue = 0;
  // printf("%s\n%s\n", firstCopy, secondCopy);
  //   printf("%lu %lu\n", strlen(firstCopy), strlen(secondCopy));
  if (firstSign > secondSign) {
    returnValue = 1;
  } else if (firstSign < secondSign) {
    returnValue = 2;
  } else {
    toOneDegree(firstCopy, secondCopy, firstDegree, secondDegree);
    // printf("%s\n%s\n", firstCopy, secondCopy);
    if (strlen(secondCopy) > strlen(firstCopy)) {
      returnValue = 2;
    } else if (strlen(secondCopy) < strlen(firstCopy)) {
      returnValue = 1;
    } else {
      int i = 0;
      while (returnValue == 0 && i < (int)strlen(secondCopy)) {
        if (firstCopy[i] > secondCopy[i]) {
          returnValue = 1;
        } else if (firstCopy[i] < secondCopy[i]) {
          returnValue = 2;
        }
        i++;
      }
    }
  }
  if (returnValue == 1 && firstSign == -1 && secondSign == -1) {
    returnValue = 2;
  } else if (returnValue == 2 && firstSign == -1 && secondSign == -1) {
    returnValue = 1;
  }
  return returnValue;
}

void toOneDegree(char *firstString, char *secondString, int firstDegree,
                 int secondDegree) {
  char addZero[2] = {"0\0"};
  if (firstDegree > secondDegree) {
    for (int i = 0; i < firstDegree - secondDegree; i++) {
      strcat(secondString, addZero);
    }
  } else if (firstDegree < secondDegree) {
    for (int i = 0; i < secondDegree - firstDegree; i++) {
      strcat(firstString, addZero);
    }
  }
}

void subString(const char *firstString, const char *secondString,
               int firstDegree, int secondDegree, char *resultString) {
  char firstCopy[KER_SIZE] = {'\0'};
  char secondCopy[KER_SIZE] = {'\0'};
  strcpy(firstCopy, firstString);
  strcpy(secondCopy, secondString);
  toOneDegree(firstCopy, secondCopy, firstDegree, secondDegree);
  int j = (int)strlen(firstCopy) - 1;
  int k = 0;
  for (int i = (int)strlen(secondCopy) - 1; i >= 0; i--, j--, k++) {
    if (firstCopy[j] >= secondCopy[i]) {
      firstCopy[j] = firstCopy[j] - secondCopy[i] + '0';
    } else {
      firstCopy[j] = (firstCopy[j] + '9' + 1 - '0') - secondCopy[i] + '0';
      if (firstCopy[j - 1] != '0') {
        firstCopy[j - 1]--;
      } else {
        int zeroCounter = 1;
        while (firstCopy[j - zeroCounter] == '0') {
          firstCopy[j - zeroCounter] = '9';
          zeroCounter++;
        }
        firstCopy[j - zeroCounter]--;
      }
    }
  }

  strcat(resultString, firstCopy);
  int i = 0;
  while (resultString[i] == '0') {
    i++;
  }
  for (int j = 0; j <= (int)strlen(resultString); j++, i++) {
    resultString[j] = resultString[i];
    // resultString[strlen(resultString) - 1] = '\0';
  }
  if (strlen(resultString) == 0) {
    resultString[0] = '0';
    resultString[1] = '\0';
  }
  // printf("%lu\n", strlen(resultString));
  // printf("%s\n", resultString);
}

int divString(const char *firstString, const char *secondString,
              int firstDegree, int secondDegree, char *resultString) {
  char firstCopy[KER_SIZE] = {'\0'};
  char secondCopy[KER_SIZE] = {'\0'};
  int degree = 0;
  strcpy(firstCopy, firstString);
  strcpy(secondCopy, secondString);
  toOneDegree(firstCopy, secondCopy, firstDegree, secondDegree);
  char stringToSub[KER_SIZE] = {'\0'};
  int counterSub = 1, counterFirst = 1;
  stringToSub[0] = firstCopy[0];
  stringToSub[1] = '\0';
  resultString[0] = '0';
  int resultCounter = 0;
  bool start = false;

  while (degree != 29 &&
         (stringToSub[0] != '0' || firstCopy[counterFirst] != '\0')) {
    resultString[resultCounter] = '0';
    while (compareString(stringToSub, secondCopy, 0, 1, 0, 1) == 2 &&
           (counterFirst < (int)strlen(firstCopy) || stringToSub[0] != '0') &&
           degree != 29) {
      if (firstCopy[counterFirst] != '\0') {
        stringToSub[counterSub] = firstCopy[counterFirst];
        stringToSub[counterSub + 1] = '\0';
        counterFirst++;
        if (stringToSub[0] != '0') {
          counterSub++;
        }
        if (start) {
          resultCounter++;
          resultString[resultCounter] = '0';
        }
      } else {
        stringToSub[counterSub] = '0';
        stringToSub[counterSub + 1] = '\0';
        if (stringToSub[0] != '0') {
          counterSub++;
        }
        degree++;
        if (start) {
          resultCounter++;
          resultString[resultCounter] = '0';
        }
      }
      start = true;
    }

    if (stringToSub[0] == '0') {
      // strcat(resultString, stringToSub);
      counterFirst++;

      //  resultCounter++;
      // printf("%s\n", stringToSub);

    } else {
      while (compareString(stringToSub, secondCopy, 0, 1, 0, 1) == 1 ||
             compareString(stringToSub, secondCopy, 0, 1, 0, 1) == 0) {
        char result[KER_SIZE] = {'\0'};
        subString(stringToSub, secondCopy, 0, 0, result);
        strcpy(stringToSub, result);
        resultString[resultCounter]++;
      }
    }
    resultCounter++;
    if (stringToSub[0] != '0') {
      counterSub = (int)strlen(stringToSub);
    } else {
      counterSub = 0;
    }
    start = false;
  }
  // printf("%s\n", stringToSub);
  resultString[resultCounter] = '\0';
  int zeroCounter = 0;
  while (resultString[zeroCounter] == '0') {
    zeroCounter++;
  }
  for (int i = 0; i < (int)strlen(resultString); i++) {
    resultString[i] = resultString[i + zeroCounter];
  }
  resultString[resultCounter - zeroCounter] = '\0';
  return degree;
  //  printf("%d\n", degree);
}

int s21_div(s21_decimal first, s21_decimal second, s21_decimal *result) {
  int returnValue = 0;
  char binaryFirst[KER_SIZE] = {'\0'};
  char decimalFirst[KER_SIZE] = {'\0'};
  int degreeFirst = 0, signFirst = 0;
  decimalToBinary(first, binaryFirst);
  binaryToString(binaryFirst, decimalFirst);
  findDegreeSign(first.bits[3], &degreeFirst, &signFirst);

  char binarySecond[KER_SIZE] = {'\0'};
  char decimalSecond[KER_SIZE] = {'\0'};
  int degreeSecond = 0, signSecond = 0;
  decimalToBinary(second, binarySecond);
  binaryToString(binarySecond, decimalSecond);
  findDegreeSign(second.bits[3], &degreeSecond, &signSecond);

  if (decimalSecond[0] == '0') {
    returnValue = 3;
  } else {
    char resultString[KER_SIZE] = {'\0'};
    char binaryString[KER_SIZE] = {'\0'};
    // printf("%s %d\n", decimalFirst, degreeFirst);
    //  printf("%s %d\n", decimalSecond, degreeSecond);
    int degree = divString(decimalFirst, decimalSecond, degreeFirst,
                           degreeSecond, resultString);
    //   printf("%s\n", resultString);
    if (decimalFirst[0] == '0' && decimalSecond[0] != '0') {
      if (degreeSecond == 0 && degreeFirst != 0) {
        degree = degreeFirst;
      } else if (degreeFirst < degreeSecond) {
        degree = 0;
      } else {
        degree = degreeSecond;
      }
    }

    // s  printf("pudge\n");

    int error = stringToBinary(resultString, binaryString, &degree);
    // printf("%s %d\n", resultString, degree);
    //  printf("%s\n", binaryString);
    if (error == 1 && degree < 29) {
      returnValue = 1;
    } else if (degree > 28) {
      binaryToDecimal(result, binaryString, 0, signFirst * signSecond);
      returnValue = 2;
    } else {
      binaryToDecimal(result, binaryString, degree, signFirst * signSecond);
    }
  }
  return returnValue;
}

int modString(const char *firstString, const char *secondString,
              int firstDegree, int secondDegree, char *resultString) {
  char firstCopy[KER_SIZE] = {'\0'};
  char secondCopy[KER_SIZE] = {'\0'};
  strcpy(firstCopy, firstString);
  strcpy(secondCopy, secondString);
  toOneDegree(firstCopy, secondCopy, firstDegree, secondDegree);
  char stringToSub[KER_SIZE] = {'\0'};
  int counterSub = 1, counterFirst = 1;
  stringToSub[0] = firstCopy[0];
  stringToSub[1] = '\0';
  int degree = 0;
  while (counterFirst < (int)strlen(firstCopy)) {
    while (compareString(stringToSub, secondCopy, 0, 1, 0, 1) == 2 &&
           counterFirst < (int)strlen(firstCopy)) {
      if (firstCopy[counterFirst] != '\0') {
        stringToSub[counterSub] = firstCopy[counterFirst];
        stringToSub[counterSub + 1] = '\0';
        counterFirst++;
        degree++;
        if (stringToSub[0] != '0') {
          counterSub++;
        }
      }
    }

    if (stringToSub[0] == '0') {
      // strcat(resultString, stringToSub);
      counterFirst++;
    } else {
      while (compareString(stringToSub, secondCopy, 0, 1, 0, 1) == 1 ||
             compareString(stringToSub, secondCopy, 0, 1, 0, 1) == 0) {
        char result[KER_SIZE] = {'\0'};
        subString(stringToSub, secondCopy, 0, 0, result);
        strcpy(stringToSub, result);
      }
    }
    if (stringToSub[0] != '0') {
      counterSub = (int)strlen(stringToSub);
    } else {
      counterSub = 0;
    }
  }
  //  printf("%s\n", stringToSub);
  strcpy(resultString, stringToSub);
  // printf("%s\n", stringToSub);
  // printf("%d\n", degree);
  return degree;
}

int s21_mod(s21_decimal first, s21_decimal second, s21_decimal *result) {
  int returnValue = 0;
  char binaryFirst[KER_SIZE] = {'\0'};
  char decimalFirst[KER_SIZE] = {'\0'};
  int degreeFirst = 0, signFirst = 0;
  decimalToBinary(first, binaryFirst);
  binaryToString(binaryFirst, decimalFirst);
  findDegreeSign(first.bits[3], &degreeFirst, &signFirst);

  char binarySecond[KER_SIZE] = {'\0'};
  char decimalSecond[KER_SIZE] = {'\0'};
  int degreeSecond = 0, signSecond = 0;
  decimalToBinary(second, binarySecond);
  binaryToString(binarySecond, decimalSecond);
  findDegreeSign(second.bits[3], &degreeSecond, &signSecond);

  if (decimalFirst[0] == '0' && decimalSecond[0] != '0') {
    (*result).bits[0] = 0;
    (*result).bits[1] = 0;
    (*result).bits[2] = 0;
    (*result).bits[3] = signDegreeToNumber(signFirst, degreeFirst);
  } else if (decimalSecond[0] == '0') {
    returnValue = 3;
  } else {
    char resultString[KER_SIZE] = {'\0'};
    char binaryString[KER_SIZE] = {'\0'};
    // printf("%s %d\n", decimalFirst, degreeFirst);
    //  printf("%s %d\n", decimalSecond, degreeSecond);
    int degree = modString(decimalFirst, decimalSecond, degreeFirst,
                           degreeSecond, resultString);
    //   printf("%s\n", resultString);
    if (degreeFirst > degreeSecond) {
      degree = degreeFirst;
    } else {
      degree = degreeSecond;
    }

    int error = stringToBinary(resultString, binaryString, &degree);
    //  printf("%s %d\n", resultString, degree);
    //  printf("%s\n", binaryString);
    if (error == 1 && degree < 29) {
      returnValue = 1;
    } else if (degree > 28) {
      returnValue = 2;
    } else {
      binaryToDecimal(result, binaryString, degree, signFirst);
    }
  }
  return returnValue;
}
/*
void DecimalToString(s21_decimal decimal, char *decimalString) {
    for (int i = 2; i >=0; i--) {
        char decimalPart[12] = {'\0'};
        sprintf(decimalPart, "%d", decimal.bits[i]);
        strcat(decimalString, decimalPart);
    }
}



void stringToDecimal(char *string, s21_decimal *decimal, int degree, int sign) {
    for (int j = 0; j <= 2; j++) {
    char partString[12] = {'\0'};
    char binaryString[110] = {'\0'};
    int cutString = 0;
    int maxLength = 9;
    partString[10] = '\0';
    if (maxLength > strlen(string)) {
        maxLength = strlen(string) - 1;
    }
    for (int i = strlen(string) - 1; i >= 0 && maxLength >= 0; i--,
maxLength--){ partString[maxLength] = string[i]; cutString++;
    }
    if (DecimalOverflowCheck(partString, binaryString, KER_MAX_LENGTH_PART)) {
        partString[9] = '\0';
        maxLength = cutString - 2;
        cutString = 0;
        for (int i = strlen(string) - 1; maxLength >= 0; i--, maxLength--){
            partString[maxLength] = string[i];
            cutString++;
        }
    }
    string[strlen(string) - cutString] = '\0';
    (*decimal).bits[j] = strtol(partString, NULL, 10);
    printf("%u\n", (*decimal).bits[j]);
    }
    char binaryString[33];
    if (sign == 1) {
        binaryString[0] = '0';
    } else {
        binaryString[0] = '1';
    }
    for (int i = 1; i < 32; i++) {
        binaryString[i] = '0';
    }
    binaryString[32] = '\0';
    char binaryStack[40] = {'\0'};
    int i = 0;
    while (degree != 0) {
        if (degree % 2 == 1) {
            binaryStack[i] = '1';
        } else {
            binaryStack[i] = '0';
        }
        i++;
        degree = degree / 2;
    }
    printf("%s\n", binaryStack);
    for (int i = 15, j = 0; j < strlen(binaryStack); i--, j++) {
        binaryString[i] = binaryStack[j];
    }
    (*decimal).bits[3] = strtol(binaryString, NULL, 2);
    printf("%u\n", (*decimal).bits[3]);
}

*/
