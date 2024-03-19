#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 시간 단축을 위한 구문
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int suNo, quizNo;
    cin >> suNo >> quizNo;
    
    vector<vector<int>> A(suNo + 1, vector<int>(suNo + 1, 0));
    vector<vector<int>> D(suNo + 1, vector<int>(suNo + 1, 0));

    for (int i = 1; i <= suNo; i++)
    {
        for (int j = 1; j <= suNo; j++)
        {
            cin >> A[i][j];
            // 구간 합 구하기 (합 배열 저장)
            D[i][j] = D[i][j - 1] + D[i - 1][j] - D[i - 1][j - 1] + A[i][j];
        }
    }

    for (int i = 0; i < quizNo; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        // 구간 합
        int result = D[x2][y2] - D[x1 - 1][y2] - D[x2][y1 - 1] + D[x1 - 1][y1 - 1];
        cout << result << "\n";
    }
}