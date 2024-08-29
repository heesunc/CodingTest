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

	long n; cin >> n;
	long result = n;

	for (long p = 2; p <= sqrt(n); p++)
	{
		if (n % p == 0) // p가 소인수인지 확인
		{
			result = result - result / p; // 결괏값 업데이트
			// 해당 소인수 지우기 (2^7*11이라면 11만 남김)
			while (n % p == 0)
			{
				n /= p;
			}
		}
	}
	if (n > 1) // 아직 소인수 구성이 남아있는 경우
	{
		// 반복문에서 제곱근까지만 탐색했기 때문에 1개의 소인수가 누락되는 케이스
		result = result - result / n;
	}
	cout << result << "\n";
}