#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<string> order) {
    int answer = 0;
    string ame = "americano";
    string latte = "cafelatte";
    string any = "anything";
    
    // 아메리카노, 아무거나 4500, 카페라떼 5000
    for(int i=0; i<order.size(); i++)
    {
        if(order[i].find(ame) != string::npos || order[i].find(any) != string::npos)
            answer += 4500;
        else if(order[i].find(latte) != string::npos)
            answer += 5000;
    }    
    
    return answer;
}