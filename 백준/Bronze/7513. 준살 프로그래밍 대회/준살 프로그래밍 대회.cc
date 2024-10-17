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
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int t; 
    cin >> t;  // 테스트 케이스 개수

    for (int scenario = 1; scenario <= t; scenario++) {
        int m; 
        cin >> m;  // 단어의 개수

        vector<string> words(m);
        for (int i = 0; i < m; i++) {
            cin >> words[i];  // 각 단어 입력
        }

        int n; 
        cin >> n;  // 참가자의 수

        cout << "Scenario #" << scenario << ":\n";
        
        // n명의 참가자들의 비밀번호를 처리
        for (int i = 0; i < n; i++) {
            int k; 
            cin >> k;  // 비밀번호에 포함된 단어의 개수
            string password = "";

            for (int j = 0; j < k; j++) {
                int index; 
                cin >> index;  // 단어 인덱스
                password += words[index];  // 해당 인덱스의 단어를 비밀번호에 추가
            }

            // 비밀번호 출력
            cout << password << "\n";
        }

        // 테스트 케이스 사이에는 빈 줄을 출력
        if (scenario != t) {
            cout << "\n";
        }
    }

    return 0;
}