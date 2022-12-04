#define RAZR_SIZE 512
#define MAXLINE_FOR_REVERSE 2048
// #define sint char
#include <stdbool.h>
#include <stddef.h>

void deDot();
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