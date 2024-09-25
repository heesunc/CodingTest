#include <string>       // 문자열 처리를 위한 헤더 파일
#include <iostream>     // 입출력을 위한 헤더 파일
#include <vector>       // 동적 배열(vector)을 사용하기 위한 헤더 파일
#include <algorithm>    // 알고리즘 함수 (예: min())를 사용하기 위한 헤더 파일
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

// dp 배열: dp[k][i][j]는 k번째 움직임에서 왼발이 i, 오른발이 j일 때의 최소 비용을 저장
static long dp[100001][5][5];

// mp 배열: 발판 간 이동 비용을 저장. mp[i][j]는 발판 i에서 발판 j로 이동하는 비용
int mp[5][5] = {
    {0, 2, 2, 2, 2},  // 같은 발판에 있을 때의 비용은 0, 나머지는 2
    {2, 1, 3, 4, 3},  // 발판 1에서 다른 발판으로의 이동 비용
    {2, 3, 1, 3, 4},  // 발판 2에서 다른 발판으로의 이동 비용
    {2, 4, 3, 1, 3},  // 발판 3에서 다른 발판으로의 이동 비용
    {2, 3, 4, 3, 1}   // 발판 4에서 다른 발판으로의 이동 비용
};

int main() {
    // 입출력 속도를 향상시키기 위한 설정
    ios::sync_with_stdio(false);
    cin.tie(NULL);  // 입력과 출력을 분리하여 입출력 성능을 최적화
    cout.tie(NULL); // 출력과의 동기화를 끊어 성능 향상

    int n = 0, s = 1;  // n은 입력받는 발판 번호, s는 현재 단계 번호

    // dp 배열 초기화: 모든 값을 매우 큰 값으로 초기화 (100001 * 4는 매우 큰 값으로 간주)
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 100001; k++) {
                dp[k][i][j] = 100001 * 4; // 각 발판에서 다른 발판으로 이동하는 최소 비용을 초기화
            }
        }
    }

    dp[0][0][0] = 0; // 시작 상태: 두 발이 모두 0 (발판에 없을 때)일 때의 비용은 0

    while (true) {
        cin >> n;  // 다음으로 밟아야 할 발판 번호 입력
        if (n == 0) {  // 0이 입력되면 종료
            break;
        }
        // 왼발을 고정하고, 오른발이 움직일 경우의 최소 비용 계산
        for (int i = 0; i < 5; i++) {
            if (n == i) { // 왼발과 오른발이 같은 위치면 패스
                continue;
            }
            for (int j = 0; j < 5; j++) {
                // dp[s][i][n]은 s번째 단계에서 왼발이 i, 오른발이 n일 때 최소 비용
                dp[s][i][n] = min(dp[s - 1][i][j] + mp[j][n], dp[s][i][n]);
                // 이전 단계에서 오른발이 j였고, j에서 n으로 이동하는 비용을 고려
            }
        }
        // 오른발을 고정하고, 왼발이 움직일 경우의 최소 비용 계산
        for (int j = 0; j < 5; j++) {
            if (n == j) { // 왼발과 오른발이 같은 위치면 패스
                continue;
            }
            for (int i = 0; i < 5; i++) {
                // dp[s][n][j]는 s번째 단계에서 왼발이 n, 오른발이 j일 때 최소 비용
                dp[s][n][j] = min(dp[s - 1][i][j] + mp[i][n], dp[s][n][j]);
                // 이전 단계에서 왼발이 i였고, i에서 n으로 이동하는 비용을 고려
            }
        }
        s++; // 다음 단계로 이동
    }

    s--;  // 마지막 단계에서의 값을 확인하므로 단계 수 감소
    long minVal = INT_MAX;  // 최소 비용을 찾기 위한 변수 초기화

    // 모든 왼발, 오른발 위치에서 최소 비용을 찾음
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            minVal = min(minVal, dp[s][i][j]);  // 가장 작은 비용을 찾음
        }
    }

    // 최소 비용 출력
    cout << minVal << "\n";
}
