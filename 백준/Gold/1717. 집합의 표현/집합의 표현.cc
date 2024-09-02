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

static vector<int> parent;
void unionfunc(int a, int b);
int find(int a);
bool checkSame(int a, int b);

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	parent.resize(N + 1);

	// 대표 노드를 자기 자신으로 초기화
	for (int i = 0; i <= N; i++)
	{
		parent[i] = i;
	}
	for (int i = 0; i < M; i++)
	{
		int question, a, b;
		cin >> question >> a >> b;

		// 집합 합치기

		if (question == 0)
		{
			unionfunc(a, b);
		}
		// 같은 집합의 원소인지 확인
		else
		{
			if (checkSame(a, b))
			{
				cout << "YES" << "\n";
			}
			else
			{
				cout << "NO" << "\n";
			}
		}
	}
}

// union : 바로 연결이 아닌 대표 노드끼리 연결
void unionfunc(int a, int b)
{
	a = find(a);
	b = find(b);

	if (a != b)
	{
		parent[b] = a;
	}
}

// find : 대표 노드를 찾아서 반환
int find(int a)
{
	if (a == parent[a])
	{
		return a;
	}
	else
	{
		return parent[a] = find(parent[a]); // 재귀 함수로 구현
	}
}

// 두 원소가 같은 집합인지 확인
bool checkSame(int a, int b)
{
	a = find(a);
	b = find(b);

	if (a == b)
	{
		return true;
	}
	return false;
}