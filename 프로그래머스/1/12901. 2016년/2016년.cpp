#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    
    // 윤년의 마지막 일수를 month 배열에 담기
    int month[] = {31,29,31,30,31,30,31,31,30,31,30,31};
    // 1월 1일은 금요일이므로 1번째 인덱스 값은 금요일
    string day[] = {"THU","FRI","SAT","SUN","MON","TUE","WED"};        
    
    int sum = b;
    
    // 입력받은 월의 전월 (a-1)까지의 일수를 모두 더한 후, 입력받은 일(b)까지 더해서 총 일수를 구함
    for(int i=0; i<a-1; i++)
    {
        sum += month[i];
    }
    
    // 총 일수를 7로 나눈 나머지 값을 day 배열 인덱스에 넣어서 요일 구함
    return day[sum%7];
}