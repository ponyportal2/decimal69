#include "s21_decimal.h"

s21_decimal parseDecimal(char *value)
{
    int n = 0, i = 0, size = 32, first = 1, flag = 0;
    long int val = parseLongInt(value, &n, &flag);
    s21_decimal res;
    char revers[RES_SIZE] = "";
    longIntIoBinaryChar(val, revers);
    printf("%s\n", revers);
    char *str = strtok(revers, ".");
    int k = 2;
    char num[RES_SIZE] = "";
    int * tmp;
    while (str != NULL)
    {
        res.bits[k] = (int) strtol(str, NULL, 2);
        printf("%u\n", res.bits[k]);
        printf("str = %s\n",itoa(res.bits[k], 2));
        strcat(num, itoa(res.bits[k], 2));
        str = strtok(NULL, ".");
        k--;
    }
    char special[RES_SIZE] = "";
    size_t t = 0; first = 1;
    for (t = 0; t < 32; t++) {
        if (t < 16 || (t > 23 && t < 31)) special[t] = '0';
        else if (t == 31) special[t] = '0' + flag;
        else {
            if (first) {
                int x = n;
                while (x != 1) {
                    special[t] = x % 2 + '0';
                    x /= 2;
                    t++;
                }
                special[t] = '0' + x;
                first = 0;
            } else {
                special[t] = '0';
            }
        }
    }
    special[t] = '\0';
    char rev[RES_SIZE] = "";
    size_t l = strlen(special);
    for(int i = 0; i < l; i++) {
        rev[i] = special[l - 1 - i];
    }
    rev[l] = '\0';
    res.bits[3] = (int) strtol(rev, NULL, 2);
    printf("flag = %d\nn = %d\nspecial = %s\nbits[3] = %s\n",flag, n, special, itoa(res.bits[3], 2));
    printf("full num = %s\n",num);
    return res;
}

char* itoa(unsigned int val, int base){
	
	static char buf[34] = {0};
	
	int i = 32;
	
	for(; val && i ; --i, val /= base)
	
		buf[i] = "0123456789abcdef"[val % base];
	
	return &buf[i+1];
	
}

void longIntIoBinaryChar(long int val, char* revers) {
    int n = 0, i = 0, size = 32, first = 1;
    char count[RES_SIZE] = "";
    for (int k = 0; k < 3; k++)
    {
        for (int j = 0; j < 32; j++)
        {
            if (val != 1)
            {
                count[i] = val % 2 + '0';
                val /= 2;
                i++;
            }
            else if (first)
            {
                count[i] = val + '0';
                first = 0;
                i++;
            }
            else
            {
                count[i] = '0';
                i++;
            }
        }
       // count[i] = 'b';
        //i++;
        //count[i] = '0';
        //i++;
        if (k != 2)
        {
            count[i] = '.';
            i++;
        }
        else
        {
            count[i] = '\0';
        }
    }
    size_t l = strlen(count);
    for(int i = 0; i < l; i++) {
        revers[i] = count[l - 1 - i];
    }
    revers[l] = '\0';
}

long int parseLongInt(char *value, int *n, int *flag)
{
    int is_double = 0, j = 0, start = 0;
    char tmp[RES_SIZE] = "";

    switch (value[0]) {
        case '+': *flag = 0; start = 1; break;
        case '-': *flag = 1; start = 1; break;
        default: *flag = 0; break;
    }
    for (size_t i = start; value[i] != '\0'; i++)
    {
        if (is_double)
            *n += 1;
        if (value[i] == '.' || value[i] == ',')
        {
            is_double = 1;
        }
        else
        {
            tmp[j] = value[i];
            j++;
        }
    }
    tmp[j] = '\0';
    long int res = atol(tmp);
    return res;
}

char *parseChar(s21_decimal value)
{
    char tmp[RES_SIZE] = "";
    //for (size_t i = 0; i < sizeof(value.bits[0])/sizeof(value.bits[0][0]); i++) {
      //  tmp[i] = value.bits[0][i] + '0';
    //}
   // itoa(value.bits[0], tmp, 2);
    printf("str = %s\n", tmp);
    // value.bits[0];
    return "";
}