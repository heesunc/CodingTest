#include <string>       // 문자열 처리를 위한 헤더 파일
#include <iostream>     // 입출력을 위한 헤더 파일
#include <vector>       // 동적 배열(vector)을 사용하기 위한 헤더 파일
#include <algorithm>    // 알고리즘 함수를 사용하기 위한 헤더 파일

using namespace std;  // 표준 라이브러리(std)의 네임스페이스를 사용함

int main()
{
	ios::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);

	int N; cin >> N;
	vector<int> A(N);
	int count = 0;

	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}

	for (int j = 0; j < A.size(); j++)
	{
		if (A[j] < 2)
		{
			continue;
		}
		bool is_prime = true; // 소수 판별을 위한 변수 추가

		for (int i = 2; i * i <= A[j]; i++) 
		{ // 수정된 부분: 1부터 시작하는 것이 아니라 2부터 시작해야 합니다.
			if (A[j] % i == 0) 
			{
				is_prime = false; // 소수가 아닌 경우를 확인하고 플래그를 설정합니다.
				break;
			}
		}
		if (is_prime) 
		{ // 소수인 경우에만 count를 증가시킵니다.
			count++;
		}
	}

	cout << count;
}