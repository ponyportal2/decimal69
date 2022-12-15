#define ATOM_SIZE 8
#define MULT_SUBPRODUCT_SIZE 1024
#define MAXLINE_FOR_REVERSE 2048
#define MAX_INPUT_SIZE 1024
#define MAX_ATOMS 1024
#define MAX_MULT_SUBPRODUCTS 1024

#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void decimMulti(char* a, char* b);
void decimFirstStepMulti(char* a, char* b, char** result);
void reAddZero(char* input, int dotPos);
void matrixToString(char** input, char* output);
void deDot(char* a, char* b, int* dotPos);
int addZerosAndReturnDotPos(char* a, char* b);
size_t s21_strlen(const char* str);
void minusTen(char* input);
void reverseString(char* inputArr);
void decimFirstStep(char* a, char* b, char** result, bool isSubtraction);
void decimSecondStepAdd(char** result);
void reverse(char* string);
void itoa(long long num, char* src);
char* get(char** input, int i);
void printer(char** result);
int sizeDetector(char** result);
void reverseCharMatrix(char** inputArr, int n);
void place(int current, char** result, char* tempForItoa, int j);
void decimSubFirstStep(char* a, char* b, char** result);
void decimSecondStepSub(char** result);