#include <string>
#include <vector>

using namespace std;

int solution(vector<int> number) {
    int answer = 0;
    
    // 3명의 번호를 더 했을 때 0이 되어야 삼총사
    for(int i=0; i<number.size()-2; i++)
        for(int j=i+1; j<number.size()-1; j++)
            for(int k=j+1; k<number.size(); k++)
                if(number[i]+number[j]+number[k]==0) answer++;
    
    return answer;
}