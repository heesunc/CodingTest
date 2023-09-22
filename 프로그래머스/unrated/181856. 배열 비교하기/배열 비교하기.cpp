#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr1, vector<int> arr2) {
    int answer = 0;
    
    int size1 = arr1.size();
    int size2 = arr2.size();
    
    int iarr1=0;
    int iarr2=0;
    
    for (int i=0; i<size1; i++)
    {
        iarr1 += arr1[i];
    }
    for (int j=0; j<size2; j++)
    {
        iarr2 += arr2[j];
    }
    
    if (size1 > size2)
        answer = 1;
    else if (size1 == size2)
    {
        if (iarr1 > iarr2)
            answer = 1;
        else if (iarr1 < iarr2)
            answer = -1;
        else if (iarr1 == iarr2)
            answer = 0;
    }
    else
        answer = -1;  
    
    
    return answer;
}