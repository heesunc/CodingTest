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

static int T, N, K; // 테스트 케이스, 층수, 호수
static int D[15][15];

int main() {
    ios::sync_with_stdio(false);  // 입출력 성능 향상을 위해 C 표준 스트림과의 동기화 비활성화
    cin.tie(NULL);  // 입출력의 동기화를 해제하여 성능을 향상
    cout.tie(NULL); // 출력 동기화를 해제하여 성능 향상

    for (int i = 0; i < 15; i++) // DP 테이블 초기화
    {
        D[i][1] = 1; // i층의 1호는 항상 1의 값을 지니기 때문에 초기화할 수 있음
        D[0][i] = i; // 0층의 i호는 i의 값을 지나도록 문제에서 주어짐
    }
    for (int i = 1; i < 15; i++)
    {
        for (int j = 2; j < 15; j++)
        {
            D[i][j] = D[i][j - 1] + D[i - 1][j]; // 점화식
            // i층 j호에 거주하는 사람 수 = i층 j-1호에 사는 사람 수 + i-1층 j호에 사는 사람 수
        }
    }

    cin >> T;

    for (int i = 0; i < T; i++)
    {
        cin >> K >> N;
        cout << D[K][N] << "\n";
    }
}