#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "decimal_struct.h"
#define KER_MAX_LENGTH 96
#define KER_MAX_LENGTH_PART 32
#define KER_SIZE 1024
#define KER_DTD_SIZE 1024

// new from vasjan:
s21_decimal dottedToDecimal(char *a);
void decimalToDotted(s21_decimal inputDecimal, char *outputDotted);
// ----------------

unsigned int signDegreeToNumber(int sign, int degree);
void dottedToDegree(char *strDot, char *noDot, int *degree, int *sign);
void degreeToDotted(char *strDot, char *noDot, int degree, int sign);

void decimalToBinary(s21_decimal decimal, char *binaryFull);
void binaryToString(char *binaryFull, char *decimalString);
bool stringToBinaryHelp(const char *decimalString, char *binaryString);
bool stringToBinary(const char *decimalString, char *binaryString, int *degree);
void binaryToDecimal(s21_decimal *decimal, char *binaryFull, int degree,
                     int sign);

int s21_from_decimal_to_int(s21_decimal decimal, int *dst);
int s21_from_decimal_to_float(s21_decimal decimal, float *dst);

int s21_from_int_to_decimal(int src, s21_decimal *decimal);
int s21_from_float_to_decimal(float src, s21_decimal *decimal);

int s21_round(s21_decimal value, s21_decimal *result);
int s21_floor(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_negate(s21_decimal value, s21_decimal *result);

int s21_is_less(s21_decimal first, s21_decimal second);
int s21_is_less_or_equal(s21_decimal first, s21_decimal second);
int s21_is_greater(s21_decimal first, s21_decimal second);
int s21_is_greater_or_equal(s21_decimal first, s21_decimal second);
int s21_is_equal(s21_decimal first, s21_decimal second);
int s21_is_not_equal(s21_decimal first, s21_decimal second);
int s21_div(s21_decimal first, s21_decimal second, s21_decimal *result);
int s21_mod(s21_decimal first, s21_decimal second, s21_decimal *result);

void findDegreeSign(unsigned int decimalBit3, int *degree, int *sign);
void toOneDegree(char *firstString, char *secondString, int firstDegree,
                 int secondDegree);
int compareString(const char *firstString, const char *secondString,
                  int firstDegree, int firstSign, int secondDegree,
                  int secondSign);
int convertForCompare(s21_decimal first, s21_decimal second);

void bankRound(char rememberLast, char *binaryString, char *decimalNew,
               bool *overflow);
void delZeros(char *binaryString, char *decimalNew, int *degree,
              bool *overflow);
void subString(const char *firstString, const char *secondString,
               int firstDegree, int secondDegree, char *resultString);
int divString(const char *firstString, const char *secondString,
              int firstDegree, int secondDegree, char *resultString);
int modString(const char *firstString, const char *secondString,
              int firstDegree, int secondDegree, char *resultString);

// void stringToDecimal(char *string, s21_decimal *decimal, int degree, int
// sign); void DecimalToString(s21_decimal decimal, char *decimalString);