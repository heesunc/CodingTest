#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, int k) {
    vector<int> answer;
    
    for(int i=0; i<arr.size(); i++)
    {
        // k가 홀수라면 arr의 모든 원소에 k를 곱하고
        if (k % 2 != 0)
            answer.push_back(arr[i]*k);
        // k가 짝수라면 arr의 모든 원소에 k를 더한다
        else
            answer.push_back(arr[i]+k);
    }
    return answer;
}