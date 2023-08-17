#include <string>
#include <vector>
#include <unordered_set> // 추가

using namespace std;

vector<int> solution(vector<int> arr, int k) {
    vector<int> answer;
    unordered_set<int> seen; // 중복 체크용 집합

    for (int i = 0; i < arr.size(); i++) {
        if (seen.find(arr[i]) == seen.end()) { // 해당 숫자가 집합에 없는 경우
            seen.insert(arr[i]);
            answer.push_back(arr[i]);
        }

        if (answer.size() == k) // 원하는 길이 k에 도달하면 반복 종료
            break;
    }

    while (answer.size() < k) { // 길이 k에 도달하지 못한 경우 -1 채우기
        answer.push_back(-1);
    }

    return answer;
}
