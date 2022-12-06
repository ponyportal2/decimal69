#include "s21_decimal.h"

int main(void) {
    int n = 0;
    long double val = 12.34;
    char value[RES_SIZE] = "-6.42949672964294967296";
    //"123456789.123456789";
    //printf("%ld\n", parseLongInt(value, &n));
    //printf("n = %d\n", n);
    parseDecimal(value);
    return 0;
}