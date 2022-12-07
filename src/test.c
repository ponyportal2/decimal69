#include "s21_decimal.h"

int main(void) {
    int n = 0;
    long double val = 12.34;
    char value[RES_SIZE] = "12.3";
    //"123456789.123456789"
    //printf("%ld\n", parseLongInt(value, &n));
    //printf("n = %d\n", n);
    s21_decimal dec = parseDecimal(value);
    printf("%s", parseChar(dec));
    //s21_decimal d1, d2, d3;
  //  int i = s21_add(d1, d2, &d3);
    return 0;
}