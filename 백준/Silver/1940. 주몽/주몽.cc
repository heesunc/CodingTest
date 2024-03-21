#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // 시간 단축을 위한 구문
    ios::sync_with_stdio(false);    cin.tie(NULL);    cout.tie(NULL);

    int N, M; // 갑옷 재료 개수, 고유 번호
    cin >> N >> M;
    vector<int> A(N, 0);

    for (int i = 0; i < N; i++)
    {
        cin >> A[i]; // 재료 배열 저장
    }

    sort(A.begin(), A.end()); // 자료 배열 정렬

    int count = 0;
    int i = 0;
    int j = N - 1;

    while (i < j)
    {
        if (A[i] + A[j] == M)
        {
            i++; j--;
            count++;
        }
        else if (A[i] + A[j] > M)
        {
            j--;
        }
        else if (A[i] + A[j] < M)
        {
            i++;
        }
    }
    cout << count << "\n";
}