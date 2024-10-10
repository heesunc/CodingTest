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
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    // N : 수학여행에 참가하는 학생 수
    // K : 한 방에 배정할 수 있는 최대 인원 수
    int N, K; cin >> N >> K;

    // 6학년까지의 학년별 남학생, 여학생을 저장할 2차원 벡터
    // students[학년][0] -> 남학생 수
    // students[학년][1] -> 여학생 수
    vector<vector<int>> students(6, vector<int>(2, 0));

    // 학생들의 정보 입력 받기
    for (int i = 0; i < N; ++i) {
        int grade, gender;
        cin >> grade >> gender;  // grade는 학년(1~6), gender는 성별(0: 남학생, 1: 여학생)
        students[grade - 1][gender]++;  // 학년은 1~6이므로 index는 grade-1로 접근
    }

    int roomCount = 0;  // 필요한 방의 수

    // 각 학년의 남학생과 여학생에 대해 필요한 방의 수 계산
    for (int grade = 0; grade < 6; ++grade) {
        for (int gender = 0; gender < 2; ++gender) {
            if (students[grade][gender] > 0) {
                // 학생 수를 K로 나누고 올림한 값만큼 방이 필요
                roomCount += (students[grade][gender] + K - 1) / K;
            }
        }
    }

    // 결과 출력
    cout << roomCount << endl;

    return 0;
}