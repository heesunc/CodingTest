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

#define X first
#define Y second

//int board[502][502];
//bool vis[502][502]; // 해당 칸을 방문했는지 여부 저장

string board[1002];
int dist1[1002][1002]; // 불의 전파 시간
int dist2[1002][1002]; // 지훈이의 이동 시간
int n, m; // n행, m열
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 }; // 상하좌우 네 방향

int main()
{
	ios::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		// dist1과 dist2를 처음부터 끝까지 -1로 채움
		fill(dist1[i], dist1[i] + m, -1);
		fill(dist2[i], dist2[i] + m, -1);
	}

	for (int i = 0; i < n; i++)
	{
		cin >> board[i];
	}

	queue<pair<int, int>> Q1;
	queue<pair<int, int>> Q2;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] == 'F')
			{
				Q1.push({ i,j });
				dist1[i][j] = 0;
			}
			if (board[i][j] == 'J')
			{
				Q2.push({ i,j });
				dist2[i][j] = 0;
			}
		}
	}

	// 불에 대한 BFS
	while (!Q1.empty())
	{
		auto cur = Q1.front(); Q1.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (dist1[nx][ny] >= 0 || board[nx][ny] == '#') continue;
			dist1[nx][ny] = dist1[cur.X][cur.Y] + 1; // 새로운 위치에 대한 거리 갱신
			Q1.push({ nx,ny });
		}
	}

	// 지훈이에 대한 BFS
	while (!Q2.empty())
	{
		auto cur = Q2.front(); Q2.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			// 범위를 벗어나면
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
			{
				// 탈출 성공. 최초 탈출 시간 출력
				cout << dist2[cur.X][cur.Y] + 1;
				return 0;
			}
			if (dist2[nx][ny] >= 0 || board[nx][ny] == '#') continue;
			if (dist1[nx][ny] != -1 && dist1[nx][ny] <= dist2[cur.X][cur.Y] + 1) continue;
			// 불의 전파 시간을 조건에 추가
			dist2[nx][ny] = dist2[cur.X][cur.Y] + 1;
			Q2.push({ nx,ny });
		}
	}
	cout << "IMPOSSIBLE"; // 실패
}