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
#include <ctime>

using namespace std;

int main() {
    // 입출력 속도를 향상시키기 위한 설정
    ios::sync_with_stdio(false);     // C와 C++ 입출력 동기화를 비활성화하여 속도 향상
    cin.tie(NULL);  // 입력과 출력 스트림을 분리해 성능 최적화
    cout.tie(NULL); // 출력 스트림을 비동기화하여 성능 최적화

    // 정문으로부터 걷는 거리가 가장 짧도록 방을 배정
    // W개의 방이 있는 H층 건물
    // 모든 인접한 두 방 사이의 거리는 1

    // Y나 YY는 층수, XX는 엘리베이터부터 세었을 때의 번호

    // T 테스트 케이스
    // H 호텔의 층수, W 각 층의 방 수, N 몇 번째 손님

    int T;  // 테스트 케이스 수
    cin >> T;

    while (T--) {
        int H, W, N;
        cin >> H >> W >> N;

        // 층수와 호실 계산
        int floor = (N - 1) % H + 1;  // 층 번호
        int room = (N - 1) / H + 1;   // 호실 번호

        // 방 번호는 "층수 + 호실" 형식으로 출력 (예: 305)
        cout << floor * 100 + room << endl;
    }
    return 0;
}