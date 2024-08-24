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

	long min, max; cin >> min >> max;
	long A[10000001];

	for (int i = 2; i < 10000001; i++)
	{
		A[i] = i;
	}

	// 에라토스테네스의 체 알고리즘으로 배열 A엔 소수만 남기도록 함
	// A[i]가 0이 아니라면 소수이고, 배수들은 0으로 설정
	for (int i = 2; i <= sqrt(10000001); i++)
	{
		if (A[i] == 0)
		{
			continue;
		}
		for (int j = i + i; j < 10000001; j = j + i)
		{
			A[j] = 0;
		}
	}

	int count = 0;

	for (int i = 2; i < 10000001; i++)
	{
		if (A[i] != 0)
		{
			long temp = A[i]; // A[i]의 거듭제곱

			// A[i]에 대해 min, max의 범위에 포함 되는 지 확인
			while ((double)A[i] <= (double)max / (double)temp)
			{
				if ((double)A[i] >= (double)min / (double)temp)
				{
					count++; // 범위 내에 있는 경우는 카운트
				}
				temp = temp * A[i];
			}
		}
	}
	cout << count << "\n";

	return 0;
}