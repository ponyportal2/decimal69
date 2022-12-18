#include "kerVasFuncs.h"

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
