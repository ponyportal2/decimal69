#include "s21_decimal.h"
#define DEC_TEMP_VALUE_SIZE 1024

// --------
// S21_ADD:
// --------
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  char value_1_dotted[DEC_TEMP_VALUE_SIZE] = {0};
  char value_2_dotted[DEC_TEMP_VALUE_SIZE] = {0};
  char abs_value_1_dotted[DEC_TEMP_VALUE_SIZE] = {0};
  char abs_value_2_dotted[DEC_TEMP_VALUE_SIZE] = {0};
  char dotted_result[DEC_TEMP_VALUE_SIZE] = {0};
  decimalToDotted(value_1, value_1_dotted);
  decimalToDotted(value_2, value_2_dotted);

  bool value_1_isNegative = false;
  bool value_2_isNegative = false;

  if (isDottedNegative(value_1_dotted)) value_1_isNegative = true;
  if (isDottedNegative(value_2_dotted)) value_2_isNegative = true;

  dottedAbs(value_1_dotted, abs_value_1_dotted);
  dottedAbs(value_2_dotted, abs_value_2_dotted);

  // ↓ если оба числа отрицательные, то откладываем их, в конце добавляем минус:
  if (value_1_isNegative && value_2_isNegative) {
    s21_add_positive_10String(abs_value_1_dotted, abs_value_2_dotted,
                              dotted_result);
    // ---------------------------------------------------
    // ↓ если первое число отрицательное и меньше второго:
    // ↓ то из второго вычтем первое. конечное число без минуса.
  } else if (value_1_isNegative &&
             dottedOnTheLeftIsLess(abs_value_1_dotted, abs_value_2_dotted)) {
    s21_sub_positive_10String(abs_value_2_dotted, abs_value_1_dotted,
                              dotted_result);
    // ---------------------------------------------------
    // ↓ если второе число отрицательное и меньше первого:
    // ↓ то из первого вычтем второе. конечное число без минуса.
  } else if (value_2_isNegative &&
             dottedOnTheLeftIsLess(abs_value_2_dotted, abs_value_1_dotted)) {
    s21_sub_positive_10String(abs_value_1_dotted, abs_value_2_dotted,
                              dotted_result);
    // ---------------------------------------------------
    // ↓ если первое число отрицательное и больше второго:
    // ↓ то из первого вычтем второе и оставим минус.
  } else if (value_1_isNegative &&
             dottedOnTheLeftIsGreater(abs_value_1_dotted, abs_value_2_dotted)) {
    s21_sub_positive_10String(abs_value_1_dotted, abs_value_2_dotted,
                              dotted_result);
    appendMinusToDotted(dotted_result);
    // ---------------------------------------------------
    // ↓ если второе число отрицательное и больше первого:
    // ↓ то из второго вычтем первое и оставим минус.
  } else if (value_2_isNegative &&
             dottedOnTheLeftIsGreater(abs_value_2_dotted, abs_value_1_dotted)) {
    s21_sub_positive_10String(abs_value_2_dotted, abs_value_1_dotted,
                              dotted_result);
    appendMinusToDotted(dotted_result);
    // ---------------------------------------------------
    // ↓ оба числа положительные:
  } else {
    s21_add_positive_10String(value_1_dotted, value_2_dotted, dotted_result);
  }

  *result = dottedToDecimal(dotted_result);

  return 1;  // fix error return later
}

// --------
// S21_SUB:
// --------
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  char value_1_dotted[DEC_TEMP_VALUE_SIZE] = {0};
  char value_2_dotted[DEC_TEMP_VALUE_SIZE] = {0};
  char abs_value_1_dotted[DEC_TEMP_VALUE_SIZE] = {0};
  char abs_value_2_dotted[DEC_TEMP_VALUE_SIZE] = {0};
  char dotted_result[DEC_TEMP_VALUE_SIZE] = {0};
  decimalToDotted(value_1, value_1_dotted);
  decimalToDotted(value_2, value_2_dotted);

  bool value_1_isNegative = false;
  bool value_2_isNegative = false;

  if (isDottedNegative(value_1_dotted)) value_1_isNegative = true;
  if (isDottedNegative(value_2_dotted)) value_2_isNegative = true;

  dottedAbs(value_1_dotted, abs_value_1_dotted);
  dottedAbs(value_2_dotted, abs_value_2_dotted);

  // ↓ если оба числа отрицательные:
  if (value_1_isNegative && value_2_isNegative) {
    // ---------------------------------------------------
    // ↓ если первое числе меньше первого:
    // ↓ то абсуем оба и вычитаем первое из второго. оставляем без минуса.
    if (dottedOnTheLeftIsLess(abs_value_1_dotted, abs_value_2_dotted)) {
      s21_sub_positive_10String(abs_value_2_dotted, abs_value_1_dotted,
                                dotted_result);
      // ---------------------------------------------------
      // ↓ если второе число меньше первого:
      // ↓ то абсуем оба и вычитаем второе из первого. в конце добавляем минус.
    } else if (dottedOnTheLeftIsLess(abs_value_2_dotted, abs_value_1_dotted)) {
      s21_sub_positive_10String(abs_value_1_dotted, abs_value_2_dotted,
                                dotted_result);
      appendMinusToDotted(dotted_result);
    }
    // ---------------------------------------------------
    // ↓ если первое число отрицательное:
  } else if (value_1_isNegative) {
    s21_add_positive_10String(abs_value_1_dotted, abs_value_2_dotted,
                              dotted_result);
    appendMinusToDotted(dotted_result);
    // ---------------------------------------------------
    // ↓ если второе число отрицательное:
  } else if (value_2_isNegative) {
    s21_add_positive_10String(abs_value_1_dotted, abs_value_2_dotted,
                              dotted_result);
  }

  *result = dottedToDecimal(dotted_result);

  return 1;  // fix error return later
}

// HOMYAK:
// ---------------------------------------------------

// printf("[%s][%s][%s]\n", abs_value_1_dotted, abs_value_2_dotted,
//        dotted_result);

// printf("[%s]", value_1_dotted);
// printf("[%s]\n", value_2_dotted);

// printf("[%s]", value_1_dotted);
// printf("[%s]\n", value_2_dotted);
