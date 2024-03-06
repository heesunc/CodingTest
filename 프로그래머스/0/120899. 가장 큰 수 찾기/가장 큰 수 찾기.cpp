#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array) {
    vector<int> answer;
    int j = 0;
    int k = 0;

    for (int i = 0; i < array.size(); i++)
    {
        if (j < array[i])
        {
            j = array[i];            
            if (array[i] == j)
                k = i;
        }
    }
    answer.push_back(j); // 가장 큰 수    
    answer.push_back(k); // 인덱스
    
    return answer;
}