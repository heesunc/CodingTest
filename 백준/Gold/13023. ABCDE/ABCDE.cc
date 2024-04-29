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
static vector<bool> visited; // 방문 기록 저장 배열
static bool arrive; // 방문 기록 저장 배열
void DFS(int now, int depth);

int main() {
	ios::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);

	int N, M; // 노드, 에지 개수
	arrive = false;
	cin >> N >> M;
	A.resize(N); // 크기 노드만큼 resize
	visited = vector<bool>(N, false);

	for (int i = 0; i < M; i++) // 에지 정보 입력 받기
	{
		// 양방향 그래프 생성
		int s, e;
		cin >> s >> e;
		A[s].push_back(e); 
		A[e].push_back(s);
	}

	// 노드마다 DFS 실행
	for (int i = 0; i < N; i++)
	{
		DFS(i, 1);
		if (arrive)
		{
			break;
		}
	}

	if (arrive) // 목표에 도달한 경우
	{
		cout << 1 << "\n";
	}
	else //  목표에 도달하지 못한 경우
	{
		cout << 0 << "\n";
	}
}

void DFS(int now, int depth)
{
	if (depth == 5 || arrive) // 깊이가 5가 되거나 목표에 도달했다면 종료
	{
		arrive = true;
		return;
	}
	visited[now] = true; // 현재 노드를 방문했다고 표시

	for (int i : A[now]) // 현재 노드와 연결된 모든 노드에 대해 반복
	{
		if (!visited[i]) // 방문하지 않은 노드라면
		{
			DFS(i, depth + 1); // 재귀 호출 시 depth를 1씩 증가하여 호출하기
		}
	}
	visited[now] = false; // 현재 노드를 방문하지 않은 상태로 되돌림
	/*모든 경로에 대해 탐색을 마친 후에도 arrive 변수가 true로 설정되어 있으면 
	함수가 종료되므로, 이미 방문한 노드를 되돌리는 것이 중요.*/
}