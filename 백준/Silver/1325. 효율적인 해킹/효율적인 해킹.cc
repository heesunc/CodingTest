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
static vector<bool> visit;
static vector<vector<int>> A;

int main() {
	// 시간 단축을 위한 구문
	ios::sync_with_stdio(false);    cin.tie(NULL);    cout.tie(NULL);

	int N, M; cin >> N >> M;
	A.resize(N + 1); // 노드 번호를 인덱스로 사용하기 때문에
	answer.resize(N + 1);

	// 노드에 에지 추가
	for (int i = 0; i < M; i++)
	{
		int S, E;
		cin >> S >> E;
		A[S].push_back(E);
	}

	visit.resize(N + 1);

	for(int i=1; i<=N; i++)
	{
		// false값으로 visit 배열 미방문 상태로 초기화
		fill(visit.begin(), visit.end(), false);
		BFS(i);
	}	

	// 각 노드에 대해 도달할 수 있는 최대 노드 수를 찾아 저장
	int maxVal = 0;
	for (int i = 1; i <= N; i++)
	{
		maxVal = max(maxVal, answer[i]);
	}

	for (int i = 1; i <= N; i++)
	{
		// answer 배열에서 maxVal와 같은 값을 가진 index를 정답으로 출력
		if (answer[i] == maxVal)
		{
			cout << i << " ";
		}
	}
}

void BFS(int node)
{
	queue<int> queue;
	queue.push(node); // 시작점 삽입
	visit[node] = true; // 시작 노드를 방문한 것으로 표시
	
	while (!queue.empty())
	{
		int now_node = queue.front(); 
		queue.pop();
		for (int i : A[now_node]) // 현재 노드에 인접한 모든 노드 순회
		{ 
			if (visit[i] == false) // 방문되지 않았다면
			{
				visit[i] = true;
				answer[i]++; // 신규 노드 인덱스의 정답 배열값 증가
				queue.push(i); // 인접한 노드를 큐에 추가
			}
		}
	}
}