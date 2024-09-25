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

static int N, M;         // N은 행(row)의 수, M은 열(column)의 수
static int D[1001][1001]; // 2D 배열 D를 선언, 최대 1000x1000 크기

int main() {
    // C++의 입출력 속도를 향상시키기 위한 설정
    ios::sync_with_stdio(false);
    cin.tie(NULL);  // 입력과 출력을 분리하여 입출력 성능을 최적화
    cout.tie(NULL); // 출력과의 동기화를 끊어 성능 향상

    cin >> N >> M;  // N: 행의 개수, M: 열의 개수
    long max = 0;   // 가장 큰 정사각형의 한 변 길이를 저장할 변수

    // N개의 행을 입력받고 처리
    for (int i = 0; i < N; i++) {
        string mline;    // 한 행의 문자열을 저장할 변수
        cin >> mline;    // 행의 정보를 입력받음

        for (int j = 0; j < M; j++) {
            // mline[j]는 '0' 또는 '1'이므로 이를 정수형으로 변환하여 D[i][j]에 저장
            D[i][j] = mline[j] - '0';

            // 만약 D[i][j]가 1이고, 경계 내부(i > 0, j > 0)라면
            if (D[i][j] == 1 && j > 0 && i > 0) {
                // 좌상, 상, 좌의 값 중 가장 작은 값에 1을 더해 D[i][j]에 저장
                // 이를 통해 (i, j)에서 끝나는 가장 큰 정사각형의 변 길이를 계산
                D[i][j] = min(D[i - 1][j - 1], min(D[i - 1][j], D[i][j - 1])) + D[i][j];
            }
            // 현재까지 찾은 가장 큰 정사각형의 변 길이를 갱신
            if (max < D[i][j]) {
                max = D[i][j];
            }
        }
    }
    // 가장 큰 정사각형의 넓이는 변의 길이를 제곱한 값
    cout << max * max << "\n";  // 결과 출력
}