#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> str_list) {
    vector<string> answer;
    int lindex = -1;
    int rindex = -1;
    
    for (int i=0; i < str_list.size(); i++)
    {
        if (str_list[i] == "l")
        {
            lindex = i;
            break;
        }
        else if (str_list[i] == "r")
        {
            rindex = i;
            break;
        }
    }
    
    if (lindex != -1 && rindex == -1)
    {
        answer.insert(answer.begin(), str_list.begin(), str_list.begin() + lindex);
    }
    else if (lindex == -1 && rindex != -1)
    {
        answer.insert(answer.begin(), str_list.begin() + rindex + 1, str_list.end());
    }
    
    return answer;
}