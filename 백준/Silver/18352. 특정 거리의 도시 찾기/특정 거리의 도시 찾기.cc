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

void BFS(int node);
static vector<int> answer;
static vector<int> visit;
static vector<vector<int>> A;

int main() {
	// 시간 단축을 위한 구문
	ios::sync_with_stdio(false);    cin.tie(NULL);    cout.tie(NULL);

	// 도시의 개수 N, 도로의 개수 M, 거리 정보 K, 출발 도시의 번호 X
	// 가중치가 없는 인접 리스트로 구현, BFS

	int N, M, K, X; cin >> N >> M >> K >> X;
	A.resize(N + 1); // 노드 번호를 인덱스로 사용하기 때문에

	// 노드에 에지 추가
	for (int i = 0; i < M; i++)
	{
		int S, E;
		cin >> S >> E;
		A[S].push_back(E);
	}

	visit.resize(N + 1);

	for(int i=0; i<=N; i++)
	{
		visit[i] = -1;
	}

	BFS(X); // 출발 도시의 번호 넣고 BFS 실행

	for (int i = 0; i <= N; i++)
	{
		if (visit[i] == K)
		{
			answer.push_back(i);
		}
	}
	if (answer.empty())
	{
		cout << -1 << "\n";
	}
	else
	{
		sort(answer.begin(), answer.end());
		for (int temp : answer)
		{
			cout << temp << "\n";
		}
	}
}

// X로부터 정확히 K거리만큼 떨어진 모든 노드를 찾기 위함
void BFS(int node)
{
	queue<int> queue;
	queue.push(node); // 시작점 삽입
	visit[node]++; // ++로 시작 노드를 방문한 것으로 표시
	// 처음에는 visit[node]가 -1이므로, 
	// visit[node]++를 하면 0이 되어 시작 노드에서 자기 자신까지의 거리가 0임을 나타냄
	
	while (!queue.empty())
	{
		int now_node = queue.front(); 
		queue.pop();
		for (int i : A[now_node]) // 현재 노드에 인접한 모든 노드 순회
		{ 
			if (visit[i] == -1) // 방문되지 않았다면
			{
				visit[i] = visit[now_node] + 1; // 인접한 노드까지의 거리 설정, 현재 노드 + 1
				queue.push(i); // 인접한 노드를 큐에 추가
			}
		}
	}
}