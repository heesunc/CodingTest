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

int board[52][52];
bool vis[52][52]; // 해당 칸을 방문했는지 여부 저장
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 }; // 상하좌우 네 방향

void resetBoardAndVis(int n, int m) {
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            board[y][x] = 0;
            vis[y][x] = 0;
        }
    }
}

void processInput(int k) {
    for (int j = 0; j < k; j++) {
        int x, y;
        cin >> x >> y;
        board[y][x] = 1;
    }
}

void BFS(int y, int x, int n, int m) {
    queue<pair<int, int>> Q;
    vis[y][x] = 1;
    Q.push({ y, x });

    while (!Q.empty()) {
        pair<int, int> cur = Q.front(); Q.pop();

        // 상하좌우 칸을 살펴본다
        for (int dir = 0; dir < 4; dir++) {
            int ny = cur.X + dy[dir];
            int nx = cur.Y + dx[dir];

            if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue; // 범위 밖일 경우 넘어감
            if (vis[ny][nx] || board[ny][nx] != 1) continue; // 이미 방문한 칸이거나 1이 아닐 경우
            vis[ny][nx] = 1; // 방문 명시
            Q.push({ ny, nx });
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n, m, k;
        cin >> m >> n >> k;

        resetBoardAndVis(n, m);
        processInput(k);

        int num = 0; // 그림의 수

        for (int y = 0; y < n; y++) {
            for (int x = 0; x < m; x++) {
                if (board[y][x] == 0 || vis[y][x]) continue; // 0이거나 방문했으면 넘어감
                BFS(y, x, n, m);
                num++;
            }
        }
        cout << num << "\n";
    }

    return 0;
}