#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int pizza = 0;
        for(int i = 1; i <= n; i++)
        {
            if(i % 7 == 1)
                pizza++;
        }    
    
    return pizza;
}