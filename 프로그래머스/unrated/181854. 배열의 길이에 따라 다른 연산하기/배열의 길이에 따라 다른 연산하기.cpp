#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, int n) {
    int size = arr.size();
    
    if (size % 2 == 0) // 짝수라면 홀수 인덱스 위치에 n을 더한 배열
        for(int i=1; i < size; i+=2)
        {
            arr[i] += n;
        }
    else
        for(int i=0; i < size; i+=2)
            arr[i] += n;
    
    return arr;
}