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

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

queue<pair<int, int>> Q;

string board[1002];
int vis[1002][1002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        cin >> board[i];
    }

    int count = 0; // 총 단지수
    vector <int> ans; // 단지내 집의 수

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == '0' || vis[i][j] == 1) continue;
            vis[i][j] = 1;
            Q.push({ i,j });
            int width = 1;
            count++;

            while (!Q.empty())
            {
                auto cur = Q.front(); Q.pop();
                for (int dir = 0; dir < 4; dir++)
                {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if (board[nx][ny] == '0' || vis[nx][ny] == 1) continue;
                    Q.push({ nx, ny });
                    vis[nx][ny] = 1;
                    width++;
                }
            }
            ans.push_back(width);
        }
    }

    cout << count << "\n";
    sort(ans.begin(), ans.end());

    for (int i : ans)
        cout << i << '\n';
    
    return 0;
}