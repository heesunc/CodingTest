#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> rank, vector<bool> attendance) {
    int answer = 0;
    
    vector<pair<int, int>> stu;
    for(int i=0; i<rank.size(); ++i)
    {
        stu.push_back({rank[i], i});
    }
    
    sort(stu.begin(), stu.end());
    
    vector<int> select;
    for(auto& s : stu)
    {
        if(attendance[s.second])
        {
            select.push_back(s.second);
            if(select.size() == 3)
                break;
        }
    }
    
    answer = 10000 * select[0] + 100 * select[1] + select[2];
    
    return answer;
}