#include <string>
#include <vector>

using namespace std;

int solution(string my_string, string is_prefix) {
    int answer = 0;
    
    for(int i=0; i < my_string.size(); i++)
    {
        string str = my_string.substr(0,i);
        if (str == is_prefix)
        {
            answer = 1;
        }
    }
    
    return answer;
}