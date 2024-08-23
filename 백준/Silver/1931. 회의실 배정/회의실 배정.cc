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
#include <numeric>  // accumulate를 사용하기 위해 필요한 헤더 파일

using namespace std;  // 표준 라이브러리(std)의 네임스페이스를 사용함

int main() {
	// 시간 단축을 위한 구문
	ios::sync_with_stdio(false);    cin.tie(NULL);    cout.tie(NULL);

	// 회의 개수
	int N; cin >> N;
	vector<pair<int, int>> A(N);

	// 종료 시간 정렬 우선을 위해 종료 값을 first에 저장
	for (int i = 0; i < N; i++)
	{
		cin >> A[i].second;
		cin >> A[i].first;
	}

	sort(A.begin(), A.end());

	int count = 0;
	int end = -1; // 마지막으로 선택한 회의의 종료 시간을 추적

	for (int i = 0; i < N; i++)
	{
		// 겹치지 않는 다음 회의가 나온 경우
		if (A[i].second >= end)
		{
			end = A[i].first; // 종료 시간 업데이트
			count++;
		}
	}

	cout << count << "\n";
	
	return 0;
}

/*
A[i].second >= end
{ end = A[i].first; count++; }

4 1 -> 1 >= end(-1) cnt(1)
5 3 -> 3 >= end(4) X
6 0 -> 0 >= end(4) X
7 5 -> 5 >= end(4) cnt(2)
8 3 -> 3 >= end(7) X
9 5 -> 5 >= end(7) X
10 6 -> 6 >= end(7) X
11 8 -> 8 >= end(7) cnt(3)
12 8 -> 8 >= end(11) X
13 2 -> 2 >= end(11) X
14 12 -> 12 >= end(11) cnt(4)

*/