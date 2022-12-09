#include "s21_decimal.h"

void sum_test(s21_decimal d1, s21_decimal d2) {
    printf("\nsum test:\n");
    s21_decimal res;
    int i = s21_add(d1, d2, &res);
    print_s21_decimal(res);
}

void parse_test_to_decimal(s21_decimal *d1, s21_decimal *d2, s21_decimal *d3, int intVal, float floatVal, char* binChar, int flag, int sign) {
    printf("\nd1 - %s\n", binChar);
    int i = s21_from_bin_char_to_decimal(binChar, flag, sign, d1);
    i = s21_from_int_to_decimal(intVal, d2);
    i = s21_from_float_to_decimal(floatVal, d3);
    print_s21_decimal(*d1);
    printf("\nd2 - %d\n", intVal);
    print_s21_decimal(*d2);
    printf("\nd3 - %f\n", floatVal);
    print_s21_decimal(*d3);
}

void parse_test_from_decimal(s21_decimal d1, int intVal, float floatVal, char* binChar, int flag, int sign) {

}

int main(void) {
    s21_decimal d1, d2, d3;
    int intVal = +834, flag = 0, sign = 1;
    float floatVal = 1.1;
    char binChar[RES_SIZE] = "1101000010";
    parse_test_to_decimal(&d1, &d2, &d3, intVal, floatVal, binChar, flag, sign);
    sum_test(d1, d2);
    return 0;
}