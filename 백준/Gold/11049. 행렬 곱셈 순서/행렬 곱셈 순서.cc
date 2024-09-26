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
static int N;                       // 행렬의 개수
static vector<pair<int, int>> M;    // 각 행렬의 행과 열을 저장하는 벡터 (pair 사용)
static long D[502][502];            // 메모이제이션을 위한 배열
int execute(int s, int e);          // 함수 선언, s에서 e까지의 최소 연산 횟수를 구하는 함수

int main() {
    // 입출력 속도를 향상시키기 위한 설정
    ios::sync_with_stdio(false);     // C와 C++ 입출력 동기화를 비활성화하여 속도 향상
    cin.tie(NULL);  // 입력과 출력 스트림을 분리해 성능 최적화
    cout.tie(NULL); // 출력 스트림을 비동기화하여 성능 최적화

    // 행렬의 개수 입력
    cin >> N;

    // 행렬 크기 정보를 저장할 벡터 크기 설정
    M.resize(N + 1);

    // 메모이제이션 배열을 -1로 초기화 (아직 계산되지 않은 상태)
    for (int i = 0; i < N + 1; i++) {
        for (int j = 0; j < N + 1; j++) {
            D[i][j] = -1;
        }
    }

    // 각 행렬의 행과 열 크기를 입력받아 벡터에 저장
    for (int i = 1; i <= N; i++) {
        int y, x;
        cin >> y >> x;
        M[i] = make_pair(y, x);  // i번째 행렬의 행(y)과 열(x)을 저장
    }

    // 1번부터 N번 행렬까지 곱하는 최소 연산 횟수를 계산하여 출력
    cout << execute(1, N) << "\n";
}

int execute(int s, int e)
{
    int result = INT_MAX;  // 결과값을 최소값으로 찾기 위해 큰 값으로 초기화
    // 이미 계산된 값이 있으면 그 값을 반환 (메모이제이션)
    if (D[s][e] != -1) {
        return D[s][e];
    }

    // 시작과 끝이 같은 경우, 행렬을 곱할 필요가 없으므로 0 반환
    if (s == e) {
        return 0;
    }

    // 시작과 끝이 바로 인접한 경우, 두 행렬의 곱셈 비용 계산
    if (s + 1 == e) {
        return M[s].first * M[s].second * M[e].second;
    }

    // 중간에 다른 행렬을 기준으로 분할하여 최소 곱셈 비용을 계산
    for (int i = s; i < e; i++) {
        result = min(result, M[s].first * M[i].second * M[e].second
            + execute(s, i) + execute(i + 1, e));
    }

    // 계산된 결과를 메모이제이션 배열에 저장하고 반환
    return D[s][e] = result;
}
