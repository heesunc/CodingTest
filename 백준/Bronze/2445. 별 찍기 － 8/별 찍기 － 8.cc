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
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int N;
    cin >> N;

    // 첫 번째부터 N번째 줄까지 (윗부분)
    for (int i = 1; i <= N; i++) {
        // 왼쪽 별 출력
        for (int j = 1; j <= i; j++) {
            cout << "*";
        }
        // 가운데 공백 출력
        for (int j = 1; j <= 2 * (N - i); j++) {
            cout << " ";
        }
        // 오른쪽 별 출력
        for (int j = 1; j <= i; j++) {
            cout << "*";
        }
        cout << endl;
    }

    // N+1번째부터 2N-1번째 줄까지 (아랫부분)
    for (int i = N - 1; i >= 1; i--) {
        // 왼쪽 별 출력
        for (int j = 1; j <= i; j++) {
            cout << "*";
        }
        // 가운데 공백 출력
        for (int j = 1; j <= 2 * (N - i); j++) {
            cout << " ";
        }
        // 오른쪽 별 출력
        for (int j = 1; j <= i; j++) {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}