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

static int N, L, R;
static long mod = 1000000007;
static long D[101][101][101];

int main() {
    // C++의 입출력 속도를 향상시키기 위한 설정
    ios::sync_with_stdio(false);
    cin.tie(NULL);  // 입력과 출력을 분리하여 입출력 성능을 최적화
    cout.tie(NULL); // 출력과의 동기화를 끊어 성능 향상

    cin >> N >> L >> R;
    D[1][1][1] = 1; // 빌딩이 1개이면 놓을 수 있는 경우의 수는 1개

    for (int i = 2; i <= N; i++)
    {
        for (int j = 1; j <= L; j++)
        {
            for (int k = 1; k <= R; k++)
            {
                D[i][j][k] =
                    (D[i - 1][j][k] * (i - 2) + // 가장 작은 빌딩을 가운데에 놓는 경우
                        (D[i - 1][j][k - 1] + // 가장 작은 빌딩을 오른쪽에 놓는 경우
                            D[i - 1][j - 1][k])) // 가장 작은 빌딩을 왼쪽에 놓는 경우
                    % mod;
            }
        }
    }
    cout << D[N][L][R] << "\n";
}