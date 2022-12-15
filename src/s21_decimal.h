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
int bin_char_to_int(char* binNum, int flag, int sign);
float bin_char_to_float(char* binNum, int flag, int sign);
s21_decimal set_result(char * res, int flag, int sign);
void set_sign_and_flag(char* val, int* sign, int *flag);
void print_s21_decimal(s21_decimal dec);
void getBits3Char(char* special, int flag, int sign);
s21_decimal set_bits(char* value);
void get_res_char(char * res);
s21_decimal get_result(char * binChar, int flag, int sign);
s21_decimal parseFromBinToDecimal(char *value);
void getFlagAndPoint(s21_decimal value, int* flag, int* point);
void addZeroAfterSign(char* var, int sign1, int *sign2);
void addZeroBeforeNumber(char* var, int size1, int size2);
void reverse(char *value);
void sum(char* num1, char *num2, char * res);
void sub(char* num1, char *num2, char * res);
void mul(char* num1, char *num2, char * res);
void div_(char* num1, char *num2, char * res);
void format_num_for_operation(s21_decimal value_1, s21_decimal value_2, char* num1, char* num2, int *flag1, int *flag2, int *sign1, int *sign2);
int get_bin_char_flag_and_sign(s21_decimal src, char* num, int *flag, int *sign);
void from_decimal_to_bin_char(s21_decimal src, char* num);
int s21_from_bin_char_to_decimal(char* src, int flag, int sign, s21_decimal *dst);
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mod(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_is_less(s21_decimal, s21_decimal);
int s21_is_less_or_equal(s21_decimal, s21_decimal);
int s21_is_greater(s21_decimal, s21_decimal);
int s21_is_greater_or_equal(s21_decimal, s21_decimal);
int s21_is_equal(s21_decimal, s21_decimal);
int s21_is_not_equal(s21_decimal, s21_decimal);
int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);
int s21_floor(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_negate(s21_decimal value, s21_decimal *result);
void longIntIoBinaryChar(long int val, char* revers);
char* itoa(unsigned int val, int base);
long int parseLongInt(char* value, int* n, int *flag);
s21_decimal parseDecimal(char * value);
char* parseChar(s21_decimal value);

#endif // S21_DECIMAL_H