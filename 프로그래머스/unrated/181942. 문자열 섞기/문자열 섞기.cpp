#include <string>
#include <vector>

using namespace std;

string solution(string str1, string str2) {
    string answer = "";
    
    for (int i =0; i < str1.length(); i++) // str1과 str2의 길이는 같으니..
    {
        answer += str1[i];
        answer += str2[i];
    }
    return answer;
}