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

	int N, M; cin >> N >> M;
	vector<int> A(N);
	int start = 0; int end = 0;

	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
		if (start < A[i])
		{
			start = A[i]; // 레슨 최댓값을 시작 인덱스로 저장
		}
		end = end + A[i]; // 모든 레슨의 값을 종료 인덱스로 저장
	}

	// 이진 탐색
	while (start <= end)
	{
		int middle = (start + end) / 2;
		int sum = 0; // 블루레이에 담고 있는 강의 길이의 합
		int count = 0; // 블루레이 개수

		// 현재 중간값으로 블루레이를 나누는 과정
		for (int i = 0; i < N; i++)
		{
			// 현재 블루레이에 담을 수 없는 경우, 블루레이 추가
			if (sum + A[i] > middle)
			{
				count++;
				sum = 0; // 새로운 블루레이를 시작하므로 합 초기화
			}
			sum += A[i]; // 현재 블루레이에 강의 길이 추가
		}
		if (sum != 0)
		{
			// 마지막 블루레이에 남아있는 강의가 있는 경우
			count++;
		}
		// 블루레이 개수가 M보다 많으면, 블루레이 크기 증가
		if (count > M)
		{
			start = middle + 1;
		}
		// 블루레이 개수가 M 이하이면, 블루레이 크기 감소
		else
		{
			end = middle - 1;
		}
	}
	// 최적의 블루레이 크기 출력
	cout << start << "\n";

	return 0;
}