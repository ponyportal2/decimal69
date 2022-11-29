#define RAZR_SIZE 512
#define MAXLINE_FOR_REVERSE 2048

void decAdd(char* a, char* b, char result[][RAZR_SIZE]);
void reverse(char* string);
void itoa(long long num, char* src, int radix);
char* get(char input[][RAZR_SIZE], int i);