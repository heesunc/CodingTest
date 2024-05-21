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

int dist[100002];
int n, m; // n행, m열
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 }; // 상하좌우 네 방향

int main()
{
	ios::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);

	cin >> n >> m;

	fill(dist, dist + 100001, -1); // dist 배열을 -1로 초기화
	dist[n] = 0; // 시작 위치의 이동 거리를 0으로 설정
	queue<int> Q;
	Q.push(n); // 시작 위치를 큐에 삽입

	while (dist[m] == -1) // 목표 위치에 도달할 때까지 반복
	{
		int cur = Q.front(); Q.pop(); // 큐에서 현재 위치를 가져옴
		for (int nxt : {cur - 1, cur + 1, 2 * cur}) // 상하좌우 및 현재 위치의 2배로 이동하는 경우 고려
		{
			if (nxt < 0 || nxt > 100000) continue; // 범위를 벗어나는 경우 무시
			if (dist[nxt] != -1) continue; // 이미 방문한 위치인 경우 무시
			dist[nxt] = dist[cur] + 1; // 다음 위치의 이동 거리를 현재 위치의 이동 거리 +1로 설정
			Q.push(nxt); // 다음 위치를 큐에 삽입
		}
	}
	cout << dist[m]; // 목표 위치까지의 최단 이동 거리 출력
}