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

// 전역 변수로 선언된 변수들
static int N;  // 배열의 크기를 저장할 변수
static vector<int> A, L, R;  // 입력 배열 A, 왼쪽(L), 오른쪽(R)에서 연속 합을 저장할 배열들

int main() {
    ios::sync_with_stdio(false);  // 입출력 성능을 향상시키기 위해 C++ 스트림을 C 표준 스트림과 비동기화
    cin.tie(NULL);  // 입력과 출력을 분리하여 입출력 성능을 최적화
    cout.tie(NULL); // 출력과의 동기화를 끊어 성능 향상

    cin >> N;  // 배열의 크기 입력받음
    A.resize(N);  // 배열 A의 크기를 N으로 조정

    // 배열 A에 값 입력
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    // L 배열의 초기화: 오른쪽으로 index를 포함한 최대 연속 합 구하기
    L.resize(N);
    L[0] = A[0];  // 첫 번째 값은 A[0]으로 설정
    int result = L[0];  // 하나도 제거하지 않았을 때의 최대 연속 합을 저장할 변수 초기화

    // L 배열 채우기: i번째 값이 포함된 연속 합 구하기
    for (int i = 1; i < N; i++) {
        L[i] = max(A[i], L[i - 1] + A[i]);  // A[i] 자체 vs A[i]를 포함한 이전 연속 합 중 큰 값 선택
        result = max(result, L[i]);  // 최대값 갱신
    }

    // R 배열의 초기화: 왼쪽으로 index를 포함한 최대 연속 합 구하기
    R.resize(N);
    R[N - 1] = A[N - 1];  // 마지막 값은 A[N-1]로 설정

    // R 배열 채우기: i번째 값이 포함된 연속 합 구하기
    for (int i = N - 2; i >= 0; i--) {
        R[i] = max(A[i], R[i + 1] + A[i]);  // A[i] 자체 vs A[i]를 포함한 이후 연속 합 중 큰 값 선택
    }

    // 배열의 중간값을 제거했을 때 최댓값 구하기
    // L[i-1] + R[i+1]을 더하면 i번째 값을 제거한 효과를 볼 수 있음
    for (int i = 1; i < N - 1; i++) {
        int temp = L[i - 1] + R[i + 1];  // i번째 값 제거 후 양쪽 연속 합 계산
        result = max(result, temp);  // 최대값 갱신
    }

    cout << result << "\n";  // 최종 결과 출력
}