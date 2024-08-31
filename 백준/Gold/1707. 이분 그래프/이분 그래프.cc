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

void DFS(int node);
static vector<int> answer;
static vector<bool> visit;
static vector<vector<int>> A;
static bool isEven;

int main() {
	// 시간 단축을 위한 구문
	ios::sync_with_stdio(false);    cin.tie(NULL);    cout.tie(NULL);

	/// <summary>
	/// 이분 그래프란?
	/// 정점을 2그룹으로 나눌 수 있되, 같은 그룹의 정점끼리는 간선으로 이어지지 않은 경우
	/// </summary>
	/// <returns></returns>

	int t; cin >> t; // 테스트 케이스 자체가 노드의 개수와 동일
	for (int i = 0; i < t; i++)
	{
		int V, E;
		cin >> V >> E;
		A.resize(V + 1);
		visit.resize(V + 1);
		answer.resize(V + 1);
		isEven = true;

		for (int j = 0; j < E; j++)
		{
			int S, E;
			cin >> S >> E;
			A[S].push_back(E);
			A[E].push_back(S);
			// 무방향 그래프이므로 양방향으로 추가
		}
		// 주어진 그래프가 하나로 연결된다는 보장이 없으므로 모든 노드에서 수행
		for (int i = 1; i <= V; i++)
		{
			if (isEven)
			{
				DFS(i);
			}
			else // 이분 그래프가 아니라고 판단되면 종료
			{
				break;
			}
		}
		if (isEven)
		{
			cout << "YES" << "\n";
		}
		else
		{
			cout << "NO" << "\n";
		}
		for (int i = 0; i <= V; i++)
		{
			A[i].clear();
			visit[i] = false; // 다음 tc를 위해 초기화
			answer[i] = 0;
		}
	}
}

void DFS(int node)
{
	visit[node] = true;
	for (int i : A[node])
	{
		if (!visit[i])
		{
			// 1또는 0
			// 인접한 노드는 같은 집합이 아니므로 이전 노드와 다른 집합으로 처리
			// 이분 그래프인지 확인하기 위해 사용
			answer[i] = (answer[node] + 1) % 2;
			DFS(i);
		}
		else if (answer[node] == answer[i])
		{
			// 이미 방문한 노드가 현재 노드와 같은 집합이면 이분 그래프가 아님
			isEven = false;
		}
	}
}