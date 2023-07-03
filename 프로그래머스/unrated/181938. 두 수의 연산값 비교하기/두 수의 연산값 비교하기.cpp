#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {
    int answer = 0;
    
    string str_a = to_string(a);
    string str_b = to_string(b);
    
    string strab = str_a + str_b;
    
    if ( stoi(strab) > 2*a*b)
    {
        answer = stoi(strab);
    }
    else
    {
        answer = 2*a*b;
    }
    
    return answer;
}