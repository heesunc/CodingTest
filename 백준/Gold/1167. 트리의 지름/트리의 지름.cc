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

using namespace std;  // 표준 라이브러리(std)의 네임스페이스를 사용함

typedef pair<int, int> edge; // <노드, 가중치>
static vector<vector <edge>> A; // 인접리스트
static vector<bool> visited; // BFS 방문 여부
static vector<int> m_distance; // 특정 노드로부터 거리 저장
void BFS(int node);

int main() {
	// 시간 단축을 위한 구문
	ios::sync_with_stdio(false);    cin.tie(NULL);    cout.tie(NULL);

	int N; cin >> N; A.resize(N + 1); // 노드 개수 입력

	for (int i = 0; i < N; i++) // 입력 받아서 트리 구성
	{
		int S; cin >> S;
		while (true)
		{
			int E, V;
			cin >> E;
			if (E == -1)
			{
				break;
			}
			cin >> V;
			A[S].push_back(edge(E, V)); // 인접리스트 A에 저장
		}
	}
    
    // 초기화 후 노드 1부터 각 노드까지의 거리 계산
	m_distance = vector<int>(N + 1, 0);
	visited = vector<bool>(N + 1, false);
	BFS(1);
	int Max = 1;

	for (int i = 2; i <= N; i++)
	{
		if (m_distance[Max] < m_distance[i])
		{
			Max = i;
		}
	}
	fill(m_distance.begin(), m_distance.end(), 0); 	// 거리 배열 초기화
	fill(visited.begin(), visited.end(), false); // 방문 배열 초기화
	BFS(Max); // 거리 배열에서 가장 큰 값을 다시 시작점으로 지정
	sort(m_distance.begin(), m_distance.end()); // 최댓값 출력을 위해.. max_element로도 가능
    cout << m_distance[N] << "\n";
}

void BFS(int index)
{
	queue<int> myqueue;
	myqueue.push(index);
	visited[index] = true;

	while (!myqueue.empty())
	{
		int now_node = myqueue.front();
		myqueue.pop();
		for (edge i : A[now_node])
		{
			if (!visited[i.first])
			{
				visited[i.first] = true;
				myqueue.push(i.first);
				// 거리 배열 업데이트
				m_distance[i.first] = m_distance[now_node] + i.second;
			}
		}
	}
}