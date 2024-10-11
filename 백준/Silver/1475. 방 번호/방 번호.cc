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

    // 플라스틱 세트는 0~9, 6과 9는 서로 뒤집어서 사용 가능

    string num; cin >> num;
    vector<int> set(10, 0);

    for (char c : num)
    {
        // '0' ~ '9'의 문자를 숫자로 변환하여 해당 인덱스를 증가시킴
        int digit = c - '0';
        set[digit]++;
    }

    // 0~9 중 최댓값을 찾고, 6하고 9는 더해서 2로 나누기
    int sixNine = set[6] + set[9];
    set[6] = (sixNine + 1) / 2; // 6과 9는 합쳐서 처리, 나눈 후 올림 처리
    set[9] = set[6]; // 9도 동일하게 처리된 값을 가짐 (사실상 안 써도 됨)
    auto result = max_element(set.begin(), set.end()); 
    cout << *result << "\n";

    return 0;
}