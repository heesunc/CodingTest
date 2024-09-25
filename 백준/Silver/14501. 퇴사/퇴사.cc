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

static int N;
static vector<int> D, T, P;

int main() {
    ios::sync_with_stdio(false);  // 입출력 성능 향상을 위해 C 표준 스트림과의 동기화 비활성화
    cin.tie(NULL);  // 입출력의 동기화를 해제하여 성능을 향상
    cout.tie(NULL); // 출력 동기화를 해제하여 성능 향상

    cin >> N; // 퇴사까지 남은 일 수

    // 배열의 크기를 초기화. D는 N+2로 설정하여 마지막 날의 이후를 고려할 수 있게 함
    D.resize(N + 2); // 점화식 배열
    T.resize(N + 1); // 상담에 필요한 일수 저장 배열
    P.resize(N + 1); // 상담 완료 시 받는 수입 저장 배열

    // 각 상담의 기간(T[i])과 수입(P[i])을 입력받음
    for (int i = 1; i <= N; i++)
    {
        cin >> T[i] >> P[i];
    }

    // 마지막 날부터 첫 번째 날로 역순으로 반복하여 최대 수입 계산
    for (int i = N; i > 0; i--)
    {
        if (i + T[i] > N + 1) // i번째 상담을 퇴사일까지 끝낼 수 없는 경우
        {
            D[i] = D[i + 1]; // 상담을 하지 않으면 그 이후의 최대 수입을 그대로 가져옴
        }
        else // i번째 상담을 퇴사일까지 끝낼 수 있는 경우
        {
            // i번째 상담을 하지 않았을 때의 수입(D[i + 1])과
            // i번째 상담을 했을 때 얻을 수 있는 수입(P[i] + D[i + T[i]]) 중 큰 값을 선택
            D[i] = max(D[i + 1], P[i] + D[i + T[i]]);
        }
    }
    // 첫 번째 날부터의 최대 수입을 출력
    cout << D[1];
}