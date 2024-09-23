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
#include <limits.h>     // 시스템 한계값들을 정의하는 헤더 파일 (ex: LONG_MAX)

using namespace std;

static int N, M;  // N: 노드의 수, M: 쿼리(두 노드 간의 LCA를 찾는 요청) 수
static vector<vector<int>> tree;  // 트리의 인접 리스트
static vector<int> depth;  // 각 노드의 깊이를 저장하는 벡터
static vector<int> parent;  // 각 노드의 부모 노드를 저장하는 벡터
static vector<bool> visited;  // 방문 여부를 저장하는 벡터
int executeLCA(int a, int b);  // LCA를 찾는 함수 선언
void BFS(int node);  // BFS를 통해 트리의 깊이와 부모를 설정하는 함수 선언

int main() {
    ios::sync_with_stdio(false);  // C++ 입출력 성능 향상을 위해 C 표준 스트림과의 동기화 비활성화
    cin.tie(NULL);  // 입출력의 동기화를 해제하여 성능을 향상
    cout.tie(NULL); // 출력 동기화를 해제하여 성능 향상

    cin >> N;  // N: 노드의 수 입력

    // 트리와 관련된 벡터 크기 조정
    tree.resize(N + 1);  // 트리는 1번 노드부터 시작하므로 N+1 크기로 설정
    depth.resize(N + 1);  // 각 노드의 깊이를 저장할 벡터
    parent.resize(N + 1);  // 각 노드의 부모를 저장할 벡터
    visited.resize(N + 1);  // 각 노드의 방문 여부를 저장할 벡터

    // 트리 구성 입력 (N-1개의 간선)
    for (int i = 0; i < N - 1; i++)
    {
        int s, e;
        cin >> s >> e;
        tree[s].push_back(e);  // 양방향 간선을 트리에 추가
        tree[e].push_back(s);  // 양방향 간선을 트리에 추가
    }

    BFS(1);  // BFS를 이용하여 1번 노드를 루트로 트리의 깊이와 부모 관계 설정
    cin >> M;  // M: LCA를 구할 쿼리의 수 입력

    // M개의 쿼리 처리
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        int LCA = executeLCA(a, b);  // a와 b의 LCA 계산
        cout << LCA << "\n";  // 결과 출력
    }
}

// 두 노드 a와 b의 LCA(최소 공통 조상)를 계산하는 함수
int executeLCA(int a, int b)
{
    // 두 노드의 깊이가 다를 경우 깊이를 맞추기 위해 더 깊은 노드를 부모 방향으로 이동
    if (depth[a] < depth[b])
    {
        // a가 더 깊은 노드가 되도록 스왑
        int temp = a;
        a = b;
        b = temp;
    }

    // a와 b의 깊이가 같아질 때까지 a를 부모 노드로 이동
    while (depth[a] != depth[b])
    {
        a = parent[a];  // a를 부모 노드로 이동
    }

    // 깊이를 맞춘 후, a와 b가 다를 경우 부모를 계속 따라가면서 LCA를 찾음
    while (a != b)
    {
        a = parent[a];  // a를 부모 노드로 이동
        b = parent[b];  // b도 부모 노드로 이동
    }

    // a와 b가 같은 노드가 되면 해당 노드가 LCA
    return a;
}

// BFS를 이용하여 트리의 각 노드의 깊이와 부모를 설정하는 함수
void BFS(int node)
{
    queue<int> myqueue;  // BFS를 위한 큐
    myqueue.push(node);  // 루트 노드를 큐에 삽입
    visited[node] = true;  // 루트 노드를 방문 처리
    int level = 1;  // 현재 레벨 (루트 노드의 자식 노드부터 레벨 1)
    int now_size = 1;  // 현재 레벨에 있는 노드의 수
    int count = 0;  // 현재 레벨에서 처리한 노드의 수

    // 큐가 빌 때까지 BFS 수행
    while (!myqueue.empty())
    {
        int now_node = myqueue.front();  // 큐에서 현재 노드를 꺼냄
        myqueue.pop();

        // 현재 노드의 인접 노드들 처리
        for (int next : tree[now_node])  // 현재 노드의 인접 노드들 순회
        {
            if (!visited[next])  // 아직 방문하지 않은 노드일 경우
            {
                visited[next] = true;  // 방문 처리
                myqueue.push(next);  // 인접 노드를 큐에 삽입
                parent[next] = now_node;  // 현재 노드를 인접 노드의 부모로 설정
                depth[next] = level;  // 인접 노드의 깊이를 현재 레벨로 설정
            }
        }

        count++;  // 현재 레벨에서 처리한 노드 수 증가

        // 현재 레벨의 모든 노드를 처리한 경우
        if (count == now_size)
        {
            count = 0;  // 처리한 노드 수 초기화
            now_size = myqueue.size();  // 다음 레벨의 노드 수
            level++;  // 레벨 증가
        }
    }
}
