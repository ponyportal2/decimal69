#define VAS_ATOM_SIZE 8
#define VAS_MULTIPLY_SUBPRODUCT_SIZE 1024
#define VAS_REVERSE_MAXLINE 2048
#define VAS_INPUT_SIZE_MAX 1024
#define VAS_ATOMS_MAX 1024
#define VAS_MULTIPLY_SUBPRODUCTS 1024

#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t s21_strlen(const char* str);
int s21_add_pos_10String(char* a, char* b, char* result);
int s21_sub_pos_10String(char* a, char* b, char* result);
void decimMulti(char* a, char* b);
void decimFirstStepMulti(char* a, char* b, char** result);
void reAddZero(char* input, int dotPos);
void matrixToString(char** input, char* output);
void deDot(char* a, char* b, int* dotPos);
int addZerosAndReturnDotPos(char* a, char* b);
size_t s21_strlen(const char* str);
void minusTen(char* input);
void reverseString(char* inputArr);
void v10StringFirstStep(char* a, char* b, char** result, bool isSubtraction);
void v10StringSecondStepAdd(char** result);
void reverseString(char* string);
void itoa(long long num, char* src);
char* get(char** input, int i);
void matrixPrinter(char** result);
int matrixSizeDetector(char** result);
void reverseCharMatrix(char** inputArr, int n);
void place(int current, char** result, char* tempForItoa, int j);
void decimSubFirstStep(char* a, char* b, char** result);
void v10StringSecondStepSub(char** result);
void reverseStringAlt(char* inputArr);