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

    // 자연수 N의 분해합은 N과 N을 이루는 각 자리수의 합
    // M의 분해합이 N인 경우, M을 N의 생성자
    // 생성자는 여러개일수도, 없을수도
    // 자연수 N의 가장 작은 생성자 구하기

    int N; cin >> N;
    int result = 0;

    for (int M = 1; M < N; ++M)
    {
        // M 각 자릿수의 합 구하기
        int sum_of_digits = 0;
        string M_str = to_string(M);

        // 문자열의 각 자릿수를 더하기
        for (char digit : M_str)
        {
            sum_of_digits += digit - '0'; // 문자를 숫자로 변환하여 더함
        }

        // M의 분해합 계산
        int decomposition_sum = M + sum_of_digits;

        // 분해합이 N과 같다면, 그 M이 생성자
        if (decomposition_sum == N)
        {
            result = M; // 가장 작은 새성자 발견
            break;
        }
    }
    // 결과 출력, 만약 생성자가 없다면 0 출력
    cout << (result != 0 ? result : 0) << endl;
    return 0;
}