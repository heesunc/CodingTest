#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // 시간 단축을 위한 구문
    ios::sync_with_stdio(false);    cin.tie(NULL);    cout.tie(NULL);

    int N; // 수의 개수
    cin >> N;
    vector<int> A(N, 0);

    for (int i = 0; i < N; i++)
    {
        cin >> A[i]; // 배열 저장
    }

    sort(A.begin(), A.end()); // 자료 배열 정렬

    int count = 0;
    
    for (int k = 0; k < N; k++)
    {
        long find = A[k];
        int i = 0;
        int j = N - 1;

        while (i < j)
        {
            if (A[i] + A[j] == find)
            {
                if (i != k && j != k)
                {
                    count++;
                    break;
                }
                else if (i == k)
                {
                    i++;
                }
                else if (j == k)
                {
                    j--;
                }
            }
            else if (A[i] + A[j] < find)
            {
                i++;
            }
            else
            {
                j--;
            }
        }
    }    
    cout << count << "\n";
}