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

int n, m; // 학생의 수, 키를 비교한 횟수
vector<int> inDegree, result;
vector<vector<int>> graph; // 간선의 정보

void input();
void topology_sort();

int main() {
	ios::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);

	input();
	topology_sort();

	for (int i = 0; i < n; i++) {
		cout << result[i] << " ";
	}
}

void input() {
	cin >> n >> m;
	inDegree.assign(n + 1, 0); // n+1크기만큼 벡터에 0을 채움
	result.assign(n + 1, 0);
	graph.assign(n + 1, vector<int>(0, 0));

	for (int i = 0; i < m; i++) {
		int a, b; // a가 b의 앞에 서야 한다
		cin >> a >> b;
		graph[a].emplace_back(b);
		inDegree[b]++;
	}
}

void topology_sort() {
	queue<int> q;
	// 진입차수가 0인 정점들을 큐에 삽입
	for (int i = 1; i <= n; i++) {
		if (inDegree[i] == 0)    q.push(i);
	}

	for (int i = 0; i < n; i++) {
		// 총 n번 반복하기 전에 큐가 비어있다면 사이클이 있다는 것
		if (q.empty())   return;
		int cur = q.front(); // 현재 방문한 노드의 번호
		result[i] = cur; // 방문 결과 저장
		q.pop();

		// 현재 노드와 연결된 노드 중 진입차수가 0인 노드가 있다면 큐에 삽입
		for (int k = 0; k < graph[cur].size(); k++) {
			int next = graph[cur][k];
			if (--inDegree[next] == 0)   q.push(next);
		}
	}
}