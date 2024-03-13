#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    
    // 최댓값이 나올 수 있는 경우의 수
    // (음수) x (음수)가 큰 수 일 경우
    // (양수) x (양수)가 큰 수 일 경우
    
    // 정렬
    sort(numbers.begin(), numbers.end());    
    
    // 처음 2개의 수 vs 마지막 2개의 수
    answer = max(numbers[0] * numbers[1], *(numbers.end() - 1) * *(numbers.end() - 2) );
    return answer;
    
    /*
    int max = 0;
    for(int i = 0; i<numbers.size(); i++)
    {
        for(int j = i + 1; j<numbers.size(); j++)
        {
            answer = numbers[i] * numbers[j];
            if (max < answer)
                max = answer;
        }
    }
    */
    
    return answer;
}