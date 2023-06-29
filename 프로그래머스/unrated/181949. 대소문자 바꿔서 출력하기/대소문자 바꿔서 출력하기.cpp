#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string str;
    cin >> str;
    
    for(int i = 0; i < str.size(); i++)
    {
        // 만약 str[i]가 대문자라면?
        if ('A' <= str[i] && str[i] <= 'Z')
        {
            // 소문자로
            str[i] += 32;
        }
        // 소문자라면?
        else if ('a' <= str[i] && str[i] <= 'z')
        {
            // 대문자로
            str[i] -= 32;
        }
    }
    // 출력
    cout << str << endl;
    
    return 0;
}