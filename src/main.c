#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX_LENGTH 96
#define MAX_LENGTH_PART 32

typedef struct {
    unsigned int bits[4];
}s21_decimal;

void decimalToBinary(s21_decimal decimal, char *binaryFull);
void binaryToString(char *binaryFull, char *decimalString);
bool stringToBinary(const char *decimalString, char *binaryString);
void binaryToDecimal(s21_decimal *decimal, char *binaryFull, int degree, int sign);

void findDegreeSign(unsigned int decimalBit3, int *degree, int *sign);

//void stringToDecimal(char *string, s21_decimal *decimal, int degree, int sign);
//void DecimalToString(s21_decimal decimal, char *decimalString);
int main() {
    s21_decimal decimal;
    char binaryFull[110] = {'\0'};
    binaryFull[97] = '\0';
    char decimalString[35] = {'\0'};
    int degree = 10, sign = 1;
    decimal.bits[0] = 2122534536;
    decimal.bits[1] = 123;
    decimal.bits[2] = 123;
    decimal.bits[3] = 3147483647;
   // findDegreeSign(decimal.bits[3], &degree, &sign);
   // DecimalToString(decimal, decimalString);
   decimalToBinary(decimal, binaryFull);
  // binaryToString(binaryFull, decimalString);
   binaryToDecimal(&decimal, binaryFull, 28, 1);
    char decimalStr[35] = {0};
    //strcpy(decimalStr, "456564566856754");
   // stringToDecimal(decimalStr, &decimal, 28, -1);
    //DecimalToBinary(decimalString, binaryString, MAX_LENGTH);
    return 0;
}


void findDegreeSign(unsigned int decimalBit3, int *degree, int *sign) {
    char binaryStack[40] = {'\0'};
    char binaryString[33];
    for (int i = 0; i < 32; i++) {
        binaryString[i] = '0';
    }
    binaryString[32] = '\0';
    int i = 0;
    while (decimalBit3 != 0) {
        if (decimalBit3 % 2 == 1) {
            binaryStack[i] = '1';
        } else {
            binaryStack[i] = '0';
        }
        i++;
        decimalBit3 = decimalBit3 / 2;
    }
    for (int j = 31, i = 0; i <= strlen(binaryStack) - 1; i++, j--){
        binaryString[j] = binaryStack[i];
    }
    if (binaryString[0] == '0') {
        *sign = 1;
    } else {
        *sign = -1;
    }
    int countToZero = 16;
    while (countToZero != 0 && i != 0) {
        countToZero--;
        i--;
    }
    char degreeString[10] = {'\0'};
    int countDegree = 4;
    while (countDegree >= 0 && i != 0) {
        degreeString[countDegree] = binaryString[i];
        i--;
        countDegree--;
    }
    *degree = strtol(degreeString, NULL, 2);
    if (*degree > 28) {
        *degree = 28;
    }
}

void binaryToDecimal(s21_decimal *decimal, char *binaryFull, int degree, int sign) {
    int lengthBin = strlen(binaryFull) - 1;
    for (int j = 0; j <= 2; j++) {
        char binaryPart[33];
        for (int i = 0; i < 32; i++) {
            binaryPart[i] = '0';
        }
        binaryPart[32] = '\0';
        int i = 31;
        while (lengthBin >= 0 && i >= 0) {
            binaryPart[i] = binaryFull[lengthBin];
            lengthBin--;
            i--;
        }
        (*decimal).bits[j] = strtol(binaryPart, NULL, 2);
        printf("%u\n",(*decimal).bits[j]);
    }
    char binaryString[33];
    if (sign == 1) {
        binaryString[0] = '0';
    } else {
        binaryString[0] = '1';
    }
    for (int i = 1; i < 32; i++) {
        binaryString[i] = '0';
    }
    binaryString[32] = '\0';
    char binaryStack[40] = {'\0'};
    int i = 0;
    while (degree != 0) {
        if (degree % 2 == 1) {
            binaryStack[i] = '1';
        } else {
            binaryStack[i] = '0';
        }
        i++;
        degree = degree / 2;
    }
    for (int i = 15, j = 0; j < strlen(binaryStack); i--, j++) {
        binaryString[i] = binaryStack[j];
    }
    (*decimal).bits[3] = strtol(binaryString, NULL, 2);
    printf("%u\n", (*decimal).bits[3]);
}

void decimalToBinary(s21_decimal decimal, char *binaryFull) {
    for (int o = 2; o >= 0; o--) {
    char binaryString[33];
    char binaryStack[45] = {'\0'};
    for (int i = 0; i < 32; i++) {
        binaryString[i] = '0';
    }
    binaryString[32] = '\0';
    int i = 0;
    while (decimal.bits[o] != 0) {
        if (decimal.bits[o] % 2 == 1) {
            binaryStack[i] = '1';
        } else {
            binaryStack[i] = '0';
        }
        i++;
        decimal.bits[o] = decimal.bits[o] / 2;
    }
    i = strlen(binaryStack) - 1;
    while (binaryStack[i] == '0') {
        i--;
    }
    for (int j = 31, k = 0; k <= i; k++, j--){
        binaryString[j] = binaryStack[k];
    }
    strcat(binaryFull, binaryString);
    }
  //  printf("%s\n", binaryFull);
}

void binaryToString(char *binaryFull, char *decimalString) {
    int zeroCounter = 0;
    int numCounter = 0;
    while (binaryFull[0] != '\0') {
        int R = 0;
        char binaryStack[110] = "";
        for (int i = 0; i < strlen(binaryFull); i++) {
            R = 2*R + binaryFull[i] - '0';
            if (R >= 10) {
                binaryStack[i] = '1';
                R -= 10;
            } else {
                binaryStack[i] = '0';
            }
        }
        decimalString[numCounter] = R + 48;
        numCounter++;
        binaryStack[strlen(binaryFull) -  zeroCounter] = '\0';
        int j = 0;
        while (binaryStack[j] == '0') {
            j++;
        }
        for (int i = 0, k = j; i < strlen(binaryStack) - j; i++, k++) {
            binaryFull[i] = binaryStack[k];
        }
        binaryFull[strlen(binaryStack) - j] = '\0';
        zeroCounter = 0;
    }
    decimalString[numCounter] = '\0';
    char invert;
    for (int i = 0; i < strlen(decimalString) / 2; i++) {
        invert = decimalString[i];
        decimalString[i] = decimalString[strlen(decimalString) - 1 - i];
        decimalString[strlen(decimalString) - 1 - i] = invert;
    }
    printf("%s\n", decimalString);
}


bool stringToBinary(const char *decimalString, char *binaryString) {
    char binaryStack[110] = {'\0'};
    char decimalStr[35] = {0};
    strcpy(decimalStr, decimalString);
    int additive = 0;
    int next_additive;
    int k = 0;
    bool toBreak = true;
    bool overflow = false;
    if ((int)(decimalStr[strlen(decimalStr) - 1] - '0') % 2 == 1){
        binaryStack[k] = '1';
    } else {
        binaryStack[k] = '0';
    }
    k++;
    while (toBreak){
        additive = 0;
        int j = 0;
        while (decimalStr[j] == '0') {
            j++;
        }
        if (j == (int)strlen(decimalStr)) {
            toBreak = false;
        }
        while (decimalStr[j] != '\0') {
            if ((int)(decimalStr[j] - '0') % 2 == 1) {
                next_additive = 5;
            } else {
                next_additive = 0;
            }
            int newNum = ((int)(decimalStr[j] - '0'))/2 + additive;
            decimalStr[j] = newNum + '0';
            additive = next_additive;
            j++;
        }
        if ((int)(decimalStr[strlen(decimalStr) - 1] - '0') % 2 == 1){
            binaryStack[k] = '1';
        } else {
            binaryStack[k] = '0';
        }
        k++;
    }
    int i = strlen(binaryStack) - 1;
    while (binaryStack[i] == '0') {
        i--;
    }
    for (int j = 0; i >= 0; i--, j++){
        binaryString[j] = binaryStack[i];
    }
  //  printf("%s\n", binaryString);
    if (strlen(binaryString) > 96) {
        overflow = true;
    }
    return overflow;
}

/*
void DecimalToString(s21_decimal decimal, char *decimalString) {
    for (int i = 2; i >=0; i--) {
        char decimalPart[12] = {'\0'};
        sprintf(decimalPart, "%d", decimal.bits[i]);
        strcat(decimalString, decimalPart);
    }
}



void stringToDecimal(char *string, s21_decimal *decimal, int degree, int sign) {
    for (int j = 0; j <= 2; j++) {
    char partString[12] = {'\0'};
    char binaryString[110] = {'\0'};
    int cutString = 0;
    int maxLength = 9;
    partString[10] = '\0';
    if (maxLength > strlen(string)) {
        maxLength = strlen(string) - 1;
    }
    for (int i = strlen(string) - 1; i >= 0 && maxLength >= 0; i--, maxLength--){
        partString[maxLength] = string[i];
        cutString++;
    }
    if (DecimalOverflowCheck(partString, binaryString, MAX_LENGTH_PART)) {
        partString[9] = '\0';
        maxLength = cutString - 2;
        cutString = 0;
        for (int i = strlen(string) - 1; maxLength >= 0; i--, maxLength--){
            partString[maxLength] = string[i];
            cutString++;
        }
    }
    string[strlen(string) - cutString] = '\0';
    (*decimal).bits[j] = strtol(partString, NULL, 10);
    printf("%u\n", (*decimal).bits[j]);
    }
    char binaryString[33];
    if (sign == 1) {
        binaryString[0] = '0';
    } else {
        binaryString[0] = '1';
    }
    for (int i = 1; i < 32; i++) {
        binaryString[i] = '0';
    }
    binaryString[32] = '\0';
    char binaryStack[40] = {'\0'};
    int i = 0;
    while (degree != 0) {
        if (degree % 2 == 1) {
            binaryStack[i] = '1';
        } else {
            binaryStack[i] = '0';
        }
        i++;
        degree = degree / 2;
    }
    printf("%s\n", binaryStack);
    for (int i = 15, j = 0; j < strlen(binaryStack); i--, j++) {
        binaryString[i] = binaryStack[j];
    }
    (*decimal).bits[3] = strtol(binaryString, NULL, 2);
    printf("%u\n", (*decimal).bits[3]);
}

*/