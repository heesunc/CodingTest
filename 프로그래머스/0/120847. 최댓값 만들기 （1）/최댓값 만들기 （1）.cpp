#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    
    int max = *max_element(numbers.begin(),numbers.end());
    numbers.erase(remove(numbers.begin(), numbers.end(), max), numbers.end());
    int twomax = *max_element(numbers.begin(),numbers.end());
        
    answer = max * twomax;
    
    return answer;
}