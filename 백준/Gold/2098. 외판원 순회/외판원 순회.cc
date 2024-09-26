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

// 전역 변수 선언
static int INF = 1000000 * 16 + 1;   // 매우 큰 값으로 초기화하여 최솟값을 찾는 용도로 사용 (무한대처럼 취급)
static int N;                        // 도시의 수
static int W[16][16];                // 두 도시 간의 비용을 저장하는 배열 (W[i][j] = i에서 j로 가는 비용)
static int D[16][(1 << 16)];         // 메모이제이션 배열, 특정 도시와 방문한 상태를 저장
int tsp(int c, int v);               // 함수 선언, 현재 도시 c와 방문 상태 v에 따른 최소 비용을 반환

int main() {
    // 입출력 속도를 향상시키기 위한 설정
    ios::sync_with_stdio(false);     // C와 C++ 입출력 동기화를 비활성화하여 속도 향상
    cin.tie(NULL);  // 입력과 출력 스트림을 분리해 성능 최적화
    cout.tie(NULL); // 출력 스트림을 비동기화하여 성능 최적화

    // 도시의 수 입력
    cin >> N;

    // 두 도시 간의 비용 입력
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> W[i][j];  // i에서 j로 가는 비용 입력
        }
    }

    // 0번 도시부터 시작하여 모든 도시를 순회하는 최소 비용 출력
    cout << tsp(0, 1) << "\n";  // 0번 도시에서 시작, 0번 도시는 이미 방문했으므로 v = 1
}

int tsp(int c, int v)
{
    // 모든 도시를 방문한 경우
    if (v == (1 << N) - 1) {
        // 마지막 도시에서 출발점(0번 도시)으로 돌아가는 비용을 반환, 만약 경로가 없으면 INF 반환
        return W[c][0] == 0 ? INF : W[c][0];
    }

    // 이미 계산된 값이 있으면 그 값을 반환 (메모이제이션)
    if (D[c][v] != 0) {
        return D[c][v];
    }

    int min_val = INF;  // 최소 값을 구하기 위해 큰 값으로 초기화

    // 모든 도시를 순회하면서 다음 방문할 도시를 찾음
    for (int i = 0; i < N; i++) {
        // i번째 도시가 아직 방문하지 않았고, 현재 도시 c에서 i로 가는 경로가 존재할 때
        if ((v & (1 << i)) == 0 && W[c][i] != 0) {
            // i번째 도시를 방문한 후의 최소 비용 계산 (재귀 호출)
            min_val = min(min_val, tsp(i, (v | (1 << i))) + W[c][i]);
        }
    }

    // 계산된 결과를 메모이제이션 배열에 저장하고 반환
    D[c][v] = min_val;
    return D[c][v];
}