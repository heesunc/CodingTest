#include <string>       // 문자열 처리를 위한 헤더 파일
#include <iostream>     // 입출력을 위한 헤더 파일
#include <vector>       // 동적 배열(vector)을 사용하기 위한 헤더 파일
#include <algorithm>    // 알고리즘 함수 (예: fill())를 사용하기 위한 헤더 파일
#include <stack>        // 스택 자료구조를 사용하기 위한 헤더 파일
#include <queue>        // 큐 및 우선순위 큐(priority_queue)를 사용하기 위한 헤더 파일
#include <deque>        // 덱(Deque, 양방향 큐)을 사용하기 위한 헤더 파일
#include <cctype>       // 문자 처리를 위한 헤더 파일
#include <stdlib.h>     // 문자열을 숫자로 변환하는 함수(예: atoi())를 위한 헤더 파일
#include <cmath>        // 수학 함수를 사용하기 위한 헤더 파일
#include <unordered_map> // 해시맵(unordered_map)을 사용하기 위한 헤더 파일
#include <map>          // 맵(map, 정렬된 딕셔너리)을 사용하기 위한 헤더 파일
#include <sstream>      // 문자열 스트림을 사용하기 위한 헤더 파일
#include <cstdlib>      // 유틸리티 함수(예: rand(), exit())를 위한 헤더 파일
#include <iomanip>      // 입출력 서식을 지정하기 위한 헤더 파일
#include <climits>      // INT_MAX(최대 정수값)을 사용하기 위한 헤더 파일
#include <numeric>      // accumulate(누적 합)를 사용하기 위한 헤더 파일
#include <limits.h>     // 시스템 한계값들을 정의하는 헤더 파일 (ex: LONG_MAX)

using namespace std;

static int N;
static int DP[1001][1001];
static string A, B;
static vector<char> Path;
void getText(int r, int c);

int main() {
    ios::sync_with_stdio(false);  // 입출력 성능을 향상시키기 위해 C++ 스트림을 C 표준 스트림과 비동기화
    cin.tie(NULL);  // 입력과 출력을 분리하여 입출력 성능을 최적화
    cout.tie(NULL); // 출력과의 동기화를 끊어 성능 향상

    cin >> A >> B;

    for (int i = 1; i <= A.size(); i++)
    {
        for (int j = 1; j <= B.size(); j++)
        {
            if (A[i - 1] == B[j - 1])
            {
                // 같은 문자열일 경우 왼쪽 대각선 값 + 1
                DP[i][j] = DP[i - 1][j - 1] + 1;
            }
            else
            {
                // 다르면 왼쪽과 위의 값 중 큰 수
                DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
            }
        }
    }

    cout << DP[A.size()][B.size()] << "\n";
    getText(A.size(), B.size());

    for (int i = Path.size() - 1; i >= 0; i--)
    {
        cout << Path[i];
    }
    cout << "\n";
}

void getText(int r, int c)
{
    if (r == 0 || c == 0)
    {
        return;
    }
    // 같으면 LCS에 기록하고 왼쪽 위로 이동
    if (A[r - 1] == B[c - 1])
    {
        Path.push_back(A[r - 1]);
        getText(r - 1, c - 1);
    }
    // 다르면 왼쪽과 위쪽 중 큰 수로 이동 (위쪽이 우선)
    else
    {
        if (DP[r - 1][c] > DP[r][c - 1])
        {
            getText(r - 1, c);
        }
        else
        {
            getText(r, c - 1);
        }
    }
}