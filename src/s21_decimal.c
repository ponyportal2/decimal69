#include "s21_decimal.h"

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  char value_1_dotted[1024] = {0};
  char value_2_dotted[1024] = {0};
  char abs_value_1_dotted[1024] = {0};
  char abs_value_2_dotted[1024] = {0};
  char dotted_result[1024] = {0};
  decimalToDotted(value_1, value_1_dotted);
  decimalToDotted(value_2, value_2_dotted);

  bool value_1_isNegative = false;
  bool value_2_isNegative = false;

  if (isDottedNegative(value_1_dotted)) value_1_isNegative = true;
  if (isDottedNegative(value_2_dotted)) value_2_isNegative = true;

  // ↓ если оба числа отрицательные, то откладываем их, в конце добавляем минус:
  if (value_1_isNegative && value_2_isNegative) {
    dottedAbs(value_1_dotted, abs_value_1_dotted);
    dottedAbs(value_2_dotted, abs_value_2_dotted);
    s21_add_positive_10String(abs_value_1_dotted, abs_value_2_dotted,
                              dotted_result);
    // ↓ если первое число отрицательное и меньше второго:
    // ↓ то из второго вычтем первое. конечное число без минуса.
  } else if (value_1_isNegative && s21_is_less(value_1, value_2)) {
    // ↓ если второе число отрицательное и меньше первого:
    // ↓ то из первого вычтем второе. конечное число без минуса.
  } else if (value_2_isNegative && s21_is_less(value_2, value_1)) {
    // ↓ если первое число отрицательное и больше второго:
    // ↓ то из первого вычтем второе и оставим минус.
  } else if (value_1_isNegative && s21_is_greater(value_1, value_2)) {
    // ↓ если второе число отрицательное и больше первого:
    // ↓ то из второго вычтем первое и оставим минус.
  } else if (value_2_isNegative && s21_is_greater(value_2, value_1)) {
    // ↓ оба числа положительные:
  } else {
    s21_add_positive_10String(value_1_dotted, value_2_dotted, dotted_result);
  }

  // printf("[%s]", value_1_dotted);
  // printf("[%s]\n", value_2_dotted);
  *result = dottedToDecimal(dotted_result);

  return 1;  // fix error return later
}

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  char value_1_dotted[1024] = {0};
  char value_2_dotted[1024] = {0};
  char abs_value_1_dotted[1024] = {0};
  char abs_value_2_dotted[1024] = {0};
  char dotted_result[1024] = {0};
  decimalToDotted(value_1, value_1_dotted);
  decimalToDotted(value_2, value_2_dotted);

  bool value_1_isNegative = false;
  bool value_2_isNegative = false;

  if (isDottedNegative(value_1_dotted)) value_1_isNegative = true;
  if (isDottedNegative(value_2_dotted)) value_2_isNegative = true;

  // ↓ если оба числа отрицательные, то откладываем их, в конце добавляем минус:
  if (value_1_isNegative && value_2_isNegative) {
    dottedAbs(value_1_dotted, abs_value_1_dotted);
    dottedAbs(value_2_dotted, abs_value_2_dotted);
    s21_sub_positive_10String(abs_value_1_dotted, abs_value_2_dotted,
                              dotted_result);
    // ↓ если первое число отрицательное и меньше второго:
    // ↓ то из второго вычтем первое. конечное число без минуса.
  } else if (value_1_isNegative && s21_is_less(value_1, value_2)) {
    // ↓ если второе число отрицательное и меньше первого:
    // ↓ то из первого вычтем второе. конечное число без минуса.
  } else if (value_2_isNegative && s21_is_less(value_2, value_1)) {
    // ↓ если первое число отрицательное и больше второго:
    // ↓ то из первого вычтем второе и оставим минус.
  } else if (value_1_isNegative && s21_is_greater(value_1, value_2)) {
    // ↓ если второе число отрицательное и больше первого:
    // ↓ то из второго вычтем первое и оставим минус.
  } else if (value_2_isNegative && s21_is_greater(value_2, value_1)) {
    // ↓ оба числа положительные:
  } else {
    s21_sub_positive_10String(value_1_dotted, value_2_dotted, dotted_result);
  }

  // printf("[%s]", value_1_dotted);
  // printf("[%s]\n", value_2_dotted);
  *result = dottedToDecimal(dotted_result);

  return 1;  // fix error return later
}
