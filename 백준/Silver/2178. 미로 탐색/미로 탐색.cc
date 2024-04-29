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

static int dx[] = { 0,1,0,-1 };
static int dy[] = { 1,0,-1,0 };
static int A[101][101];
//static vector<vector <int>> A; // 그래프 데이터 저장 인접 리스트
static bool visited[101][101] = { false }; // 방문 기록 저장 배열
static int N, M;
//static bool arrive; // 방문 기록 저장 배열
void BFS(int i, int j);

int main() {
	ios::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);

	//int N, M; // N개의 줄에 M개의 정수로 미로가 주어짐
	cin >> N >> M;
	
	for (int i = 0; i < N; i++)
	{
		string s; cin >> s;
		for (int j = 0; j < M; j++)
		{
			A[i][j] = s[j] - '0';
		}
	}

	BFS(0, 0);
	cout << A[N - 1][M - 1] << "\n";
}

void BFS(int i, int j)
{
	queue<pair<int, int>> q;
	q.push(make_pair(i, j));

	while (!q.empty())
	{
		int now[2];
		now[0] = q.front().first;
		now[1] = q.front().second;
		q.pop();
		visited[i][j] = true;

		for (int k = 0; k < 4; k++) // 상하좌우 이동에 대해 반복
		{
			// x,y 좌표 계산
			int x = now[0] + dx[k];
			int y = now[1] + dy[k];

			// 좌표 유효성 검사
			if (x >= 0 && y >= 0 && x < N && y < M)
			{
				// 미방문 노드 검사
				if (A[x][y] != 0 && !visited[x][y])
				{
					visited[x][y] = true;
					// 깊이 업데이트, 현재 위치까지의 거리 + 1
					A[x][y] = A[now[0]][now[1]] + 1;
					q.push(make_pair(x, y)); // 새로운 위치 삽입
				}
			}
		}
	}
}