#include "s21_decimal.h"

int main() {
  // char a[AB_SIZE] = "8326731548612467647832";
  // char b[AB_SIZE] = "8326731548612467647833";

  // char a[AB_SIZE] = "875.84758623475897345878784953789";
  // char b[AB_SIZE] = "46237647823.64762374";

  // здесть функция конвертации, вставить потом

  char a[MAX_INPUT_SIZE] = "42354366634.00014758623475897345878784953789";
  char b[MAX_INPUT_SIZE] = "0.000104623764782364762374";

  int dotPos = 0;

  // -------------------------------------------------------------------
  // DONT FORGET THAT FIRST STEP REQUIRES ADDITION/SUBTRACTION SPECIFIER
  // -------------------------------------------------------------------

  // RESULT ALLOC:
  // -------------
  // char result[RES_SIZE][RAZR_SIZE] = {0}; // static initialization variant
  char** result = calloc(MAX_MULT_SUBPRODUCTS, sizeof(char*));
  for (int i = 0; i < MAX_MULT_SUBPRODUCTS; i++) {
    result[i] = calloc(MULT_SUBPRODUCT_SIZE, sizeof(char));
  }

  printf("[%s]\n", a);
  printf("[%s]\n\n", b);
  deDot(a, b, &dotPos);
  printf("[%s]\n", a);
  printf("[%s]\n\n", b);

  // ADDITION:
  // ---------
  reverse(a);
  reverse(b);
  decimFirstStep(a, b, result, true);  // dont forget sub/add specifier
  decimSecondStepAdd(result);
  int resultSize = sizeDetector(result);
  reverseCharMatrix(result, resultSize);
  // printf("\nDEBUG\n");
  char outputString[1024] = {0};
  printer(result);
  matrixToString(result, outputString);
  reAddZero(outputString, dotPos);
  printf("%s\n", outputString);

  // SUBTRACTION:
  // ------------
  // reverse(a);
  // reverse(b);
  // decimFirstStep(a, b, result, false);  // dont forget sub/add specifier
  // decimSecondStepSub(result);
  // int resultSize = sizeDetector(result);
  // reverseCharMatrix(result, resultSize);
  // char outputString[1024] = {0};
  // printer(result);
  // matrixToString(result, outputString);
  // reAddZero(outputString, dotPos);
  // printf("%s", outputString);

  // MULTIPLICATION:
  // ---------------
  // reverse(a);
  // reverse(b);
  // decimMulti(a, b);
  // decimSecondStepSub(result);
  // int resultSize = sizeDetector(result);
  // reverseCharMatrix(result, resultSize);
  // char outputString[1024] = {0};
  // printer(result);
  // matrixToString(result, outputString);
  // reAddZero(outputString, dotPos);
  // printf("%s", outputString);

  // strcat(ALeftPart, ARightPart);
  // strcat(BLeftPart, BRightPart);
  // printf("[%s]\n", ALeftPart);
  // printf("[%s]\n\n", BLeftPart);
  // reAddZero(ALeftPart, dotPos);
  // reAddZero(BLeftPart, dotPos);
  // printf("[%s]\n", ALeftPart);
  // printf("[%s]\n\n", BLeftPart);

  // char a[AB_SIZE] = "9";
  // char b[AB_SIZE] = "9";
  // reverse(a);
  // reverse(b);
  // char result[RES_SIZE][RAZR_SIZE] = {0};

  // decimFirstStep(a, b, result, true);
  // decimSecondStepAdd(result);
  // int resultSize = sizeDetector(result);
  // reverseCharMatrix(result, resultSize);
  // printer(result);

  // strcpy(a, "87584758623475897345878784953789");
  // strcpy(b, "4623764782364762374");
  // reverse(a);
  // reverse(b);

  // char** resultSub = calloc(RES_SIZE, sizeof(char*));
  // for (int i = 0; i < RES_SIZE; i++) {
  //   resultSub[i] = calloc(RAZR_SIZE, sizeof(char));
  // }

  // decimFirstStep(a, b, resultSub, false);
  // printer(resultSub);
  // decimSecondStepSub(resultSub);
  // resultSize = sizeDetector(resultSub);
  // reverseCharMatrix(resultSub, resultSize);
  // printer(resultSub);

  // FREEING:
  // --------
  for (int i = 0; i < MAX_MULT_SUBPRODUCTS; i++) {
    if (result[i]) free(result[i]);
  }
  if (result) free(result);

  return 0;
}
