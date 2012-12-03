#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int strlen(const char * str) {
    int l = 0;
    while (*str++)
        ++l;
    return l;
}

char * strcat(char * destination, const char * source) {
    char *p = destination;
    while (*p++);
    --p;
    while (*p++ = *source++);
    return destination;
}

char * strrev2(char * destination, const char * source) {
    int l = strlen(source);
    for (int i = 0; i < l; ++i)
        *(destination + i) = *(source - i + l - 1);
    return destination;
}

char * strrev(char * destination, const char * source) {
    const char *p = source;
    while (*p++)
        destination++;
    --destination;
    *--destination = 0;
    while (*source && (*--destination = *source++));
    return destination;
    
}

int strcmp(const char * str1, const char * str2) {
    while (*str1 && *str2 && *str1 == *str2) {
        ++str1;
        ++str2;
    }
    return *str1 - *str2;
}

int atoi(const char * str) {
    int res = 0, sgn = 1;
    if (*str == '-') {
        sgn = -1;
        ++str;
    } else if (*str == '+') {
        sgn = 1;
        ++str;
    }
    while (*str) {
        res = res*10 + *str - '0';
        ++str;
    }
    return res * sgn;
}

char * itoa(unsigned int value, char * str, unsigned int base) {
    char buf[65];
    char *p = buf;
    if (value == 0) {
        char *p = str;
        *str++ = '0';
        *str = 0;
        return p;
    }
    while (value > 0) {
        unsigned int digit = value % base;
        if (digit > 9)
            *p++ = digit + 'a' - 10;
        else
            *p++ = digit + '0';
        value /= base;
    }
    *p = 0;
    int l = strlen(buf);
    int i;
    for (i = 0; i < l; i++)
        *(str + i) = *(buf + l - 1 - i);
    *(str + i) = 0;
    return str;
}

int main() {
//    cout << strlen("hello") << endl;
    char *dst, *src;
    dst = new char[100];
    src = new char[100];
/*  
    cin >> dst >> src;
    cout << strcat(dst, src) << endl;
    cin >> src;
    cout << strrev(dst, src) << endl;
    cout << strcmp("abc", "abd") << endl;
    cout << strcmp("abc", "abc") << endl;
    cout << strcmp("bbc", "abc") << endl;
    cout << strcmp("bbc", "abc234") << endl;
    cout << strcmp("abc234kjlkjlkj", "abc234") << endl;
    cout << atoi("256") << endl;
    cout << atoi("-10256") << endl;
    cout << atoi("2") << endl;
    cout << atoi("0") << endl;
    cout << atoi("10") << endl;
    cout << atoi("-100500") << endl;
*/
//    cout << strrev2(dst, "12345") << endl;
    cout << itoa(100500, src, 10) << endl;
    cout << itoa(1024, src, 2) << endl;
    cout << itoa(1024, src, 16) << endl;
    cout << itoa(100500, src, 16) << endl;
    cout << itoa(7, src, 2) << endl;
    cout << itoa(7, src, 16) << endl;
    cout << itoa(11, src, 16) << endl;
    cout << itoa(0, src, 16) << endl;
    delete [] dst;
    delete [] src;
    return 0;
}
