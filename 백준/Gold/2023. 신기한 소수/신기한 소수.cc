#include <string>       // 문자열 처리를 위한 헤더 파일
#include <iostream>     // 입출력을 위한 헤더 파일
#include <vector>       // 동적 배열(vector)을 사용하기 위한 헤더 파일
#include <algorithm>    // 알고리즘 함수를 사용하기 위한 헤더 파일

using namespace std;  // 표준 라이브러리(std)의 네임스페이스를 사용함

void DFS(int number, int jarisu);
bool isPrime(int num);
static int N;

int main() {
	ios::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);

	cin >> N;

	// 소수는 1과 자기 자신만 있는 수
	// 소수는 2,3,5,7
	DFS(2, 1);
	DFS(3, 1);
	DFS(5, 1);
	DFS(7, 1);
}

void DFS(int number, int jarisu)
{
	// 이미 방문했다면 종료
	if (jarisu == N) // 현재까지의 자리수가 목표 자리수 n과 같다면
	{
		if (isPrime(number)) // 현재 수가 소수인지 확인
		{
			cout << number << "\n"; // 출력
		}
		return;
	}

	// 생성하려는 수의 각 자릿수가 0부터 9까지의 숫자 중 하나여야 하기 때문
	for (int i = 1; i < 10; i++)
	{
		if (i % 2 == 0) // 짝수이면 탐색할 필요 없음
		{
			continue;
		}
		// 소수이면 재귀로 자릿수를 늘림
		if (isPrime(number * 10 + i)) // 2,3,5,7이면
		{
			DFS(number * 10 + i, jarisu + 1);
		}
	}
}

// 소수 판별 함수
bool isPrime(int num)
{
	//if (num < 2) return false;
	for (int i = 2; i <= num / 2; i++)
	{
		if (num % i == 0) return false;
	}
	return true;
}