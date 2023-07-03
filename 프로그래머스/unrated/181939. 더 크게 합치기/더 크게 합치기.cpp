#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {
    int answer = 0;
    string str_a = to_string(a);
    string str_b = to_string(b);
    
    string a_b = str_a + str_b;
    string b_a = str_b + str_a;
    
    if ( a_b > b_a )
    {
        answer = stoi(a_b);
    }
    else
    {
        answer = stoi(b_a);
    }
    
    return answer;
}