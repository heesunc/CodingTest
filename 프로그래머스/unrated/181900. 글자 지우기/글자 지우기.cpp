#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string my_string, vector<int> indices) 
{
    // indices 벡터 정렬
    sort(indices.begin(), indices.end(), greater<int>());
    
    // indices size만큼 for문
    // indices[i]에 해당하면 erase 해주면 됨
    for (int i=0; i < indices.size(); ++i)
    {
        my_string.erase(indices[i], 1);
    }
    
    return my_string;
}