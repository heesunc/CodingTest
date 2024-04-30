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

int N, M, K;
vector<int> connect[100001];
int check[100001];

void bfs(int start) {
    int Visit = 1;
    queue<int> q;
    q.push(start);
    check[start] = Visit++;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i = 0; i < connect[x].size(); i++) {
            int xx = connect[x][i];
            if (check[xx] == 0) {
                check[xx] = Visit++;
                q.push(xx);
            }
        }
    }
}

void solve() {
    for (int i = 1; i <= N; i++) {
        sort(connect[i].begin(), connect[i].end(), greater<int>());
    }
    bfs(K);
    for (int i = 1; i <= N; i++) {
        cout << check[i] << "\n";
    }
}

int main() {
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M >> K;
    for (int i = 1; i <= M; i++) {
        int x, y;
        cin >> x >> y;
        connect[x].push_back(y);
        connect[y].push_back(x);
    }
    solve();
    return 0;
}