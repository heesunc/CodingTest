#include <string>
#include <vector>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n = 0;
    string numbers = "";

    cin >> n;
    cin >> numbers;

    int sum = 0;

    for (char c : numbers)
    {
        sum += c - '0';
    }

    cout << sum << endl;

    return 0;
}