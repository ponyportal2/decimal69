#include "s21_decimal.h"

void addZeroAfterSign(char* var, int sign1, int *sign2) {
    int dif = sign1 - *sign2;
    int start_size = (int)strlen(var); int i = 0;
    for (i = start_size; i < start_size + dif; i++) {
        var[i] = '0';
    }
    var[i] = '\0';
    *sign2 = sign1;
}

void addZeroBeforeNumber(char* var, int size1, int size2) {
    char res[RES_SIZE] = "";
    int dif = size1 - size2;
    int i = 0;
    res[size1] = '\0';
    for (i = 0; i < dif; i++) {
        res[i] = '0';
    }
    for (i = dif; i < size1; i++) {
        res[i] = var[i - dif];
    }
    strncpy(var, res, size1);
}

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    
}

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    int no_error = 1;
    char num1[RES_SIZE] = "";
    char num2[RES_SIZE] = "";
    for (int i = 2; i >= 0; i--) {
        strcat(num1, itoa(value_1.bits[i], 2));
        strcat(num2, itoa(value_2.bits[i], 2));
    }
    int sign1 = 0, sign2 = 0, flag1 = 0, flag2 = 0;
    getFlagAndPoint(value_1, &flag1, &sign1);
    getFlagAndPoint(value_2, &flag2, &sign2);
    if (sign1 != sign2) {
        (sign1 > sign2)? addZeroAfterSign(num2, sign1, &sign2) : addZeroAfterSign(num1, sign2, &sign1);
    }
    int size1 = (int) strlen(num1);
    int size2 = (int) strlen(num2);
    if (size1 != size2) {
        (size1 > size2)? addZeroBeforeNumber(num2, size1, size2) : addZeroBeforeNumber(num1, size2, size1);
    }
    printf("\nnum1 = %s,\nnum2 = %s\n", num1, num2);
    char res[RES_SIZE] = ""; int j = 0, tmp = 0, val = 0;
    int count = 0;
        for (int i = (int)strlen(num1) - 1; i >= 0; i--) {
            if (count == 32) {
                count = 0;
                res[j++] = '.';
            }
            val = (num1[i] - '0') + (num2[i] - '0') + tmp;
            if (val < 2) {
                res[j++] = val + '0';
                tmp = 0;
            } else if (val == 2) {
                res[j++] = '0';
                tmp = 1;
            } else {
                res[j++] = '1';
                tmp = 1;
            }
            count++;
        }
    if (tmp == 1) res[j++] = '1';
    res[j++] = '\0';
    *result = get_result(res, flag1, sign1);
    return no_error;
}

s21_decimal get_result(char * res, int flag, int sign) {
    char temp[RES_SIZE] = "";
    get_res_char(res);
    printf("\nrev = %s\n", res);
    s21_decimal d;
    return d; 
}

void set_bits(s21_decimal res, char* value) {
    char *str = strtok(value, ".");
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
}

void get_res_char(char * res) {
    char temp[RES_SIZE] = "";
    int i = 0, j = 0;
    for (int k = 0; k < 3; k++) {
        for (int t = 0; t < 32; t++) {
            if (j < (int)strlen(res)) {
                temp[i] = res[j]; i++; j++;
            } else {
                temp[i] = '0'; i++;
            }
        }
        if (k != 2)
        {
            temp[i] = '.';
            i++;
        }
        else
        {
            temp[i] = '\0';
        }
    }
    char rev[RES_SIZE] = "";
    reverse(temp, rev);
    strcpy(res, rev);
}

void reverse(char *value, char* rev) {
    size_t l = strlen(value);
    for(int i = 0; i < l; i++) {
        rev[i] = value[l - 1 - i];
    }
    rev[l] = '\0';
}

s21_decimal parseFromBinToDecimal(char *value) {
    int n = 0, i = 0, size = 32, first = 1, flag = 0;
    s21_decimal res;
    char revers[RES_SIZE] = "";
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
    printf("flag = %d\nn = %d\nbits[3] = %s\n",flag, n, itoa(res.bits[3], 2));
    //printf("full num = %s\n",num);
    return res;
}

s21_decimal parseDecimal(char *value)
{
    int n = 0, i = 0, size = 32, first = 1, flag = 0;
    long int val = parseLongInt(value, &n, &flag);
    //long long unsigned int v = 64294967296429496729611111111;
   // printf("\nlong int = %lu\n", strtoul(value, NULL, 16));
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
    printf("flag = %d\nn = %d\nbits[3] = %s\n",flag, n, itoa(res.bits[3], 2));
    //printf("full num = %s\n",num);
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

void getFlagAndPoint(s21_decimal value, int* flag, int* point) {
    char special[RES_SIZE] = "";
    char N[RES_SIZE] = "";
    strcat(special, itoa(value.bits[3], 2));
    size_t size = strlen(special) - 17;
    int j = 0, first = 1, end = 0;
    if (special[0] == '1' && strlen(special) == 32) {*flag = 1;}
    for (int i = (int)size; i >= 0; i--) {
        if (special[i] == '0' && !first) {
            end = 1;
        }
        if (!end) {
            if (special[i] == '1' && first) first = 0;
            N[j] = special[i]; j++;
        }
    }
    N[j] = '\0';
    for (size_t i = 0; i < strlen(N); i++) {
        *point += (N[i] - '0') * pow(2, i);
    }
}

char *parseChar(s21_decimal value)
{
    char num[RES_SIZE] = "";
    char special[RES_SIZE] = "";
    char N[RES_SIZE] = "";
    for (int i = 2; i >= 0; i--) {
        strcat(num, itoa(value.bits[i], 2));
    }
    strcat(special, itoa(value.bits[3], 2));
    printf("full num = %s\n", num);
    size_t size = strlen(special) - 17;
    int flag = 0, n = 0, j = 0, first = 1, end = 0;
    if (special[0] == '1' && strlen(special) == 32) flag = 1;
    for (int i = (int)size; i >= 0; i--) { //can not use size_t here
        if (special[i] == '0' && !first) {
            end = 1;
        }
        if (!end) {
            if (special[i] == '1' && first) first = 0;
            N[j] = special[i]; j++;
        }
    }
    N[j] = '\0';
    long int res = 0;
    for (size_t i = 0; i < strlen(N); i++) {
        n += (N[i] - '0') * pow(2, i);
    }
    j = 0;
    for (int i = (int)strlen(num) - 1; i >= 0; i--) {
        res += (num[j] - '0') * powl(2, i); j++;
    }
    printf("strlen = %ld, special = %s\nlen = %ld\nN = %s\nflag = %d\nn = %d\nres = %ld\n", 
    strlen(num), special, size, N, flag, n, res);
    return "";
}