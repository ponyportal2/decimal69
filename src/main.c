#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#define MAX_LENGTH 96
#define MAX_LENGTH_PART 32
#define SIZE 1024

typedef struct {
    unsigned int bits[4];
}s21_decimal;

void decimalToBinary(s21_decimal decimal, char *binaryFull);
void binaryToString(char *binaryFull, char *decimalString);
bool stringToBinary(const char *decimalString, char *binaryString, int *degree);
void binaryToDecimal(s21_decimal *decimal, char *binaryFull, int degree, int sign);

int s21_from_decimal_to_int(s21_decimal decimal, int *dst);
int s21_from_decimal_to_float(s21_decimal decimal, float *dst);


int s21_from_int_to_decimal(int src, s21_decimal *decimal);
int s21_from_float_to_decimal(float src, s21_decimal *decimal);

int s21_round(s21_decimal value, s21_decimal *result);
int s21_floor(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_negate(s21_decimal value, s21_decimal *result);

void findDegreeSign(unsigned int decimalBit3, int *degree, int *sign);

//void stringToDecimal(char *string, s21_decimal *decimal, int degree, int sign);
//void DecimalToString(s21_decimal decimal, char *decimalString);
int main() {
    s21_decimal decimal, intCheck;
    char binaryFull[SIZE] = {'\0'};
  //  binaryFull[97] = '\0';
    char decimalString[SIZE] = {'\0'};
    int degree = 3, sign = 0;
    float dst = 0;

    decimal.bits[0] = 2122534536;
    decimal.bits[1] = 15676;
    decimal.bits[2] = 123;
    decimal.bits[3] = 2294933502;
   // findDegreeSign(decimal.bits[3], &degree, &sign);
   // DecimalToString(decimal, decimalString);
  // decimalToBinary(decimal, binaryFull);
  // binaryToString(binaryFull, decimalString);
 //  binaryToDecimal(&decimal, binaryFull, 28, 1);
 //   char decimalStr[35] = {0};
 //stringToBinary("772281625142643375935439999991", binaryFull, &degree);
   //  printf("%d\n", degree);
 //printf("%s\n", binaryFull);
// s21_from_int_to_decimal(-42134, &intCheck);
//s21_from_decimal_to_float(decimal, &dst);
s21_negate(decimal, &intCheck);
//s21_from_float_to_decimal(78228169514264337593543950334.123446789, &intCheck);
    //strcpy(decimalStr, "456564566856754");
   // stringToDecimal(decimalStr, &decimal, 28, -1);
    //DecimalToBinary(decimalString, binaryString, MAX_LENGTH);
    return 0;
}


void findDegreeSign(unsigned int decimalBit3, int *degree, int *sign) {
    if (decimalBit3 == 0) {
        *degree = 0;
         *sign = 1;
    } else {
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
    i = 31;
    while (countToZero != 0) {
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
    /*
    char binaryDegree[100] = {'\0'};
    binaryToString(binaryString, binaryDegree);
    printf("%s\n", binaryDegree);
    i = 0;
    while (binaryDegree[i] != '\0') {
        (*decimal).bits[3] = (*decimal).bits[3] * 10 + (binaryDegree[i] - '0');
        i++;
    }
    */
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
        char binaryStack[SIZE] = "";
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
}


bool stringToBinary(const char *decimalString, char *binaryString, int *degree) {
    char binaryStack[SIZE] = {'\0'};
    char decimalStr[SIZE] = {0};
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
        if (i == 0) {
            binaryString[j + 1] = '\0';
        }
    }
  //  printf("%s\n", binaryString);
    if (strlen(binaryString) > 96 && *degree == 0) {
        overflow = true;
    } else if (strlen(binaryString) > 96 && *degree > 0) {
        *degree -= 1;
        char decimalNew[SIZE] = {0};
        strcpy(decimalNew, decimalString);
        char rememberLast = decimalNew[strlen(decimalNew) - 1];
        decimalNew[strlen(decimalNew) - 1] = '\0';
        for (int i = 0; i < strlen(binaryString); i++) {
            binaryString[i] = '\0';
        }
        overflow = stringToBinary(decimalNew, binaryString, degree);
        if (rememberLast > '5' || (rememberLast == '5' && decimalNew[strlen(decimalNew) - 1] % 2 == 1)) {
            int lastNumCounter = 1;
            while (decimalNew[strlen(decimalNew) - lastNumCounter] == '9') {
                decimalNew[strlen(decimalNew) - lastNumCounter] = '0';
                lastNumCounter++;
            }
            decimalNew[strlen(decimalNew) - lastNumCounter]++;        
            if (decimalNew[0] == '0') {
                decimalNew[0] = '1';
                decimalNew[strlen(decimalNew) + 1] = '\0';
                decimalNew[strlen(decimalNew)] = '0';
            }
            for (int i = 0; i < strlen(binaryString); i++) {
                binaryString[i] = '\0';
            }
            overflow = stringToBinary(decimalNew, binaryString, degree);
        }
        if (decimalNew[strlen(decimalNew) - 1] == '0' && *degree > 0) {
            while (decimalNew[strlen(decimalNew) - 1] == '0' && *degree > 0) {
                decimalNew[strlen(decimalNew) - 1] = '\0';
                *degree-=1;
            }
            for (int i = 0; i < strlen(binaryString); i++) {
                binaryString[i] = '\0';
            }
            overflow = stringToBinary(decimalNew, binaryString, degree);
        }
    }
    return overflow;
}

int s21_from_int_to_decimal(int src, s21_decimal *decimal) {
    if (src < 0) {
        (*decimal).bits[3] = 2147483648;
    } else {
        (*decimal).bits[3] = 0;
    }
    (*decimal).bits[0] = abs(src);
    (*decimal).bits[1] = 0;
    (*decimal).bits[2] = 0;
 //   printf("%d\n", (*decimal).bits[0]);
  //  float asd = 1236556433.25241675;
  //  printf("%.20f\n", asd);
    return 0;
}

int s21_from_float_to_decimal(float src, s21_decimal *decimal) {
    int returnValue = 0;
    int sign = 0, degree = 0;
    int string = 0;
    long double zeroCount = 1;
    long double saveSrc = src;
    if (fabs(src) > 0 && fabs(src) < 1e-28) {
        returnValue = 1;
        (*decimal).bits[0] = 0;
        (*decimal).bits[1] = 0;
        (*decimal).bits[2] = 0;
        (*decimal).bits[3] = 0;
    } else if (src > 79228162514264337593543950335. || src < -79228162514264337593543950335. || src == INFINITY || src == -INFINITY) {
        returnValue = 1;
    } else {
        if (src < 0) {
            src = src * (-1);
            sign = -1;
        } else {
            sign = 1;
        }
        int eightNum = 0;
        if ((int)src == 0) {
            while ((int)src == 0) {
                src = src * 10;
                degree++;
            }
            for (int i = 2; i <= 7 && degree <= 28; i++, degree++){
                src = src * 10;
            }
            eightNum = (int)(src * 10) % 10;
            string = (int)src;
            if (eightNum >= 5) {
                string++;
            }
        } else if (src < 1000000) {
            while (src < 1000000) {
                src = src * 10;
                degree++;
            }
            eightNum = (int)(src * 10) % 10;
            string = (int)src;
            if (eightNum >= 5) {
                string++;
            }
        } else {
            while (saveSrc > 10000000) {
                saveSrc = saveSrc / 10;
                zeroCount *= 10;
            }
            eightNum = (int)(saveSrc * 10) % 10;
            string = (int)saveSrc;
            if (eightNum >= 5) {
                string++;
            }
        }
    }
    char stringToDec[SIZE];
    sprintf(stringToDec, "%d", string);
    while (zeroCount != 1) {
        stringToDec[strlen(stringToDec) + 1] = '\0';
        stringToDec[strlen(stringToDec)] = '0'; 
        zeroCount /= 10;
    }
    char binaryString[SIZE] = {'\0'};
    printf("%s\n", stringToDec);
    stringToBinary(stringToDec, binaryString, &degree);
    binaryToDecimal(decimal, binaryString, degree, sign);
    printf("%u\n%u\n%u\n%u\n", (*decimal).bits[2], (*decimal).bits[1], (*decimal).bits[0], (*decimal).bits[3]);
    return returnValue;
}

int s21_from_decimal_to_int(s21_decimal decimal, int *dst) {
    int returnValue;
    char binaryFull[110] = {'\0'};
    char binaryPart[40] = {'\0'};
    char decimalString[35] = {'\0'};
    int sign = 0, degree = 0;
    decimalToBinary(decimal, binaryFull);
    binaryToString(binaryFull, decimalString);
    findDegreeSign(decimal.bits[3], &degree, &sign);
    while (degree > 0 && strlen(decimalString) != 0) {
        decimalString[strlen(decimalString) - 1] = '\0';
        degree--;
    }
    stringToBinary(decimalString, binaryPart, 0);
    if (strlen(binaryPart) > 31) {
        returnValue = 1;
    } else {
        *dst = sign * strtol(binaryPart, NULL, 2);
        returnValue = 0;
    }
    return returnValue;
}

int s21_from_decimal_to_float(s21_decimal decimal, float *dst) {
    char binaryFull[110] = {'\0'};
    char decimalString[35] = {'\0'};
    int sign = 0, degree = 0;
    decimalToBinary(decimal, binaryFull);
    binaryToString(binaryFull, decimalString);
    findDegreeSign(decimal.bits[3], &degree, &sign);
    printf("%s\n", decimalString);
     *dst = decimalString[0] - '0';
    double degreeCount = 10;
    long double result = decimalString[0] - '0';
    int leftPart = strlen(decimalString) - 1 - degree;
    for (int i = 1; i < strlen(decimalString); i++) {
        if (leftPart > 0) {
            result = result * 10 + decimalString[i] - '0';
            leftPart--;
        } else {
            result = result + (decimalString[i] - '0')/degreeCount;
            degreeCount *= 10;
        }
    }
    *dst = (float)result;
    printf("%e\n", *dst);
    return 0;
}


int s21_round(s21_decimal value, s21_decimal *result) {
    bool overflow = false;
    char binaryFull[110] = {'\0'};
    char decimalString[35] = {'\0'};
    int degree = 0, sign = 0;
    decimalToBinary(value, binaryFull);
    binaryToString(binaryFull, decimalString);
    findDegreeSign(value.bits[3], &degree, &sign);
    printf("%d\n", degree);
    int i = strlen(decimalString) - 1;
    char rememberLast = '\0';
    printf("%s\n", decimalString);
    while (degree != 0 && i >= 0) {
        rememberLast = decimalString[i];
        decimalString[i] = '\0';
        degree--;
        i--;
    }
    int lastNumCounter = 1;
    if (rememberLast >= '5') {
        while (decimalString[i] == '9') {
            decimalString[i] = '0';
            i--;
        }
        decimalString[i]++;
        if (decimalString[0] == '0') {
            decimalString[0] = '1';
            decimalString[strlen(decimalString) + 1] = '\0';
            decimalString[strlen(decimalString)] = '0';
        }
    }
    printf("%s\n", decimalString);
    char binaryString[110] = {'\0'};
    overflow = stringToBinary(decimalString, binaryString, &degree);
    printf("%s\n", binaryString);
    if (overflow == false) {
        binaryToDecimal(result, binaryString, degree, sign);
    }
    printf("%u\n%u\n%u\n%u\n", (*result).bits[2], (*result).bits[1], (*result).bits[0], (*result).bits[3]);
    return overflow;
}


int s21_floor(s21_decimal value, s21_decimal *result) {
    bool overflow = false;
    char binaryFull[110] = {'\0'};
    char decimalString[35] = {'\0'};
    int degree = 0, sign = 0;
    decimalToBinary(value, binaryFull);
    binaryToString(binaryFull, decimalString);
    findDegreeSign(value.bits[3], &degree, &sign);
    printf("%d\n", degree);
    int i = strlen(decimalString) - 1;
    char rememberLast = '\0';
    printf("%s\n", decimalString);
    while (degree != 0 && i >= 0) {
        rememberLast = decimalString[i];
        decimalString[i] = '\0';
        degree--;
        i--;
    }
    int lastNumCounter = 1;
    if (sign == -1) {
        while (decimalString[i] == '9') {
            decimalString[i] = '0';
            i--;
        }
        decimalString[i]++;
        if (decimalString[0] == '0') {
            decimalString[0] = '1';
            decimalString[strlen(decimalString) + 1] = '\0';
            decimalString[strlen(decimalString)] = '0';
        }
    }
    printf("%s\n", decimalString);
    char binaryString[110] = {'\0'};
    overflow = stringToBinary(decimalString, binaryString, &degree);
    printf("%s\n", binaryString);
    if (overflow == false) {
        binaryToDecimal(result, binaryString, degree, sign);
    }
    printf("%u\n%u\n%u\n", (*result).bits[2], (*result).bits[1], (*result).bits[0]);
    return overflow;
}

int s21_truncate(s21_decimal value, s21_decimal *result) {
    bool overflow = false;
    char binaryFull[110] = {'\0'};
    char decimalString[35] = {'\0'};
    int degree = 0, sign = 0;
    decimalToBinary(value, binaryFull);
    binaryToString(binaryFull, decimalString);
    findDegreeSign(value.bits[3], &degree, &sign);
    printf("%d\n", degree);
    int i = strlen(decimalString) - 1;
    printf("%s\n", decimalString);
    while (degree != 0 && i >= 0) {
        decimalString[i] = '\0';
        degree--;
        i--;
    }
    int lastNumCounter = 1;
    printf("%s\n", decimalString);
    char binaryString[110] = {'\0'};
    overflow = stringToBinary(decimalString, binaryString, &degree);
    printf("%s\n", binaryString);
    if (overflow == false) {
        binaryToDecimal(result, binaryString, degree, sign);
    }
    printf("%u\n%u\n%u\n", (*result).bits[2], (*result).bits[1], (*result).bits[0]);
    return overflow;
}

int s21_negate(s21_decimal value, s21_decimal *result) {
    char reverseString[33] = {'\0'};
    char oldString[33];
    for (int i = 0; i < 32; i++) {
        oldString[i] = '0';
    }
    oldString[32] = '\0';
    int i = 0;
    while (value.bits[3] != 0) {
        if (value.bits[3] % 2 == 1) {
            oldString[i] = '1';
        } else {
            oldString[i] = '0';
        }
        i++;
        value.bits[3] = value.bits[3] / 2;
    }
    if (oldString[31] == '0') {
        oldString[31] = '1';
    } else {
        oldString[31] = '0';
    }
    for (int j = 31, k = 0; k <= i; k++, j--){
        reverseString[j] = oldString[k];
    }
    (*result).bits[0] = value.bits[0];
    (*result).bits[1] = value.bits[1];
    (*result).bits[2] = value.bits[2];
    (*result).bits[3] = strtol(reverseString, NULL, 2);
    printf("%s\n", reverseString);
    printf("%ld\n", strtol(reverseString, NULL, 2));
    return 0;
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