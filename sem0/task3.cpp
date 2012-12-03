#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using std::string;
using std::vector;
using std::cin;
using std::cout;

bool comp(const string& s1, const string& s2) {
    int i, j;
    int l1 = s1.length();
    int l2 = s2.length();
    for (i = 0; i < l1; ++i)
        if (s1[i] != '0')
            break;
    for (j = 0; j < l2; ++j)
        if (s2[j] != '0')
            break;
    if (l1 - i < l2 - j)
        return true;
    if (l1 - i > l2 - j)
        return false;
    for (; i < l1 && j < l2; ++i, ++j) {
        if (s1[i] < s2[j])
            return true;
        if (s1[i] > s2[j])
            return false;
    }
    return true;
}

int main()
{
    vector<string> arr;
    string tmp;
    while (!cin.eof()) {
        cin >> tmp;
        arr.push_back(tmp);
    }
    arr.pop_back();
    std::sort(arr.begin(), arr.end(), comp);
    for (int i = 0; i < arr.size(); ++i) {
        cout << arr[i] << std::endl;
    }
    return 0;
}
