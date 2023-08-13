#include <string>
#include <vector>

using namespace std;

int solution(string binomial) {
    int answer = 0;
    string first="";
    string second="";
    int size = binomial.size();
    
    for(int i=0; i<size; ++i)
    {
        if(binomial[i] == '+' || binomial[i] == '-' || binomial[i] == '*')
        {
            first = binomial.substr(0, i-1);
            second = binomial.substr(i+1);
            
            int ifirst = stoi(first);            
            int isecond = stoi(second);
            
            if (binomial[i] == '+')
                answer=ifirst+isecond;
            else if (binomial[i] == '-')
                answer=ifirst-isecond;
            else if (binomial[i] == '*')
                answer=ifirst*isecond;
            
            break;
        }
    }
    
    return answer;
}