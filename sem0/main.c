#include <stdio.h>

int main(void) {
    int a;
    a = 2 //* */
        +2;

    int j = 2;
    int *i = &j;
    int b;
    b = 2 /*i // */
        ;

    printf("%d\n", a);
    printf("%d\n", b);
    return 0;
}
