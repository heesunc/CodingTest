#include <string>
#include <vector>
#include <algorithm> // sort를 위해

using namespace std;

int solution(vector<int> people, int limit) 
{    
    // 오름차순으로 정렬
    sort(people.begin(), people.end());
    
    int answer = 0, idx = 0; // idx -> 맨 앞사람
    
    // 2명 검사
    while(people.size() > idx)
    {
        int back = people.back(); // 맨 뒷사람 (최솟값)
        people.pop_back(); // 맨 뒷사람은 무조건이기 때문에
        
        if(people[idx] + back <= limit) // r같이 탈 수 있다면
        {
            answer++;
            idx++;
        }
        else // 같이 탈 수 없다면
        {
            answer++;
        }
    }
    return answer;
}