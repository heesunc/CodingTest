#include <string>
#include <vector>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    string str = "";
    string ans = "";

    cin >> str;

    for (char c : str)
    {
        if (islower(c))
            ans += toupper(c);
        else if (isupper(c))
            ans += tolower(c);
    }

    cout << ans << '\n';

    return 0;
}