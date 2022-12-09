#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int countWords(char *text);

int main() {
    char text[100000] = "Casabasadasaf, sdvsxz. Nfd2g2! Davadad? SDssfbS.";
    printf("%d", countWords(text));
    return 0;
}

int countWords(char *text) {
    int returnValue = 0;
    char dividers[5] = "., ?!";
    char glasn[15] = "AEIOUYaeiouy";
    char soglas[40] = "BCDFGHJKLMNPQRSTVWXZbcdfghjklmnpqrstvwxz";
    char *str = strtok(text, dividers); // find first word
    while (str != NULL) { // while we have words in string
        int check = 0; // to check if letters match the condition
        for (int i = 0; i < strlen(str); i++){ // check every letter in word
            char getChar[2];
            sprintf(getChar, "%c", str[i]); // get letter as string
            if ((strpbrk(getChar, glasn) != NULL) &&
            (check == 1 || check == 0)) { // if letter matches "glasn" and previous letter
                                         // matches "soglas" (or 0 if it start of the cycle)
                check = 2;
            } else if ((strpbrk(getChar, soglas) != NULL) &&  // same for "soglas" letters
            (check == 2 || check == 0)) {
                check = 1;
            } else {
                break; // if not match that conditions then break
            }
            if (i == strlen(str) - 1) {
                returnValue++; // if we checkt all word then add one to counter of such words
            }
        }
        
        str = strtok(NULL, dividers); // get next word
    }
    return returnValue;
}