#include "s21_decimal.h"

int main(void) {
    int n = 0;
    long double val = 12.34;
    char value[RES_SIZE] = "12.3";
    //"123456789.123456789"
    //printf("%ld\n", parseLongInt(value, &n));
    //printf("n = %d\n", n);
    //s21_decimal d1 = parseDecimal(value);
    //s21_decimal d2 = parseDecimal("0.3");
    s21_decimal d3;
    //printf("%s", parseChar(d2));
    int v = +834;
    int j = s21_from_int_to_decimal(v, &d3);
   // int i = s21_add(d1, d2, &d3);
    print_s21_decimal(d3);
    return 0;
}