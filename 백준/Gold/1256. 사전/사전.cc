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

static int N, M, K;               // N: 'a'의 개수, M: 'z'의 개수, K: K번째 사전순 문자열을 찾기 위한 값
static long D[202][202];          // D[i][j]: i개의 문자 중에서 j개의 선택에 대한 조합의 개수 저장 (이항 계수)

int main() {
    ios::sync_with_stdio(false);  // 입출력 성능 향상을 위해 C 표준 스트림과의 동기화 비활성화
    cin.tie(NULL);  // 입출력의 동기화를 해제하여 성능을 향상
    cout.tie(NULL); // 출력 동기화를 해제하여 성능 향상

    // N, M, K 입력 받기
    cin >> N >> M >> K;

    // 조합 테이블 초기화
    for (int i = 0; i <= 200; i++)  // D 배열의 인덱스는 최대 200까지
    {
        for (int j = 0; j <= i; j++)  // j는 선택할 문자 개수
        {
            if (j == 0 || j == i)  // nC0 또는 nCn은 1 (모든 것을 선택하거나 아무것도 선택하지 않는 경우)
            {
                D[i][j] = 1;
            }
            else  // 이항 계수 공식: D[i][j] = D[i-1][j-1] + D[i-1][j]
            {
                D[i][j] = D[i - 1][j - 1] + D[i - 1][j];
                // 경우의 수가 너무 커지면 10억을 넘지 않도록 제한
                if (D[i][j] > 1000000000)
                {
                    D[i][j] = 1000000001;  // 10억을 넘으면 1000000001로 설정하여 오버플로 방지
                }
            }
        }
    }

    // 주어진 N개의 'a'와 M개의 'z'로 만들 수 있는 모든 문자열의 수가 K보다 작으면, 불가능 (-1 출력)
    if (D[N + M][M] < K)
    {
        cout << "-1";  // K번째 문자열을 만들 수 없으면 -1 출력
    }
    else
    {
        // N개의 'a'와 M개의 'z'로 사전 순으로 K번째 문자열을 구성
        while (!(N == 0 && M == 0))  // 'a'와 'z'가 모두 0이 될 때까지 반복
        {
            // N-1개의 'a'와 M개의 'z'로 만들 수 있는 문자열의 수가 K보다 크거나 같으면
            // 즉, 첫 번째 문자가 'a'인 경우의 모든 조합이 K보다 크면, 첫 문자는 'a'로 선택
            if (D[N - 1 + M][M] >= K)
            {
                cout << "a";  // 첫 번째 문자는 'a'
                N--;  // 'a'를 사용했으므로 N 감소
            }
            else  // 첫 번째 문자가 'a'인 경우가 K보다 작으면 첫 문자는 'z'
            {
                cout << "z";  // 첫 번째 문자는 'z'
                K = K - D[N - 1 + M][M];  // 'a'로 만들 수 있는 경우의 수를 K에서 빼줌
                M--;  // 'z'를 사용했으므로 M 감소
            }
        }
    }
}
