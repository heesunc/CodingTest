#include <string>       // 문자열 처리를 위한 헤더 파일
#include <iostream>     // 입출력을 위한 헤더 파일
#include <vector>       // 동적 배열(vector)을 사용하기 위한 헤더 파일
#include <algorithm>    // 알고리즘 함수 (예: fill())를 사용하기 위한 헤더 파일
#include <stack>        // 스택 자료구조를 사용하기 위한 헤더 파일
#include <queue>        // 큐 및 우선순위 큐(priority_queue)를 사용하기 위한 헤더 파일
#include <deque>        // 덱(Deque, 양방향 큐)을 사용하기 위한 헤더 파일
#include <cctype>       // 문자 처리를 위한 헤더 파일
#include <stdlib.h>     // 문자열을 숫자로 변환하는 함수(예: atoi())를 위한 헤더 파일
#include <cmath>        // 수학 함수를 사용하기 위한 헤더 파일
#include <unordered_map> // 해시맵(unordered_map)을 사용하기 위한 헤더 파일
#include <map>          // 맵(map, 정렬된 딕셔너리)을 사용하기 위한 헤더 파일
#include <sstream>      // 문자열 스트림을 사용하기 위한 헤더 파일
#include <cstdlib>      // 유틸리티 함수(예: rand(), exit())를 위한 헤더 파일
#include <iomanip>      // 입출력 서식을 지정하기 위한 헤더 파일
#include <climits>      // INT_MAX(최대 정수값)을 사용하기 위한 헤더 파일
#include <numeric>      // accumulate(누적 합)를 사용하기 위한 헤더 파일

using namespace std;  // std 네임스페이스를 사용하여 std::를 생략 가능하게 함

// Node는 (거리, 노드 번호)의 쌍을 의미
typedef pair<int, int> Node;
static int N, M, K;  // N: 노드(도시) 수, M: 에지(도로) 수, K: K번째 최단 경로를 구하기 위한 변수
static int W[1001][1001];  // W는 그래프의 인접 행렬로, W[a][b]는 a에서 b로 가는 가중치
static priority_queue<int> distQueue[1001];  // 각 노드까지의 K번째 최단 경로를 저장하는 우선순위 큐 배열

int main() {
    // 입출력 속도를 높이기 위한 설정
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 노드 수 N, 에지 수 M, 구할 K번째 경로 입력
    cin >> N >> M >> K;

    // M개의 에지 정보를 입력받아 인접 행렬에 저장
    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        // a에서 b로 가는 가중치 c 입력
        cin >> a >> b >> c;
        W[a][b] = c;
    }

    // 우선순위 큐를 이용해 다익스트라 알고리즘을 변형한 방식으로 시작
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    pq.push(make_pair(0, 1));  // 시작점(1번 노드)에서의 거리 0을 큐에 삽입
    distQueue[1].push(0);  // 1번 노드까지의 최단 거리를 0으로 초기화

    // 다익스트라 알고리즘 수행
    while (!pq.empty())
    {
        Node u = pq.top();  // 가장 짧은 거리의 노드를 꺼냄
        pq.pop();

        // 현재 노드 u에서 인접한 다른 노드로 이동하는 경로 탐색
        for (int adjNode = 1; adjNode <= N; adjNode++)
        {
            // u.second에서 adjNode로의 경로가 존재하면
            if (W[u.second][adjNode] != 0)
            {
                // 아직 adjNode의 경로가 K개 미만이라면
                if (distQueue[adjNode].size() < K)
                {
                    // 경로 추가
                    distQueue[adjNode].push(u.first + W[u.second][adjNode]);
                    pq.push(make_pair(u.first + W[u.second][adjNode], adjNode));
                }
                // adjNode의 경로가 K개 이상이고, 새로운 경로가 기존 경로보다 짧다면
                else if (distQueue[adjNode].top() > u.first + W[u.second][adjNode])
                {
                    distQueue[adjNode].pop();  // 가장 긴 경로를 제거하고
                    distQueue[adjNode].push(u.first + W[u.second][adjNode]);  // 새로운 경로를 추가
                    pq.push(make_pair(u.first + W[u.second][adjNode], adjNode));
                }
            }
        }
    }

    // 각 노드에 대해 K번째 최단 경로 출력
    for (int i = 1; i <= N; i++)
    {
        // 만약 K번째 경로가 있다면, 해당 경로 출력
        if (distQueue[i].size() == K)
        {
            cout << distQueue[i].top() << "\n";
        }
        // 없다면 -1 출력
        else
        {
            cout << -1 << "\n";
        }
    }
}
