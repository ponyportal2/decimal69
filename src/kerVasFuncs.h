#ifndef SRC_KERVASFUNCS_H_
#define SRC_KERVASFUNCS_H_

#include "kerFuncs.h"

s21_decimal dottedToDecimal(char *a);
void decimalToDotted(s21_decimal inputDecimal, char *outputDotted);
void dottedAbs(char *input, char *dottedResult);
bool isDottedNegative(const char *input);

#endif  // SRC_KERVASFUNCS_H_
