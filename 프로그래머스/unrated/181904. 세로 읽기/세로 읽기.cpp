#include <string>
#include <vector>

using namespace std;

string solution(string my_string, int m, int c) {
    string answer = "";
    vector<string> rows;
    int length = my_string.length();
    
    // 문자열을 m 글자씩 나누어서 rows 벡터에 저장
    for (int i=0; i < length; i+=m)
    {
        string row = my_string.substr(i, m);
        rows.push_back(row);
    }
    
    // c번째 열의 글자들을 결과 문자열에 추가
    for (const auto& row : rows)
    {
        if ( c - 1 < row.length())
        {
            answer += row[c-1];
        }
    }
    
    return answer;
}