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

    // 등급과 학점 점수를 매핑한 unordered_map
    unordered_map<string, string> gradeToGPA = {
        {"A+", "4.3"}, {"A0", "4.0"}, {"A-", "3.7"},
        {"B+", "3.3"}, {"B0", "3.0"}, {"B-", "2.7"},
        {"C+", "2.3"}, {"C0", "2.0"}, {"C-", "1.7"},
        {"D+", "1.3"}, {"D0", "1.0"}, {"D-", "0.7"}
    };

    string grade;
    cin >> grade;

    // 입력된 등급에 해당하는 GPA 출력, 없으면 "0.0" 출력
    if (gradeToGPA.find(grade) != gradeToGPA.end()) {
        cout << gradeToGPA[grade] << "\n";
    }
    else {
        cout << "0.0" << "\n";
    }

    return 0;
}