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

int board[1002][1002];
int dist[1002][1002];
int n, m; // n행, m열
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 }; // 상하좌우 네 방향

int main()
{
	ios::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);

	cin >> m >> n;

	queue<pair<int, int>> Q;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 1) // 익은 토마토(1)은 큐에 넣기
				Q.push({ i,j });
			if (board[i][j] == 0) // 익지 않은 토마토(0)은 dist를 -1로 둠
				dist[i][j] = -1;
		}
	}

	while (!Q.empty())
	{
		auto cur = Q.front(); Q.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (dist[nx][ny] >= 0) continue;
			dist[nx][ny] = dist[cur.X][cur.Y] + 1;
			Q.push({ nx,ny });
		}
	}
	int ans = 0; // 익는 데 걸리는 최대 일수를 저장할 변수 초기화
	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < m; j++) 
		{
			if (dist[i][j] == -1) 
			{ // 익지 않은 토마토가 있는지 확인
				cout << -1; // 익지 않은 토마토가 하나라도 있으면 -1 출력
				return 0; // 프로그램 종료
			}
			// 모든 토마토가 익은 경우, 익는 데 걸린 최대 일수를 확인
			ans = max(ans, dist[i][j]); // 현재까지의 최대 일수를 갱신
		}
	}
	cout << ans; // 모든 토마토가 익는 데 걸리는 최대 일수 출력
}