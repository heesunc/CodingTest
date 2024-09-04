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

typedef pair<int, int> edge;
static int V, E, K;
static vector<int> mdistance;
static vector<bool> visited;
static vector<vector<edge>> mlist;
static priority_queue<edge, vector<edge>, greater<edge>> q;

int main() {
	ios::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);

	// 정점의 개수V, 간선의 개수E, 시작 정점의 번호K
	cin >> V >> E >> K;
	mdistance.resize(V + 1);
	fill(mdistance.begin(), mdistance.end(), INT_MAX);
	visited.resize(V + 1);
	fill(visited.begin(), visited.end(), false);
	mlist.resize(V + 1);

	// 간선을 나타내는 세 개의 정수 (u, v, w)
	// u에서 v로 가는 가중치 w인 간선
	for (int i = 0; i < E; i++) // 가중치가 있는 인접리스트 초기화
	{
		int u, v, w;
		cin >> u >> v >> w;
		mlist[u].push_back(make_pair(v, w));
	}

	q.push(make_pair(0, K));
	mdistance[K] = 0;

	while (!q.empty())
	{
		edge current = q.top();
		q.pop();
		int c_v = current.second;
		if (visited[c_v]) // 이미 방문한 노드는 다시 큐에 넣지 않음
		{
			continue;
		}
		visited[c_v] = true; // 현재 노드를 방문 노드로 업데이트

		// 현재 선택 노드의 에지 개수
		for (int i = 0; i < mlist[c_v].size(); i++)
		{
			edge tmp = mlist[c_v][i];
			int next = tmp.first;
			int value = tmp.second;

			// 타깃 노드 방문 전 && 현재 선택 노드 최단 거리 + 비용 < 타깃 노드의 최단 거리
			if (mdistance[next] > mdistance[c_v] + value)
			{
				// 최소 거리로 업데이트
				mdistance[next] = value + mdistance[c_v];
				// 우선 순위 큐에 타깃 노드 추가
				q.push(make_pair(mdistance[next], next));
			}
		}
	}
	for (int i = 1; i <= V; i++)
	{
		if (visited[i])
		{
			cout << mdistance[i] << "\n";
		}
		else
		{
			cout << "INF" << "\n";
		}
	}
}