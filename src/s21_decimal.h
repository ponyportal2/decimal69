#ifndef S21_DECIMAL_H
#define S21_DECIMAL_H
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#define AB_SIZE 256
#define RES_SIZE 1024
#define MAX 79228162514264337593543950335
#define MAX_DEGREE 28
#define MIN_DEGREE 0
typedef struct 
{
    int bits[4];
} s21_decimal;
void longIntIoBinaryChar(long int val, char* revers);
char* itoa(unsigned int val, int base);
long int parseLongInt(char* value, int* n, int *flag);
s21_decimal parseDecimal(char * value);
char* parseChar(s21_decimal value);

#endif // S21_DECIMAL_H