#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = n;
    int x=1;
    
    while (true)
    {
        if (n % x == 1)
            return x;
        else
            x++;
    }
    
    return answer;
}