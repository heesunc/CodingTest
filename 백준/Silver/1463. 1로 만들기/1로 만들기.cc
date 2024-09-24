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
static vector<int> D;

int main() {
    ios::sync_with_stdio(false);  // 입출력 성능 향상을 위해 C 표준 스트림과의 동기화 비활성화
    cin.tie(NULL);  // 입출력의 동기화를 해제하여 성능을 향상
    cout.tie(NULL); // 출력 동기화를 해제하여 성능 향상

    cin >> N;
    D.resize(N + 1);
    D[1] = 0; // 1일 때 연산 불필요

    for (int i = 2; i <= N; i++)
    {
        D[i] = D[i - 1] + 1; // -1 연산 표현, 1을 빼는 연산이 가능함
        if (i % 2 == 0) // 2로 나누는 연산이 가능함
        {
            D[i] = min(D[i], D[i / 2] + 1);
        }
        if (i % 3 == 0) // 3으로 나누는 연산이 가능함
        {
            D[i] = min(D[i], D[i / 3] + 1);
        }
    }
    cout << D[N];
}