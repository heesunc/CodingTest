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

static vector<vector <int>> A; // 그래프 데이터 저장 인접 리스트
static vector<bool> visited;
static int N, M;
static bool arrive; // 방문 기록 저장 배열
static int C = -1;
void BFS(int v);

int main() {
	ios::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);

	//int N, M; // N개의 줄에 M개의 정수로 미로가 주어짐
	cin >> N;
	cin >> M;
	
	A.resize(N + 1);
	visited = vector<bool>(N + 1, false);	

	for (int i = 0; i < M; i++)
	{
		int s, e; cin >> s >> e;
		A[s].push_back(e);
		A[e].push_back(s);
	}

	BFS(1);
	cout << C << "\n";
}

void BFS(int v)
{
	queue<int> q;
	q.push(v);
	visited[v] = true;

	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		//cout << x << " ";
		C++;

		for (int i : A[x])
		{
			if (!visited[i])
			{
				visited[i] = true;
				q.push(i);				
			}
		}
	}
}