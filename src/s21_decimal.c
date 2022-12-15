#include "s21_decimal.h"

int s21_is_less(s21_decimal value_1, s21_decimal value_2) {
    int res = 0;
    int flag1 = 0, sign1 = 0, flag2 = 0, sign2 = 0;
    char num1[RES_SIZE] = "";
    char num2[RES_SIZE] = "";
    if (get_bin_char_flag_and_sign(value_1, num1, &flag1, &sign1) && get_bin_char_flag_and_sign(value_2, num2, &flag2, &sign2)) {
    //format_num_for_operation(value_1, value_2, num1, num2, &flag1, &flag2, &sign1, &sign2);
        //reverse(num1);
        //reverse(num2);
        int s1 = (int) strlen(num1);
        int s2 = (int) strlen(num2);
        res = (flag1 > flag2) ? 1 : 0;
        if (flag1 == flag2) {
            res = (s1 < s2) ? pow(0, flag1) : flag1;
            if (s1 == s2) {
                res = 0;
                for (int i = s1; i >= 0; i--) {
                    if (num1[i] < num2[i]) {
                        res = 1;
                    }
                    if (num1[i] != num2[i]) break;
                }
            }
        }
    printf("\nn1 = %s n2 = %s\n", num1, num2);
    }
    return res;
}

int bin_char_to_int(char* binNum, int flag, int sign) {
    int val = (int) bin_char_to_float(binNum, flag, sign);
    return val;
}

float bin_char_to_float(char* binNum, int flag, int sign) {
    float val = 0;
    for (size_t i = 0; i < strlen(binNum); i++) {
        val += (binNum[i] - '0') * pow(2, i);
    }
    switch(flag) {
        case 1: val *= -1; break;
        case 0: break;
        default: break; 
    }
    val /= pow(10, sign);
    return val;
}

int get_bin_char_flag_and_sign(s21_decimal src, char* num, int *flag, int *sign) {
    int no_error = 1;
    from_decimal_to_bin_char(src, num);
    getFlagAndPoint(src, flag, sign);
    //printf("\nnum = %s\nflag = %d\npoint = %d\n", num, *flag, *sign);
    //reverse(num);
    return no_error;
}

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
    char num[RES_SIZE] = "";
    int flag = 0, sign = 0;
    int no_error = get_bin_char_flag_and_sign(src, num, &flag, &sign);
    *dst = bin_char_to_int(num, flag, sign);
    return no_error;
}

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
    char num[RES_SIZE] = "";
    int flag = 0, sign = 0;
    int no_error = get_bin_char_flag_and_sign(src, num, &flag, &sign);
    *dst = bin_char_to_float(num, flag, sign);
    return no_error;
}

int s21_from_bin_char_to_decimal(char* src, int flag, int sign, s21_decimal *dst) {
    int no_error = 1;
    reverse(src);
    *dst = get_result(src, flag, sign);
    return no_error;
}

s21_decimal set_result(char * res, int flag, int sign) {
    s21_decimal d = set_bits(res);
    char special[RES_SIZE] = "";
    getBits3Char(special, flag, sign);
    d.bits[3] = (int) strtol(special, NULL, 2);
    return d;
}

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
    int no_error = 1;
    char str[RES_SIZE] = "";
    sprintf(str, "%f", src);
    int sign = 0, flag = 0;
    set_sign_and_flag(str, &sign, &flag);
    int val = (int) (src * pow(10, sign));
    char res[RES_SIZE] = "";
    longIntIoBinaryChar((long int)val, res);
    //printf("res = %s\nsrc = %f\nstr = %s\nsign! = %d\nflag = %d\n", res, src, str, sign, flag);
    *dst = set_result(res, flag, sign);
    return no_error;
}

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
    int no_error = 1;
    char str[RES_SIZE] = "";
    sprintf(str, "%d", src);
    int sign = 0, flag = 0;
    set_sign_and_flag(str, &sign, &flag);
    char res[RES_SIZE] = "";
    longIntIoBinaryChar((long int)src, res);
    //printf("res = %s\nsrc = %d\nstr = %s\nsign! = %d\nflag = %d\n", res, src, str, sign, flag);
    *dst = set_result(res, flag, sign);
    return no_error;
}

void set_sign_and_flag(char* val, int* sign, int *flag) {
    int is_float = 0, empty = 1, start = 0;
    switch (val[0]) {
        case '+': *flag = 0; start = 1; break;
        case '-': *flag = 1; start = 1; break;
        default: *flag = 0; break;
    }
    for (size_t i = (size_t)start; i < strlen(val); i++) {
        if (is_float) {
            *sign += 1;
        }
        if (val[i] == '.' || val[i] == ',') {
            is_float = 1;
        }
    }
    for (int i = (int)strlen(val) - 1; i >= start; i--) {
        if (val[i] != '0') {
            empty = 0;
        }
        if (empty) {
            if (*sign > 0) *sign -= 1;
        }
    }
}

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
    printf("\ns1 = %d\ns2 = %d\n", size1, size2);
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

void sub(char* num1, char *num2, char * res) {
    int count = 0, j = 0, tmp = 0, val = 0;
    for (int i = (int)strlen(num1) - 1; i >= 0; i--) {
            if (count == 32) {
                count = 0;
                res[j++] = '.';
            }
            val = (num1[i] - '0') - (num2[i] - '0') - tmp;
            if (val >= 0) {
                res[j++] = val + '0';
                tmp = 0;
            } else if (val == -1) {
                res[j++] = '1';
                tmp = 1;
            } else {
                res[j++] = '0';
                tmp = 1;
            }
            count++;
        }
    res[j++] = '\0';
}

void div_(char* num1, char *num2, char * res) {
    printf("\nNUM1 = %s, NUM2 = %s\n", num1, num2);
    int j = 0, tmp = 0, val = 0, t = 0;
    int count = 0, n = 0, final = 0;
    char tmp1[RES_SIZE] = "";
    char tmp2[RES_SIZE] = "";
    char tmp3[RES_SIZE] = "";
    int s1 = (int)strlen(num1);
    int s2 = (int)strlen(num2);
    //strcat(num1,)
    //printf("\nS1 = %d, S2 = %d\n", s1, s2);
    while (!final)
    {
        for (int k = t; k < s2; k++) {
            if (1) // tmp3 меньше num2 
            {
                tmp3[k] = num1[k];
                t++;
            } else {
                k++;
                tmp3[k] = '\0';
                sub(tmp3, num2, tmp2);
                if (1) // tmp2 < num2 
                {

                }
            }
        }
        if (1) // tmp3 < num2 
        {

        }
    }
    //printf("\ntmp = %s\n", tmp1);
    //tmp1[j++] = '\0';
    reverse(tmp1);
    strcpy(res, tmp1);
}

void mul(char* num1, char *num2, char * res) {
    int j = 0, tmp = 0, val = 0;
    int count = 0, n = 0;
    char tmp1[RES_SIZE] = "";
    char tmp2[RES_SIZE] = "";
    for (int k = (int)strlen(num2) - 1; k >= 0; k--) {
        int t = 0;
        for (int i = (int)strlen(num1) - 1; i >= 0; i--) {
            if (count == 32) {
                count = 0;
                res[j++] = '.';
            }
            val = (num1[i] - '0') * (num2[k] - '0');
            if (k == (int)strlen(num2) - 1) {
                tmp1[t++] = val + '0';
            //printf("\nnum1[%d] = %c\nnum2[%d] = %c\n",i, num1[i], i, num2[i]);
            } else {
                tmp2[t++] = val + '0';
            }
            count++;
        }
        if (k != (int)strlen(num2) - 1) {
            reverse(tmp1);
            reverse(tmp2);
            char tmp3[RES_SIZE] = "";
            char tmp4[RES_SIZE] = "";
            strcat(tmp3, tmp2);
            for (int i = 0; i < n; i++) {
                tmp3[t++] = '0';
            }
            tmp3[t++] = '\0';
            strcat(tmp4, tmp1);
            if (strlen(tmp3) > strlen(tmp4)) addZeroBeforeNumber(tmp4, (int)strlen(tmp3), (int)strlen(tmp4));
            //printf("\ntmp1 = %s\ntmp2 = %s\n\ntmp4 = %s\ntmp3 = %s\n",tmp1, tmp2, tmp4, tmp3);
            sum(tmp4, tmp3, res);
            reverse(res);
            //printf("\nres = %s\n", res);
            strcpy(tmp1, res);
            reverse(tmp1);
        } else {

        //printf("\ntmp1 = %s\n", tmp1);
        }
        n++;
    }
    //printf("\ntmp = %s\n", tmp1);
    //tmp1[j++] = '\0';
   // reverse(tmp1);
    strcpy(res, tmp1);
}

void sum(char* num1, char *num2, char * res) {
    int j = 0, tmp = 0, val = 0;
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
}

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    int no_error = 1;
    char num1[RES_SIZE] = "";
    char num2[RES_SIZE] = "";
    int sign1 = 0, sign2 = 0, flag1 = 0, flag2 = 0;
    format_num_for_operation(value_1, value_2, num1, num2, &flag1, &flag2, &sign1, &sign2);
    char res[RES_SIZE] = ""; 
    sub(num1, num2, res);
    *result = get_result(res, flag1, sign1);
    return no_error;
}

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    int no_error = 1;
    char num1[RES_SIZE] = "";
    char num2[RES_SIZE] = "";
    int sign1 = 0, sign2 = 0, flag1 = 0, flag2 = 0;
    format_num_for_operation(value_1, value_2, num1, num2, &flag1, &flag2, &sign1, &sign2);
    char res[RES_SIZE] = ""; 
    mul(num1, num2, res);
    *result = get_result(res, flag1, sign1);
    return no_error;
}

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    int no_error = 1;
    char num1[RES_SIZE] = "";
    char num2[RES_SIZE] = "";
    int sign1 = 0, sign2 = 0, flag1 = 0, flag2 = 0;
    format_num_for_operation(value_1, value_2, num1, num2, &flag1, &flag2, &sign1, &sign2);
    char res[RES_SIZE] = ""; 
    div_(num1, num2, res);
    *result = get_result(res, flag1, sign1);
    return no_error;
}

void from_decimal_to_bin_char(s21_decimal src, char* num) {
    for (int i = 2; i >= 0; i--) {
        strcat(num, itoa(src.bits[i], 2));
    }
}

void format_num_for_operation(s21_decimal value_1, s21_decimal value_2, char* num1, char* num2, int *flag1, int *flag2, int *sign1, int *sign2) {
    //reverse(num1);
   // reverse(num2);
    get_bin_char_flag_and_sign(value_1, num1, flag1, sign1);
    get_bin_char_flag_and_sign(value_2, num2, flag2, sign2);
    printf("\nnum1 = %s,\nnum2 = %s\n", num1, num2);
    if (*sign1 != *sign2) {
        (*sign1 > *sign2)? addZeroAfterSign(num2, *sign1, sign2) : addZeroAfterSign(num1, *sign2, sign1);
    }
    int size1 = (int) strlen(num1);
    int size2 = (int) strlen(num2);
    if (size1 != size2) {
        (size1 > size2)? addZeroBeforeNumber(num2, size1, size2) : addZeroBeforeNumber(num1, size2, size1);
    }
    printf("\nformatted num1 = %s -> %d, num2 = %s -> %d\n", num1, (int) strtol(num1, NULL, 2), num2, (int) strtol(num2, NULL, 2));
}

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    int no_error = 1;
    char num1[RES_SIZE] = "";
    char num2[RES_SIZE] = "";
    int sign1 = 0, sign2 = 0, flag1 = 0, flag2 = 0;
    format_num_for_operation(value_1, value_2, num1, num2, &flag1, &flag2, &sign1, &sign2);
    char res[RES_SIZE] = ""; 
    sum(num1, num2, res);
    *result = get_result(res, flag1, sign1);
    return no_error;
}

s21_decimal get_result(char * binChar, int flag, int sign) {
    char temp[RES_SIZE] = "";
    get_res_char(binChar);
    s21_decimal d = set_bits(binChar);
    char special[RES_SIZE] = "";
    getBits3Char(special, flag, sign);
    d.bits[3] = (int) strtol(special, NULL, 2);
    return d;
}

void print_s21_decimal(s21_decimal dec) {
    for (int i = 3; i >= 0; i--) {
        if (dec.bits[i]) printf("\nbits[%d] = %s -> %d\n", i, itoa(dec.bits[i], 2), (int) strtol(itoa(dec.bits[i], 2), NULL, 2));
    }
}

void getBits3Char(char* special, int flag, int sign) {
    size_t t = 0; 
    int first = 1;
    for (t = 0; t < 32; t++) {
        if (t < 16 || (t > 23 && t < 31)) special[t] = '0';
        else if (t == 31) special[t] = '0' + flag;
        else {
            if (first) {
                int x = sign;
                if (sign != 0) {
                while (x != 1) {
                    special[t] = x % 2 + '0';
                    x /= 2;
                    t++;
                }
                }
                special[t] = '0' + x;
                first = 0;
            } else {
                special[t] = '0';
            }
        }
    }
    special[t] = '\0';
    reverse(special);
}

s21_decimal set_bits(char* value) {
    s21_decimal res;
    char *str = strtok(value, ".");
    int k = 2;
    char num[RES_SIZE] = "";
    int * tmp;
    while (str != NULL)
    {
        res.bits[k] = (int) strtol(str, NULL, 2);
        //printf("%u\n", res.bits[k]);
        //printf("str = %s\n",itoa(res.bits[k], 2));
        strcat(num, itoa(res.bits[k], 2));
        str = strtok(NULL, ".");
        k--;
    }
    return res;
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
    reverse(temp);
    strcpy(res, temp);
}

void reverse(char *value) {
    char rev[RES_SIZE] = "";
    size_t l = strlen(value);
    for(int i = 0; i < l; i++) {
        rev[i] = value[l - 1 - i];
    }
    rev[l] = '\0';
    strcpy(value, rev);
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
    if (val < 0) val *= -1;
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
    for (size_t i = 0; i < strlen(N); i++) { //rewr
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