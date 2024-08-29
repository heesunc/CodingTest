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

	long Min, Max; cin >> Min >> Max;
	// 최댓값과 최솟값의 차이만큼 배열 선언
	vector<bool> Check(Max - Min + 1);

	// 2의 제곱수인 4부터 max보다 작거나 같은 값까지 반복
	for (long i = 2; i * i <= Max; i++)
	{
		long pow = i * i; // 제곱수
		long start_index = Min / pow;

		if (Min % pow != 0)
		{
			// 나머지가 있으면 1을 더해주어야 Min보다 큰 제곱수부터 시작
			start_index++;
		}
		// 제곱수를 true로 변경
		for (long j = start_index; pow * j <= Max; j++)
		{
			Check[(int)((j * pow) - Min)] = true;
		}
	}

	int count = 0;

	for (int i = 0; i <= Max - Min; i++)
	{
		if (!Check[i])
		{
			count++;
		}
	}
	cout << count << "\n";

	return 0;
}