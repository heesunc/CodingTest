#include <string>       // 문자열 처리를 위한 헤더 파일
#include <iostream>     // 입출력을 위한 헤더 파일
#include <vector>       // 동적 배열(vector)을 사용하기 위한 헤더 파일
#include <algorithm>    // 알고리즘 함수를 사용하기 위한 헤더 파일
#include <stack>        // 스택을 사용하기 위한 헤더 파일
#include <queue>        // 큐를 사용하기 위한 헤더 파일
#include <deque>        // 덱(Deque)을 사용하기 위한 헤더 파일
#include <cctype>       // 문자열의 문자를 검사하기 위한 헤더 파일
#include <stdlib.h>     // 문자열을 숫자로 변환하는 함수를 사용하기 위한 헤더 파일
#include <cmath>        // 수학 함수를 사용하기 위한 헤더 파일
#include <unordered_map> // 해시맵(Unordered Map)을 사용하기 위한 헤더 파일
#include <map>          // 맵(Map)을 사용하기 위한 헤더 파일
#include <sstream>      // 문자열을 스트림으로 변환하기 위한 헤더 파일
#include <cstdlib>      // 일반적인 유틸리티 함수를 사용하기 위한 헤더 파일
#include <iomanip>      // 입출력 서식 지정을 위한 헤더 파일

using namespace std;  // 표준 라이브러리(std)의 네임스페이스를 사용함

int main()
{
	ios::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	
    for (int j = 0; j < 3; ++j) {
        int cnt = 0; // 각 반복마다 cnt를 초기화합니다.

        for (int i = 0; i < 4; ++i) {
            int n;
            cin >> n; // 입력 값을 읽어옵니다.
            if (n == 0) {
                cnt++; // 0이면 cnt를 증가시킵니다.
            }
        }

        if (cnt == 0) {
            cout << "E\n";
        }
        else if (cnt == 1) {
            cout << "A\n";
        }
        else if (cnt == 2) {
            cout << "B\n";
        }
        else if (cnt == 3) {
            cout << "C\n";
        }
        else if (cnt == 4) {
            cout << "D\n";
        }
    }

    return 0;
}