#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    // 시간 단축을 위한 구문
    ios::sync_with_stdio(false);    cin.tie(NULL);    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    int C[100001] = {};

    int answer = INT_MIN;

    for (int i = 1; i <= N; i++)
    {
        int temp;
        cin >> temp;
        C[i] = C[i - 1] + temp; // 구간 합 구하기
    }

    for (int i = K; i <= N; i++)
    {
        answer = max(answer, C[i] - C[i - K]);
    }

    cout << answer;
}