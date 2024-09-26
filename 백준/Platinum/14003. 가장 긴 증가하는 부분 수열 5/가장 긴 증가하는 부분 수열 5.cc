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

// 수열 A의 크기
int N;
// 수열 A
vector<int> A;
// LIS를 저장할 벡터
vector<int> lis;
// LIS의 경로를 저장하기 위한 배열
vector<int> trace;
// LIS에서 선택된 원소들의 인덱스를 저장하는 배열
vector<int> result_path;

// LIS를 구하는 함수
void findLIS() {
    // LIS 탐색을 위한 이분 탐색 위치
    vector<int> lis_indexes;

    // 수열 A를 순차적으로 순회하면서 LIS를 찾음
    for (int i = 0; i < N; i++) {
        // A[i]를 LIS에 넣기 위한 위치를 이분 탐색으로 찾음
        int pos = lower_bound(lis.begin(), lis.end(), A[i]) - lis.begin();

        // 새로운 원소가 LIS에 추가될 수 있으면 LIS 확장
        if (pos == lis.size()) {
            lis.push_back(A[i]);
            lis_indexes.push_back(i);
        }
        else {
            lis[pos] = A[i];
            lis_indexes[pos] = i;
        }
        trace[i] = (pos > 0) ? lis_indexes[pos - 1] : -1;
    }

    // 가장 마지막에 있는 LIS의 끝에서부터 경로를 역추적
    int idx = lis_indexes.back();
    while (idx != -1) {
        result_path.push_back(A[idx]);
        idx = trace[idx];
    }

    // 최종 경로를 역순으로 출력하기 위해 반전
    reverse(result_path.begin(), result_path.end());
}

int main() {
    // 입력 받기
    cin >> N;
    A.resize(N);
    trace.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    // LIS 계산
    findLIS();

    // 출력: LIS의 길이
    cout << lis.size() << '\n';

    // 출력: LIS 수열
    for (int i = 0; i < result_path.size(); i++) {
        cout << result_path[i] << ' ';
    }
    cout << '\n';

    return 0;
}