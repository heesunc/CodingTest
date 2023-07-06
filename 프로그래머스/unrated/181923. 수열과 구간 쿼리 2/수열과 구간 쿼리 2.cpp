#include <climits>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    vector<int> answer;
    
    for(const auto& query : queries)
    {
        int s = query[0];
        int e = query[1];
        int k = query[2];
        
        int minGreater = INT_MAX;
        bool found = false;
        
        for (int i=s; i <=e; i++)
        {
            if (arr[i] > k && arr[i] < minGreater)
            {
                minGreater = arr[i];
                found = true;
            }
        }
        if (found)
            answer.push_back(minGreater);
        else
            answer.push_back(-1);
    }
    
    return answer;
}