#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> array) {
    int answer = 0;
    
    // 오름차순 정렬
    sort(array.begin(), array.end());
    
    // 중앙값
    int i = array.size() / 2;
    answer = array[i];
    
    return answer;
}