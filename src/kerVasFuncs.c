#include "kerVasFuncs.h"

#define KERVAS_APPEND_MINUS_SIZE 1024

s21_decimal dottedToDecimal(char *a) {
  int tempDegree = 0;
  int tempSign = 0;

  char resultWithoutDot[KER_DTD_SIZE] = {0};
  dottedToDegree(a, resultWithoutDot, &tempDegree, &tempSign);

  char binaryResult[KER_DTD_SIZE] = {0};
  stringToBinary(resultWithoutDot, binaryResult, &tempDegree);

  s21_decimal tempDecimal = {0};
  binaryToDecimal(&tempDecimal, binaryResult, tempDegree, tempSign);

  return tempDecimal;
}

void decimalToDotted(s21_decimal inputDecimal, char *outputDotted) {
  char binaryResultNew[KER_DTD_SIZE] = {0};
  int tempDegree = 0;
  int tempSign = 0;

  findDegreeSign(inputDecimal.bits[3], &tempDegree, &tempSign);

  decimalToBinary(inputDecimal, binaryResultNew);

  char stringTempBeforeFinal[KER_DTD_SIZE] = {0};
  binaryToString(binaryResultNew, stringTempBeforeFinal);

  char stringConvertedBackAndForth[KER_DTD_SIZE] = {0};
  degreeToDotted(stringConvertedBackAndForth, stringTempBeforeFinal, tempDegree,
                 tempSign);

  strcpy(outputDotted, stringConvertedBackAndForth);
}

bool isDottedNegative(const char *input) {
  bool returnValue = false;
  if (strlen(input) != 0) {
    if (input[0] == '-') {
      returnValue = true;
    }
  } else {
    printf("EMPTY STRING WHEN CHECKING FOR NEGATIVE!\n");
  }
  return returnValue;
}

void dottedAbs(char *input, char *dottedResult) {
  if (strlen(input) > 0) {
    if (input[0] == '-') {
      strcpy(dottedResult, (char *)input + 1);
    } else {
      strcpy(dottedResult, input);
    }
  } else {
    printf("EMPTY STRING WHEN DOING DOTTED ABS!\n");
  }
}

void appendMinusToDotted(char *input) {
  char temp[KERVAS_APPEND_MINUS_SIZE] = {0};
  if (strlen(input) != 0) {
    strcat(temp, "-");
    strcat(temp, input);
    strcpy(input, temp);
  } else {
    printf("EMPTY STRING WHEN ADDING MINUS!\n");
  }
}

bool dottedOnTheLeftIsLess(char *first, char *second) {
  bool isLess = false;

  s21_decimal firstDec = dottedToDecimal(first);
  s21_decimal secondDec = dottedToDecimal(second);

  if (s21_is_less(firstDec, secondDec)) {
    isLess = true;
  }
  return isLess;
}

bool dottedOnTheLeftIsGreater(char *first, char *second) {
  bool isGreater = false;

  s21_decimal firstDec = dottedToDecimal(first);
  s21_decimal secondDec = dottedToDecimal(second);

  if (s21_is_greater(firstDec, secondDec)) {
    isGreater = true;
  }
  return isGreater;
}
