#include "s21_decimal.h"

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  char value_1_dotted[1024] = {0};
  char value_2_dotted[1024] = {0};
  char dotted_result[1024] = {0};
  decimalToDotted(value_1, value_1_dotted);
  decimalToDotted(value_2, value_2_dotted);
  printf("[%s]", value_1_dotted);
  printf("[%s]\n", value_2_dotted);
  s21_add_positive_10String(value_1_dotted, value_2_dotted, dotted_result);
  *result = dottedToDecimal(dotted_result);

  return 1;  // fix error return later
}
