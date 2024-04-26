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

using namespace std;  // 표준 라이브러리(std)의 네임스페이스를 사용함

static vector<vector <int>> A; // 그래프의 인접 리스트 저장
static vector<bool> visited;  // 노드의 방문 여부
void DFS(int v);

int main() {
	ios::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);

	int N, M; cin >> N >> M;
	A.resize(N + 1);
	visited = vector<bool>(N + 1, false);
	// 노드 번호가 1번부터 시작하기 때문에 +1을 해주는 것

	//  각 노드에 연결된 간선의 정보가 A 벡터에 저장
	for (int i = 0; i < M; i++)
	{
		int s, e; cin >> s >> e;
		A[s].push_back(e);
		A[e].push_back(s);
	}

	// 연결 요소의 개수 세기
	int count = 0;
	
	for (int i = 1; i < N + 1; i++)
	{
		// 방문하지 않은 노드가 없을 때까지 반복
		if (!visited[i])
		{
			count++;
			DFS(i);
		}
	}
	cout << count << "\n";
}

void DFS(int v)
{
	// 이미 방문했다면 종료
	if (visited[v])
	{
		return;
	}

	// 방문했다고 표시
	visited[v] = true;

	for (int i : A[v])
	{
		// 연결 노드 중 방문하지 않은 노드만 탐색
		if (visited[i] == false)
		{
			DFS(i);
		}
	}
}