#include <string>

int solution(std::string number) {
    int sum = 0;
    
    for (char c : number) {
        int digit = c - '0'; // char를 int형으로 변환
        sum += digit;
        sum %= 9;
    }    
    return sum;
}
