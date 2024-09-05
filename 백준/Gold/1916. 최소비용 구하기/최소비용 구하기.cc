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

// int형 두 개를 묶는 pair를 edge로 정의, 노드 간 연결을 표현하는 데 사용
typedef pair<int, int> edge;

// 전역 변수 선언
static int N, M;  // N: 노드(도시) 개수, M: 에지(도로) 개수
static vector<int> dist;  // 시작점에서 다른 노드까지의 최단 거리를 저장
static vector<bool> visited;  // 방문 여부를 확인하는 배열
static vector<vector<edge>> mlist;  // 인접 리스트로 그래프를 표현

// 다익스트라 알고리즘을 구현하는 함수 선언
int dijkstra(int start, int end);

int main() {
    // 입출력 속도를 높이기 위한 설정
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 노드 개수(N)와 에지 개수(M) 입력
    cin >> N >> M;

    // 거리 배열(dist)을 노드 개수만큼 크기 조정
    dist.resize(N + 1);
    // 모든 노드에 대해 거리를 무한대(INT_MAX)로 초기화 (처음에는 도달할 수 없다고 가정)
    fill(dist.begin(), dist.end(), INT_MAX);

    // 방문 여부 배열(visited)을 노드 개수만큼 크기 조정
    visited.resize(N + 1);
    // 모든 노드를 아직 방문하지 않은 상태(false)로 초기화
    fill(visited.begin(), visited.end(), false);

    // 인접 리스트(mlist)를 노드 개수만큼 크기 조정
    mlist.resize(N + 1);

    // M개의 에지 정보 입력
    for (int i = 0; i < M; i++) {
        int start, end, weight;
        // 시작 노드(start), 도착 노드(end), 가중치(weight) 입력
        cin >> start >> end >> weight;
        // 인접 리스트에 에지 정보를 저장 (시작 노드에서 도착 노드로의 가중치)
        mlist[start].push_back(make_pair(end, weight));
    }

    // 다익스트라 알고리즘에서 사용할 시작 노드와 목적지 노드 입력
    int startIndex, endIndex;
    cin >> startIndex >> endIndex;

    // 시작 노드에서 다익스트라 알고리즘을 수행하여 최단 경로 계산
    int result = dijkstra(startIndex, endIndex);

    // 결과(최단 거리)를 출력
    cout << result << "\n";
}

// 다익스트라 알고리즘을 구현한 함수
int dijkstra(int start, int end) {
    // 우선순위 큐(priority_queue)를 사용하여 (거리, 노드)를 저장
    priority_queue<edge, vector<edge>, greater<edge>> pq;

    // 시작 노드를 우선순위 큐에 삽입 (거리 0, 시작 노드)
    pq.push(make_pair(0, start));

    // 시작 노드까지의 거리는 0으로 설정
    dist[start] = 0;

    // 우선순위 큐가 비어 있지 않은 동안 반복
    while (!pq.empty()) {
        // 현재 가장 가까운 노드를 큐에서 꺼냄
        edge nowNode = pq.top();
        pq.pop();
        int now = nowNode.second;  // 현재 처리 중인 노드

        // 해당 노드를 아직 방문하지 않았다면
        if (!visited[now]) {
            visited[now] = true;  // 해당 노드를 방문 처리

            // 현재 노드에 인접한 모든 노드들을 확인
            for (edge n : mlist[now]) {
                // 더 짧은 경로가 발견되면 업데이트
                if (dist[n.first] > dist[now] + n.second) {
                    dist[n.first] = dist[now] + n.second;  // 최단 거리 갱신
                    // 갱신된 거리와 노드를 우선순위 큐에 삽입
                    pq.push(make_pair(dist[n.first], n.first));
                }
            }
        }
    }

    // 목적지 노드까지의 최단 거리를 반환
    return dist[end];
}
