#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>

using namespace std;

int main() {
    ios::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);

    int N; cin >> N;
    vector<pair<int, int>> A(N);

    for (int i = 0; i < N; i++)
    {
        cin >> A[i].first;
        A[i].second = i;
    }

    sort(A.begin(), A.end());
    int Max = 0;

    for (int i = 0; i < N; i++)
    {
        // 정렬 전 index - 정렬 후 index를 계산한 값 중 최댓값을 찾아 저장
        if (Max < A[i].second - i)
        {
            Max = A[i].second - i;
        }
    }

    // swap이 일어나지 않는 반복문이 한 번 더 실행되는 것을 감안해 +1
    cout << Max + 1;
}