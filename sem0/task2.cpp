#include <iostream>

bool getBit(int data, int pos) {
    return data & (1 << pos);
}

void setBit(int * const data, int pos, int value) {
    int mask = 1 << pos;
    if (value)
        *data |= mask;
    else
        *data &= ~mask;
}

int main() 
{
    int t = 3;
    setBit(&t, 2, 1);
    setBit(&t, 2, 0);
    std::cout << getBit(t, 2) << std::endl << getBit(t, 1) << std::endl << getBit(t, 0);
    return 0;
}
