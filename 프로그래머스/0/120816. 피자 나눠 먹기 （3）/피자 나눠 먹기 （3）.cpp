#include <string>
#include <vector>

using namespace std;

int solution(int slice, int n) {
    int answer = 1; // 0 대신 1부터 시작하도록 수정
    
    while(answer * slice / n < 1) // 조건식 변경
        answer++;
    
    return answer;
}