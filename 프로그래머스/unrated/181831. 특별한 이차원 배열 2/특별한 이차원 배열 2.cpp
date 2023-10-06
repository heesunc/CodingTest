#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> arr) {
    int answer = arr.size();
    
    for(int i=0; i<answer; ++i)
    {
        for(int j=0; j<i; ++j)
        {
            // i번째 행과 j번째 열, j번째 행과 i번째 열의 원소를 비교하여 다르다면 0을 반환합니다.
            if(arr[i][j] == arr[j][i])
                answer = 1;
            else
                answer = 0;
        }
    }
    
    /*
    왜 int n = arr.size();로 하면 안될까?
    조건을 만족하는 첫 번째 원소 쌍을 찾으면 answer를 1로 설정합니다. 그러나 이후에 다른 원소 쌍이 조건을 만족하지 않으면 answer를 0으로 설정합니다. 즉, 이 코드는 배열의 일부 조건만 확인하고, 다른 조건들은 무시합니다.

반복문을 계속 수행하면서 answer를 여러 번 덮어쓰게 됩니다. 따라서 마지막 비교 결과만 남게 되며, 이것이 함수의 최종 반환 값이 됩니다. 이 경우, 마지막 비교 결과에 따라 answer가 설정되므로, 전체 배열의 대칭성을 확인할 수 없습니다.

원하는 동작은 모든 비교가 조건을 만족할 때만 answer를 1로 설정하고, 그 외에는 0으로 설정하는 것입니다. 그렇게 하려면 answer를 반복문 밖에서 초기화한 후, 모든 비교를 마친 후에 반환하는 것이 올바릅니다. 이것이 제시한 수정된 코드의 방식입니다.
*/
    
    return answer;
}