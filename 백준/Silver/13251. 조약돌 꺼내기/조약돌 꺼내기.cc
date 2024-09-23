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

static int M, K, T; // 전체 조약돌 개수, 색의 종류, 선택 조약돌 개수
static int D[51]; // 색깔별 조약돌 개수 저장하기 배열
static double probability[51]; // 색깔별 확률 저장 배열
static double ans = 0.0;

int main() {
    ios::sync_with_stdio(false);  // 입출력 성능 향상을 위해 C 표준 스트림과의 동기화 비활성화
    cin.tie(NULL);  // 입출력의 동기화를 해제하여 성능을 향상
    cout.tie(NULL); // 출력 동기화를 해제하여 성능 향상

    cin >> M;

    for (int i = 0; i < M; i++) // 전체 조약돌 개수만큼 반복
    {
        cin >> D[i]; // 각 조약돌 개수 저장ㅣㄹ  
        T += D[i]; // 조약돌 개수 더하기
    }

    cin >> K; // 선택 조약돌 개수 받기

    for (int i = 0; i < M; i++)
    {
        // 선택 조약돌 개수보다 현재 색 조약돌 개수가 적으면 모두 같은 색으로 뽑을 확률은 0
        if (D[i] >= K) // 현재 색깔의 조약돌 개수가 선택해야 할 개수보다 크면
        {
            probability[i] = 1.0;

            for (int k = 0; k < K; k++) // 색의 종류만큼 반복
            {
                probability[i] *= (double)(D[i] - k) / (T - k);
                // i 색깔을 모두 뽑을 확률 =
                // i 색깔을 모두 뽑을 확률 * 현재 색깔 개수 - K / 전체 색깔 개수 - K
            }
        }
        ans += probability[i];
        // 정답에 현재 색깔을 모두 뽑을 확률에 더하기
    }
    cout << fixed;
    cout.precision(9); // 오차 범위 내 출력을 위해 소수점 9자리까지 출력
    cout << ans;
}