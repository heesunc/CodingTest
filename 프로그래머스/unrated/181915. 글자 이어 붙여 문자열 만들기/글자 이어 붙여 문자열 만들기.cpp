#include <string>
#include <vector>

using namespace std;

string solution(string my_string, vector<int> index_list) {
    string answer = "";
    
    // index_list 배열의 첫 번째 요소부터 마지막 요소까지 반복합니다.
    // 각 반복에서 현재 요소의 값을 index 변수에 할당합니다.
    // 반복문의 코드 블록 내에서 index 변수를 사용하여 현재 요소의 값을 활용할 수 있습니다.
    // 반복이 끝나면 반복문을 빠져나가고 다음 코드를 실행합니다.
    
    for (int index : index_list)
    {
        answer += my_string[index];
    }
    
    return answer;
}