#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers, int num1, int num2) {
    vector<int> answer;
    
    vector<int> slice(numbers.begin() + num1, numbers.begin() + num2 + 1);
    
    for (int &i: slice) {
        answer.push_back(i);
    }
    
    return answer;
}