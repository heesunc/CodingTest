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

int minDeletionsToAnagram(const string& str1, const string& str2) {
    // 알파벳의 개수는 26개로 고정
    vector<int> freq1(26, 0), freq2(26, 0);

    // 첫 번째 단어의 각 문자의 빈도수 계산
    for (char c : str1) {
        freq1[c - 'a']++;
    }

    // 두 번째 단어의 각 문자의 빈도수 계산
    for (char c : str2) {
        freq2[c - 'a']++;
    }

    // 두 단어가 애너그램이 되도록 만들기 위해 제거해야 할 문자 수 계산
    int deletions = 0;
    for (int i = 0; i < 26; i++) {
        deletions += abs(freq1[i] - freq2[i]);
    }

    return deletions;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    string str1, str2;
    cin >> str1;
    cin >> str2;

    int result = minDeletionsToAnagram(str1, str2);
    cout << result << endl;

    return 0;
}