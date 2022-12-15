#include "vConverters.h"
#include "vFuncs.h"
#define TEST_VALUE_SIZE 1024

int main() {
  char mainResult[1024] = {0};
  char* a = "4324234";
  char* b = "326731548612467647833.423423";

  // char* a = "875.84758623475897345878784953789";
  // char* b = "46237647823.64762374";

  s21_add_pos_10String(a, b, mainResult);
  printf("%s\n", mainResult);

  a = "875.84758623475897345878784953789";
  b = "46237647823.64762374";

  s21_add_pos_10String(a, b, mainResult);
  printf("%s\n", mainResult);

  a = "326731548612467647833.423423";
  b = "4324234";

  printf("--------------------------------\n");
  // char* a = "875.84758623475897345878784953789";
  // char* b = "46237647823.64762374";

  s21_sub_pos_10String(a, b, mainResult);
  printf("%s\n", mainResult);

  a = "46237647823.64762374";
  b = "875.84758623475897345878784953789";

  s21_sub_pos_10String(a, b, mainResult);
  printf("%s\n", mainResult);
}
// -----------------------
// HOMYAK:
// -----------------------

// // char a[AB_SIZE] = "8326731548612467647832";
// // char b[AB_SIZE] = "8326731548612467647833";

// // char a[AB_SIZE] = "875.84758623475897345878784953789";
// // char b[AB_SIZE] = "46237647823.64762374";

// // здесть функция конвертации, вставить потом

// printf("----------------------------------------------\n");

// char a[MAX_INPUT_SIZE] = "42354366634.00014758623475897345878784953789";
// char b[MAX_INPUT_SIZE] = "0.000104623764782364762374";

// int dotPos = 0;

// // -------------------------------------------------------------------
// // DONT FORGET THAT FIRST STEP REQUIRES ADDITION/SUBTRACTION SPECIFIER
// // -------------------------------------------------------------------

// // RESULT ALLOC:
// // -------------
// // char result[RES_SIZE][RAZR_SIZE] = {0}; // static initialization variant
// char** result = calloc(MAX_MULT_SUBPRODUCTS, sizeof(char*));
// for (int i = 0; i < MAX_MULT_SUBPRODUCTS; i++) {
//   result[i] = calloc(MULT_SUBPRODUCT_SIZE, sizeof(char));
// }

// printf("[%s]\n", a);
// printf("[%s]\n\n", b);
// deDot(a, b, &dotPos);
// printf("[%s]\n", a);
// printf("[%s]\n\n", b);

// // ADDITION:
// // ---------
// reverseString(a);
// reverseString(b);
// v10StringFirstStep(a, b, result, true);  // dont forget sub/add specifier
// v10StringSecondStepAdd(result);
// int resultSize = matrixSizeDetector(result);
// reverseCharMatrix(result, resultSize);
// // printf("\nDEBUG\n");
// char outputString[1024] = {0};
// // matrixPrinter(result);
// matrixToString(result, outputString);
// reAddZero(outputString, dotPos);
// printf("%s\n", outputString);
// printf("______________________________________________\n");

// // SUBTRACTION:
// // ------------
// // reverse(a);
// // reverse(b);
// // v10StringFirstStep(a, b, result, false);  // dont forget sub/add
// // specifier v10StringSecondStepSub(result); int resultSize =
// // sizeDetector(result); reverseCharMatrix(result, resultSize); char
// // outputString[1024] = {0}; matrixPrinter(result); matrixToString(result,
// // outputString); reAddZero(outputString, dotPos); printf("%s",
// outputString);

// // MULTIPLICATION:
// // ---------------
// // reverse(a);
// // reverse(b);
// // decimMulti(a, b);
// // v10StringSecondStepSub(result);
// // int resultSize = sizeDetector(result);
// // reverseCharMatrix(result, resultSize);
// // char outputString[1024] = {0};
// // matrixPrinter(result);
// // matrixToString(result, outputString);
// // reAddZero(outputString, dotPos);
// // printf("%s", outputString);

// // strcat(ALeftPart, ARightPart);
// // strcat(BLeftPart, BRightPart);
// // printf("[%s]\n", ALeftPart);
// // printf("[%s]\n\n", BLeftPart);
// // reAddZero(ALeftPart, dotPos);
// // reAddZero(BLeftPart, dotPos);
// // printf("[%s]\n", ALeftPart);
// // printf("[%s]\n\n", BLeftPart);

// // char a[AB_SIZE] = "9";
// // char b[AB_SIZE] = "9";
// // reverse(a);
// // reverse(b);
// // char result[RES_SIZE][RAZR_SIZE] = {0};

// // v10StringFirstStep(a, b, result, true);
// // v10StringSecondStepAdd(result);
// // int resultSize = sizeDetector(result);
// // reverseCharMatrix(result, resultSize);
// // matrixPrinter(result);

// // strcpy(a, "87584758623475897345878784953789");
// // strcpy(b, "4623764782364762374");
// // reverse(a);
// // reverse(b);

// // char** resultSub = calloc(RES_SIZE, sizeof(char*));
// // for (int i = 0; i < RES_SIZE; i++) {
// //   resultSub[i] = calloc(RAZR_SIZE, sizeof(char));
// // }

// // v10StringFirstStep(a, b, resultSub, false);
// // matrixPrinter(resultSub);
// // v10StringSecondStepSub(resultSub);
// // resultSize = sizeDetector(resultSub);
// // reverseCharMatrix(resultSub, resultSize);
// // matrixPrinter(resultSub);

// // FREEING:
// // --------
// for (int i = 0; i < MAX_MULT_SUBPRODUCTS; i++) {
//   if (result[i]) free(result[i]);
// }
// if (result) free(result);

// return 0;
