#include "s21_decimal.h"

void sum_test(s21_decimal d1, s21_decimal d2) {
    printf("\nsum test:\n");
    s21_decimal res;
    int i = s21_add(d1, d2, &res);
    print_s21_decimal(res);
}

void sub_test(s21_decimal d1, s21_decimal d2) {
    printf("\nsub test:\n");
    s21_decimal res;
    int i = s21_sub(d1, d2, &res);
    print_s21_decimal(res);
}

void mul_test(s21_decimal d1, s21_decimal d2) {
    printf("\nmul test:\n");
    s21_decimal res;
    int i = s21_mul(d1, d2, &res);
    print_s21_decimal(res);
}

void div_test(s21_decimal d1, s21_decimal d2) {
    printf("\ndiv test:\n");
    s21_decimal res;
    int i = s21_div(d1, d2, &res);
    printf("\nres:\n");
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

void is_less_test(s21_decimal d1, s21_decimal d2) {
    printf("\nless test:\n");
    printf("\nres = %d\n", s21_is_less(d1, d2));
    printf("\nres = %d\n", s21_is_less(d2, d1));
    printf("\nres = %d\n", s21_is_less(d2, d2));
}

void parse_test_from_decimal(s21_decimal d1, int intVal, float floatVal, char* binChar, int flag, int sign) {

}

int main(void) {
    s21_decimal d1, d2, d3;
    int intVal = 12, flag = 0, sign = 1;
    float floatVal = 0.2;
    char binChar[RES_SIZE] = "1100";
    parse_test_to_decimal(&d1, &d2, &d3, intVal, floatVal, binChar, flag, sign);
    //sum_test(d2, d1);
    //sub_test(d1, d2);
    //mul_test(d1, d2);
    div_test(d1, d3);
    //is_less_test(d1, d2);
    return 0;
}