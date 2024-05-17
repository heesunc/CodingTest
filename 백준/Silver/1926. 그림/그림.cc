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
int board[502][502];
bool vis[502][502]; // 해당 칸을 방문했는지 여부 저장
int n, m; // n행, m열
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 }; // 상하좌우 네 방향

int main()
{
	ios::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];

	int mx = 0; // 그림의 최댓값
	int num = 0; // 그림의 수

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] == 0 || vis[i][j]) continue; // 0이거나 방문했으면 넘어감
			num++;
			queue<pair<int, int>> Q;
			vis[i][j] = 1;
			Q.push({ i,j });
			int area = 0; // 그림의 넓이

			while (!Q.empty())
			{
				area++; // 큐에 들어있는 원소를 하나 뺄 때 마다 넓이를 1 증가
				pair<int, int> cur = Q.front(); Q.pop();
				
				// 상하좌우 칸을 살펴본다
				for (int dir = 0; dir < 4; dir++)
				{
					// nx, ny에 dir에서 정한 방향의 인접한 칸의 좌표가 들어감
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];
					
					if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // 범위 밖일 경우 넘어감
					if (vis[nx][ny] || board[nx][ny] != 1) continue; // 이미 방문한 칸이거나 파란 칸이 아닐 경우
					vis[nx][ny] = 1; // 방문 명시
					Q.push({ nx,ny });
				}
			}
			// (i, j)를 시작점으로 하는 BFS 종료
			mx = max(mx, area); // area가 mx보다 클 경우 mx에 area를 대입
		}
	}
	cout << num << '\n' << mx;	
	return 0;
}