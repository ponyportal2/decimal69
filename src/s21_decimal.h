#define RAZR_SIZE 512
#define MAXLINE_FOR_REVERSE 2048
#define sint char

void minusTen(char* input);
void reverseString(char* inputArr);
void decimAddFirstStep(char* a, char* b, char** result);
void decimAddSecondStep(char** result);
void reverse(char* string);
void itoa(long long num, char* src, int radix);
char* get(char** input, int i);
void printer(char** result);
int sizeDetector(char** result);
void reverseCharMatrix(char** inputArr, int n);
void place(sint current, char** result, char* tempForItoa, int j);
void decimSubFirstStep(char* a, char* b, char** result);
void decimSubSecondStep(char** result);