#include "s21_decimal.h"
#define TEST_VALUE_SIZE 1024

int main() {
  printf("--------------------------------\n");
  printf("VASJAN MAIN:\n");
  printf("--------------------------------\n");
  // -----------
  // 10ADIITION:
  // -----------
  char mainResult[1024] = {0};
  char* a = "4324234";
  // printf("%p\n", a);
  char* b = "326731548612467647833.423423";
  // char* a = "875.84758623475897345878784953789";
  // char* b = "46237647823.64762374";
  s21_add_positive_10String(a, b, mainResult);
  printf("%s\n", mainResult);
  a = "875.84758623475897345878784953789";
  // printf("%p\n", a);
  b = "46237647823.64762374";
  s21_add_positive_10String(a, b, mainResult);
  printf("%s\n", mainResult);
  a = "326731548612467647833.423423";
  // printf("%p\n", a);
  b = "4324234";
  printf("--------------------------------\n");
  // --------------
  // 10SUBTRACTION:
  // --------------
  // char* a = "875.84758623475897345878784953789";
  // char* b = "46237647823.64762374";
  s21_sub_positive_10String(a, b, mainResult);
  printf("%s\n", mainResult);
  a = "46237647823.64762374";
  // printf("%p\n", a);
  b = "875.84758623475897345878784953789";
  s21_sub_positive_10String(a, b, mainResult);
  printf("%s\n", mainResult);
  printf("--------------------------------\n");
  // --------------
  // s21_add:
  // --------------
  a = "-875.64762374";
  b = "-875.84758623475897345878784953789";
  s21_decimal tempDecimal_add = dottedToDecimal(a);
  s21_decimal tempDecimal_add2 = dottedToDecimal(b);
  char temp[1024] = {0};
  decimalToDotted(tempDecimal_add2, temp);
  // printf("b:[%s]\n", temp);

  s21_decimal result_add = {0};
  char result_add_str[1024] = {0};

  s21_add(tempDecimal_add, tempDecimal_add2, &result_add);
  decimalToDotted(result_add, result_add_str);
  printf("ADD RESULT:[%s] sometimes results in 0, maybe error\n",
         result_add_str);
  printf("--------------------------------\n");
  // --------------
  // s21_sub:
  // --------------
  a = "-875.44762374";
  b = "-875.84758623475897345878784953789";
  s21_decimal tempDecimal_sub = dottedToDecimal(a);
  s21_decimal tempDecimal_sub2 = dottedToDecimal(b);
  decimalToDotted(tempDecimal_sub2, temp);
  // printf("b:[%s]\n", temp);

  s21_decimal result_sub = {0};
  char result_sub_str[1024] = {0};
  s21_sub(tempDecimal_sub, tempDecimal_sub2, &result_sub);
  decimalToDotted(result_sub, result_sub_str);
  printf("SUB RESULT:[%s] sometimes results in 0, maybe error; UNFINISHED\n",
         result_sub_str);
  printf("--------------------------------\n");
  // ---------------
  // BACK AND FORTH:
  // ---------------
  a = "-46237647823.64762374";
  // printf("%p\n", a);
  printf("Converted back and forth:\n[%s]\n", a);

  s21_decimal tempDecimal = dottedToDecimal(a);

  char stringConvertedBackAndForth[1024] = {0};
  decimalToDotted(tempDecimal, stringConvertedBackAndForth);

  // char binaryResultNew[1024] = {0};
  // decimalToBinary(tempDecimal, binaryResultNew);
  // char stringTempBeforeFinal[1024] = {0};
  // binaryToString(binaryResultNew, stringTempBeforeFinal);
  // char stringConvertedBackAndForth[1024] = {0};
  // degreeToDotted(stringConvertedBackAndForth, stringTempBeforeFinal,
  // tempDegree,
  //                tempSign);

  printf("[%s]\n", stringConvertedBackAndForth);

  printf("--------------------------------\n");

  // ----------------------
  // KERENHOR MAIN STARTED:
  // ----------------------
  printf("--------------------------------\n");
  printf("KERENHOR MAIN:\n");
  printf("--------------------------------\n");
  // s21_decimal decimal, intCheck;
  // char binaryFull[KER_SIZE] = {'\0'};
  //  binaryFull[97] = '\0';
  // char decimalString[KER_SIZE] = {'\0'};

  // float dst = 0;

  // decimal.bits[0] = 2122534536;
  // decimal.bits[1] = 15676;
  // decimal.bits[2] = 123;
  // decimal.bits[3] = 2294933502;
  // findDegreeSign(decimal.bits[3], &degree, &sign);
  // DecimalToString(decimal, decimalString);
  // decimalToBinary(decimal, binaryFull);
  // binaryToString(binaryFull, decimalString);
  //  binaryToDecimal(&decimal, binaryFull, 28, 1);
  //   char decimalStr[35] = {0};
  // stringToBinary("772281625142643375935439999991", binaryFull, &degree);
  //  printf("%d\n", degree);
  // printf("%s\n", binaryFull);
  // s21_from_int_to_decimal(-42134, &intCheck);
  // s21_from_decimal_to_float(decimal, &dst);
  // s21_negate(decimal, &intCheck);
  // 655360
  // int degree = 32, sign = -1;
  /*
  unsigned int degreeSign = signDegreeToNumber(sign, degree);
    s21_decimal x = {{95008, 0, 0, degreeSign}};
    printf("%u\n", degreeSign);

    s21_decimal z = {{0, 0, 0, 0}};
    s21_round(x, &z);
    char res1[1000], res2[1000] = "950 0 0 2147483648";
    snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
             z.bits[2], z.bits[3]);
    printf("%s\n%s\n", res1, res2);
    */
  /*/
  int degree = 0, sign = 1;
  unsigned int degreeSign = signDegreeToNumber(sign, degree);
  s21_decimal first = {{100, 0, 0, 0}};
  s21_decimal second = {{1, 0, 0, 1835008}};
  s21_decimal result = {{0, 0, 0, 0}};
  int check = s21_div(first, second, &result);
  printf("%d %u %u %u %u\n", check, result.bits[0], result.bits[1],
  result.bits[2], result.bits[3]);
  */
  int degree = 20, sign = 1;
  // unsigned int degreeSign = signDegreeToNumber(sign, degree);
  // s21_decimal src1, src2, original, result;
  /*
  s21_decimal x = {{91, 0, 0, degreeSign}};
  s21_decimal y = {{5, 0, 0, 0}};
  s21_decimal z = {{0, 0, 0, 0}};

  int n1 = 0;
  n1 = s21_mod(x, y, &z);
  char res1[1000], res2[1000] = "0 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
    printf("%s\n%s\n", res1, res2);
    printf("%d 0\n", n1);
*/

  // src1.bits[0] = 379470760;
  // src1.bits[1] = 300332253;
  // src1.bits[2] = 187904819;
  // src1.bits[3] = 0;

  // src2.bits[0] = 11;
  // src2.bits[1] = 0;
  // src2.bits[2] = 0;
  // src2.bits[3] = 1835008;
  // int res = s21_mod(src1, src2, &result);
  // original.bits[0] = 6;
  // original.bits[1] = 0;
  // original.bits[2] = 0;
  // original.bits[3] = 1835008;
  // printf("%u %u %u %u\n", result.bits[3], result.bits[2], result.bits[1],
  // result.bits[0]);
  // printf("%u %u %u %u\n", original.bits[3], original.bits[2],
  // original.bits[1], original.bits[0]);

  // printf("%d 2\n", res);
  char strDot[KER_SIZE] = {"-24345.5456455"};
  char noDot[KER_SIZE] = {'\0'};
  printf("%s\n", strDot);
  dottedToDegree(strDot, noDot, &degree, &sign);
  printf("%s\n", noDot);
  // modString("1111", "31", 2, 1, decimalString);
  // printf("%d\n", signDegreeToNumber(1, 7));
  // printf("%d", s21_is_less(first, second));
  // char resultString[KER_SIZE] = {'\0'};
  // subString("11111", "112", 0, 0, resultString);
  // divString("0", "2", 0, 0, resultString);
  // printf("%s\n",resultString);
  //  printf("%d 1", err);
  // s21_from_float_to_decimal(78228169514264337593543950334.123446789,
  // &intCheck); strcpy(decimalStr, "456564566856754");
  // stringToDecimal(decimalStr, &decimal, 28, -1);
  // DecimalToBinary(decimalString, binaryString, KER_MAX_LENGTH);

  // negate если задать нулевой децимал что выводит оригинал
  // если засунули в функцию степень больше 28 что будет
  // везде ли банковское округление использовать
  printf("--------------------------------\n");
  // ----------------------
  // KERENHOR MAIN ENDED
  // ----------------------
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

// char a[VAS_INPUT_SIZE_MAX] = "42354366634.00014758623475897345878784953789";
// char b[VAS_INPUT_SIZE_MAX] = "0.000104623764782364762374";

// int dotPos = 0;

// // -------------------------------------------------------------------
// // DONT FORGET THAT FIRST STEP REQUIRES ADDITION/SUBTRACTION SPECIFIER
// // -------------------------------------------------------------------

// // RESULT ALLOC:
// // -------------
// // char result[RES_SIZE][RAZR_SIZE] = {0}; // static initialization variant
// char** result = calloc(VAS_MULTIPLY_SUBPRODUCTS, sizeof(char*));
// for (int i = 0; i < VAS_MULTIPLY_SUBPRODUCTS; i++) {
//   result[i] = calloc(VAS_MULTIPLY_SUBPRODUCT_SIZE, sizeof(char));
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
// for (int i = 0; i < VAS_MULTIPLY_SUBPRODUCTS; i++) {
//   if (result[i]) free(result[i]);
// }
// if (result) free(result);

// return 0;
