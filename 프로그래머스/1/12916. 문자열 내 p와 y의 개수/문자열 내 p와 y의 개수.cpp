#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    int p = 0;
    int y = 0;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'p' || s[i] == 'P')
            p += 1;
        else if (s[i] == 'y' || s[i] == 'Y')
            y += 1;
    }

    if (p == y)
        answer = true;
    else if (p != y)
        answer = false;
    else
        answer = true;

    return answer;
}