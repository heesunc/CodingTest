#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers, string direction) {
    vector<int> answer;
    int a = numbers.size();
    
    if (direction == "right")
    {
        answer.push_back(numbers[a-1]);
        for(int i=0; i<numbers.size()-1; i++)
        {
            answer.push_back(numbers[i]);
        }
    }
    else
    {
        for(int i=0; i<numbers.size()-1; i++)
        {
            answer.push_back(numbers[i+1]);
        }
        answer.push_back(numbers[0]);
    }
    
    return answer;
}