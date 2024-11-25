#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#define MIN_BASE 2
#define MAX_BASE 16
#define MAX_LEN_NUM 14
#define MAX_CAP_CHR 7
#define MAX_ANS_INT_LEN 50

int CharToDigit(char chr) {
    if (chr <= '9') {
        return chr - '0';
    }
    else if (chr >= 'a') {
        return chr - 'a' + 10;
    }
    else {
        return chr - 'A' + 10;
    }
}

char DigitToChar(int intnum) {
    if (intnum <= 9 && intnum >= 0) {
        return intnum + '0';
    }
    else {
        return intnum + 'a' - 10;
    }
}

long long int IntPartValue(int point_index, int lenght_num, int base1, char num[]) {
    if (point_index == -1) {
        point_index = lenght_num;
    }
    long long ans_int = 0;
    for (int i = 0; i < point_index; ++i) {
        int chr_i = num[i];
        ans_int += CharToDigit(chr_i) * pow(base1, point_index - i - 1);
    }
    return ans_int;
}

void PrintIntPart(long long ans_int, int base2) {
    if (ans_int == 0) {
        printf("0");
    }
    int ans_int_base2[MAX_ANS_INT_LEN];
    int count = 0;
    while (ans_int > 0) {
        ans_int_base2[count] = ans_int % base2;
        ans_int /= base2;
        count++;
    }
    for (int i = count - 1; i >= 0; --i) {
        printf("%c", DigitToChar(ans_int_base2[i]));
    }
}

long double FloatPartValue(int point_index, int lenght_num, char num[], int base1) {
    if (point_index == -1) {
        point_index = lenght_num;
    }
    long double ans_float = 0;
    for (int i = point_index + 1; i < lenght_num; ++i) {
        int chr_i = num[i];
        ans_float += CharToDigit(chr_i) * pow(base1, -(i - point_index));
    }
    return ans_float;
}

void PrintFloatPart(double ans_float, int base2) {
    int count = 0;
    while (ans_float > 0 && count < 13) {
        ans_float *= base2;
        int ans_float_base2 = ans_float;
        printf("%c", DigitToChar(ans_float_base2));
        ans_float -= ans_float_base2;
        ++count;
    }
}

int main(void) {

    int base1, base2;
    if (scanf("%d%d", &base1, &base2) != 2 || base1 < MIN_BASE || base2 < MIN_BASE || base1 > MAX_BASE || base2 > MAX_BASE) {
        printf("bad input");
        return 0;
    }

    char num[MAX_LEN_NUM];
    if (scanf("%13s", num) != 1) {
        printf("bad input");
        return 0;
    }

    int count_cap_chr = 0, valid_chr[MAX_BASE + 1], valid_chr_cap[MAX_CAP_CHR];
    for (int i = 0; i < base1 + 1; ++i) {
        if (i == base1) {
            valid_chr[i] = '.';
            break;
        }
        else if (i > 9) {
            valid_chr_cap[count_cap_chr] = 'A' + i - 10;
            ++count_cap_chr;
        }
        valid_chr[i] = DigitToChar(i);
    }

    size_t len = strlen(num);
    int lenght_num = len, point_index = -1;
    for (int i = 0; i < lenght_num; ++i) {
        int chr_i = num[i];
        if (chr_i == '.') {
            if (point_index != -1 || i == lenght_num - 1 || i == 0) {
                printf("bad input");
                return 0;
            }
            else {
                point_index = i;
            }
        }
        int count = 0;
        for (int j = 0; j < 17; ++j) {
            if (chr_i == valid_chr[j]) {
                ++count;
            }
        }
        for (int j = 0; j < 7; ++j) {
            if (chr_i == valid_chr_cap[j]) {
                ++count;
            }
        }
        if (count == 0) {
            printf("bad input");
            return 0;
        }
    }

    int bool_point = 1;
    if (point_index == -1) {
        bool_point = 0;
    }

    long long ans_int = IntPartValue(point_index, lenght_num, base1, num);
    PrintIntPart(ans_int, base2);
    if (bool_point == 1 && point_index != lenght_num - 1) {
        printf(".");
        long double ans_float = FloatPartValue(point_index, lenght_num, num, base1);
        PrintFloatPart(ans_float, base2);
    }
    return EXIT_SUCCESS;
}
