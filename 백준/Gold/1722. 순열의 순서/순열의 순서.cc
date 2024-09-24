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

static int N, Q;              // N: 숫자의 개수, Q: 문제 번호 (1 또는 2)
static long F[21], S[21];     // F: 팩토리얼 값을 저장하는 배열, S: 각 자리의 숫자를 저장하는 배열
static bool visited[21] = { false }; // 방문한 숫자를 기록하는 배열 (순열에서 이미 사용된 숫자 체크)

int main() {
    ios::sync_with_stdio(false);  // 입출력 성능 향상을 위해 C 표준 스트림과의 동기화 비활성화
    cin.tie(NULL);  // 입출력의 동기화를 해제하여 성능을 향상
    cout.tie(NULL); // 출력 동기화를 해제하여 성능 향상

    // 입력 받기: N은 숫자의 개수, Q는 문제 유형(1 또는 2)
    cin >> N >> Q;
    F[0] = 1;  // 0!은 1로 초기화

    // 팩토리얼 초기화 -> 각 자릿수에서 만들 수 있는 경우의 수
    for (int i = 1; i <= N; i++)
    {
        F[i] = F[i - 1] * i;  // F[i]에 i! 값을 저장
    }

    // 첫 번째 문제: 주어진 K에 해당하는 순열 구하기
    if (Q == 1)
    {
        long K; cin >> K;  // K번째 순열을 찾기 위한 값 입력
        for (int i = 1; i <= N; i++)  // N개의 자리 수에 대해 반복
        {
            for (int j = 1, cnt = 1; j <= N; j++)  // 사용하지 않은 숫자 중에서 K번째 순열의 자릿값을 찾음
            {
                if (visited[j])
                {
                    continue; // 이미 사용한 숫자는 건너뛰기
                }
                // K가 현재 자릿수에서 만들 수 있는 순열의 범위 안에 있는지 확인
                if (K <= cnt * F[N - i])
                {
                    K -= ((cnt - 1) * F[N - i]); // K값을 업데이트하여 다음 자릿수를 결정
                    S[i] = j;  // 현재 자리에 j 값을 할당
                    visited[j] = true;  // 해당 숫자를 방문 처리
                    break;
                }
                cnt++;  // 다음 숫자로 이동
            }
        }
        // 결과 출력: 순열 S 출력
        for (int i = 1; i <= N; i++)
        {
            cout << S[i] << " ";
        }
    }
    // 두 번째 문제: 주어진 순열이 몇 번째 순열인지 계산하기
    else
    {
        long K = 1;  // 순서값 초기화 (1번째부터 시작)
        for (int i = 1; i <= N; i++)  // 순열 S의 각 자리를 입력 받음
        {
            cin >> S[i];
            long cnt = 0;  // 현재 자리에 사용할 수 있는 숫자 개수

            for (int j = 1; j < S[i]; j++)  // 현재 자리에 올 수 있는 작은 숫자들을 확인
            {
                if (visited[j] == false)
                {
                    cnt++;  // 사용되지 않은 숫자의 개수를 센다
                }
            }
            K += cnt * F[N - i];  // 현재 자리에서 선택된 숫자에 따라 K값 업데이트
            visited[S[i]] = true;  // 현재 숫자를 사용했으므로 방문 처리
        }
        // 결과 출력: 주어진 순열이 몇 번째 순열인지 출력
        cout << K << "\n";
    }
}
