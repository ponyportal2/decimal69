#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    int bits[4];
}s21_decimal;

void DecimalToBinary(char decimalStr[35], char binaryString[100]);
void DecimalToString(s21_decimal decimal, char decimalString[100]);

int main() {
    s21_decimal decimal;
    char binaryString[110] = {'\0'};
    char decimalString[35] = {'\0'};
    decimal.bits[0] = 2122534536;
    decimal.bits[1] = 2122474454;
    decimal.bits[2] = 202234567;
    DecimalToString(decimal, decimalString);
    DecimalToBinary(decimalString, binaryString);
    return 0;
}

void DecimalToString(s21_decimal decimal, char decimalString[100]) {
    char binaryStack[110] = {'\0'};
    for (int i = 2; i >=0; i--) {
        char decimalPart[12] = {'\0'};
        sprintf(decimalPart, "%d", decimal.bits[i]);
        strcat(decimalString, decimalPart);
    }
}

void DecimalToBinary(char decimalStr[35], char binaryString[100]) {
    char binaryStack[110] = {'\0'};
    int additive = 0;
    int next_additive;
    int k = 0;
    bool toBreak = true;
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
    printf("%s\n", binaryString);
    if (strlen(binaryString) > 96) {
        printf("error\n");
    }
}