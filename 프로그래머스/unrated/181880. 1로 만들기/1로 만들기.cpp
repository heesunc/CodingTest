#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int answer = 0;
    
    for (int i = 0; i < num_list.size(); i++) {
        while (num_list[i] != 1) { // 1이 아닐 때까지 돌려
            if (num_list[i] % 2 == 0) { // 짝수면
                num_list[i] /= 2; // 반으로 나눠
            } else { // 홀수면
                num_list[i] = (num_list[i] - 1) / 2; // 1빼고 나누기 2해
            }
            answer++; // 쁠쁠
        }
    }
    
    return answer;
}