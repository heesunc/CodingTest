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

vector<tuple<int, int, int>> A[10]; // 각 노드마다 연결된 노드와 비율을 저장
long my_lcm; // 최소 공배수
bool visited[10]; // 방문 여부 체크 배열
long D[10]; // 각 노드의 값을 저장
long gcd(long a, long b); // 최대 공약수를 구하는 함수
void DFS(int node);

int main() {
	// 시간 단축을 위한 구문
	ios::sync_with_stdio(false);    cin.tie(NULL);    cout.tie(NULL);

	int N; cin >> N;
	my_lcm = 1;

	for (int i = 0; i < N - 1; i++)
	{
		int a, b, p, q;
		cin >> a >> b >> p >> q;
		A[a].push_back(make_tuple(b, p, q));
		A[b].push_back(make_tuple(a, q, p));
		// 두 수의 최소 공배수는 두 수의 곱을 최대 공약수로 나눈 것
		my_lcm *= (p * q / gcd(p, q));
	}

	D[0] = my_lcm; // 첫 번째 노드의 값을 LCM으로 초기화
	DFS(0); // DFS를 통해 모든 노드의 값 계산
	long mgcd = D[0]; // 모든 노드의 값의 최대 공약수 계산

	for (int i = 1; i < N; i++)
	{
		mgcd = gcd(mgcd, D[i]);
	}

	for (int i = 0; i < N; i++)
	{
		cout << D[i] / mgcd << ' '; // 최대 공약수로 나눈 값을 출력
	}
}

// 재귀를 사용한 유클리드 알고리즘
long gcd(long a, long b)
{
	if (b == 0)
	{
		return a;
	}
	else
	{
		return gcd(b, a % b);
	}
}

void DFS(int node)
{
	visited[node] = true;

	for (tuple<int, int, int> i : A[node])
	{
		int next = get<0>(i);
		if (!visited[next])
		{
			// 주어진 비율로 다음 노드값 업데이트
			D[next] = D[node] * get<2>(i) / get<1>(i);
			DFS(next);
		}
	}
}