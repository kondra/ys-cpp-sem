#include <iostream>

int pow(int n, int a)
{
    if (n == 0)
        return 1;
    if (n & 1)
        return a * pow(n - 1, a);
    else
        return pow(n >> 1, a * a);
}

int main()
{
    int a, n, res;
    std::cin >> a >> n;
    std::cout << pow(n, a);
    return 0;
}
