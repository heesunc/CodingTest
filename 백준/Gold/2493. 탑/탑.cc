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
#include <climits> // INT_MAX를 사용하기 위한 헤더 파일

using namespace std;  // 표준 라이브러리(std)의 네임스페이스를 사용함

int main() {
	// 시간 단축을 위한 구문
	ios::sync_with_stdio(false);    cin.tie(NULL);    cout.tie(NULL);

	vector<int> A;
	stack<pair<int, int>> S;
	int N, t, i = 1;

	cin >> N;

	S.push({ 100000001, 0 });
	
	for (int j = 0; j < N; j++)
	{
		cin >> t;

		// 스택의 맨 위 값이 현재 입력된 값보다 작으면 스택에서 제거
		while (S.top().first < t)
			S.pop();

		// 스택의 맨위 값이 현재 입력된 값보다 크거나 같은 경우, 
		// 그 값의 위치를 추가
		A.push_back(S.top().second);
		// 현재 입력된 값을 그 위치와 함께 스택에 푸시
		S.push({ t, i++ });
	}

	for (int j = 0; j < N; j++)
	{
		cout << A[j] << " ";
	}

	return 0;
}