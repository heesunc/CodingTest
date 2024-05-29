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

using namespace std;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

queue<pair<int, int>> q;
queue<pair<int, int>> s;

char board[1002][1002];
int fire[1002][1002];
int jihun[1002][1002];

void initialize(int r, int c) {
    while (!q.empty()) q.pop();
    while (!s.empty()) s.pop();
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            fire[i][j] = -1;
            jihun[i][j] = -1;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        // 초기화
        bool success = false;
        int r, c;
        cin >> c >> r;
        initialize(r, c);

        // 입력 받기
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> board[i][j];

                if (board[i][j] == '*') {
                    q.push({ i, j });
                    fire[i][j] = 0;
                }
                if (board[i][j] == '@') {
                    s.push({ i, j });
                    jihun[i][j] = 0;
                }
            }
        }

        // 시간에 따른 불의 위치
        while (!q.empty()) {
            pair<int, int> current = q.front();
            q.pop();

            for (int dir = 0; dir < 4; dir++) {
                int x = current.first + dx[dir];
                int y = current.second + dy[dir];

                if (x < 0 || x >= r || y < 0 || y >= c) continue;
                if (fire[x][y] >= 0 || board[x][y] == '#') continue; // 이미 불이 있거나 벽이라면 패스

                fire[x][y] = fire[current.first][current.second] + 1;
                q.push({ x, y });
            }
        }

        // 시간에 따른 지훈이의 위치
        while (!s.empty() && !success) {
            pair<int, int> current = s.front();
            s.pop();

            for (int dir = 0; dir < 4; dir++) {
                int x = current.first + dx[dir];
                int y = current.second + dy[dir];

                // 미로 탈출시 종료
                if (x < 0 || x >= r || y < 0 || y >= c) {
                    cout << jihun[current.first][current.second] + 1 << "\n";
                    success = true;
                    break;
                }

                // 이미 방문했거나 벽이 있으면 패스
                if (jihun[x][y] >= 0 || board[x][y] == '#') continue;

                // 가려는 곳에 불이 이미 있다면 패스
                if (fire[x][y] != -1 && jihun[current.first][current.second] + 1 >= fire[x][y]) continue;

                jihun[x][y] = jihun[current.first][current.second] + 1;
                s.push({ x, y });
            }
        }

        // 탈출 실패
        if (!success) {
            cout << "IMPOSSIBLE\n";
        }
    }
    return 0;
}