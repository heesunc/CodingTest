#include <string>
#include <iostream>

using namespace std;

int main() {
    // 시간 단축을 위한 구문
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int suNo, quizNo;
    cin >> suNo >> quizNo;
    int S[100001] = {};

    for (int i = 1; i <= suNo; i++)
    {
        int temp;
        cin >> temp;
        S[i] = S[i - 1] + temp; // 합 배열 생성
    }

    for (int i = 0; i < quizNo; i++)
    {
        int start, end;
        cin >> start >> end;
        cout << S[end] - S[start - 1] << "\n"; // 부분 합 출력
    }
}