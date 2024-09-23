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

static int N, M;  // N: 노드의 수, M: LCA를 구할 쿼리의 수
static vector<vector<int>> tree;  // 트리의 인접 리스트
static vector<int> depth;  // 각 노드의 깊이를 저장하는 벡터
static int kmax;  // 2^k에서 사용할 최대 k값 (트리의 높이에 따라 결정됨)
static int parent[21][100001];  // 각 노드의 부모 노드 정보를 저장하는 2차원 배열, 21은 log2(100001) 정도로 kmax의 최대값
static vector<bool> visited;  // 방문 여부를 저장하는 벡터
int executeLCA(int a, int b);  // LCA를 찾는 함수 선언
void BFS(int node);  // BFS를 통해 트리의 깊이와 부모를 설정하는 함수 선언

int main() {
    ios::sync_with_stdio(false);  // 입출력 성능 향상을 위해 C 표준 스트림과의 동기화 비활성화
    cin.tie(NULL);  // 입출력의 동기화를 해제하여 성능을 향상
    cout.tie(NULL); // 출력 동기화를 해제하여 성능 향상

    cin >> N;  // N: 노드의 수 입력
    tree.resize(N + 1);  // 트리의 인접 리스트 크기를 N+1로 설정

    // 트리 간선 정보 입력
    for (int i = 0; i < N - 1; i++)
    {
        int s, e;
        cin >> s >> e;
        tree[s].push_back(e);  // 양방향 간선 추가
        tree[e].push_back(s);  // 양방향 간선 추가
    }

    depth.resize(N + 1);  // 각 노드의 깊이를 저장할 벡터 크기 설정
    visited.resize(N + 1);  // 방문 여부를 저장할 벡터 크기 설정

    int temp = 1;
    kmax = 0;

    // kmax 설정: N보다 작은 가장 큰 2의 거듭제곱을 구함 (log2(N)에 해당)
    while (temp <= N)
    {
        temp <<= 1;  // temp를 왼쪽으로 시프트하여 2배로 만듦
        kmax++;  // kmax는 트리의 최대 깊이에 따른 최대 k값을 결정
    }

    BFS(1);  // BFS를 사용해 1번 노드를 루트로 트리의 깊이와 부모 관계 설정

    // 모든 노드에 대해 2^k 번째 부모를 계산 (Sparse Table 생성)
    for (int k = 1; k <= kmax; k++)
    {
        for (int n = 1; n <= N; n++)
        {
            parent[k][n] = parent[k - 1][parent[k - 1][n]];  // 2^k 번째 부모는 2^(k-1) 번째 부모의 부모
        }
    }

    cin >> M;  // M: LCA 쿼리 수 입력

    // M개의 쿼리 처리
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        int LCA = executeLCA(a, b);  // 두 노드 a와 b의 LCA 계산
        cout << LCA << "\n";  // 결과 출력
    }
}

// 두 노드 a와 b의 LCA(최소 공통 조상)를 계산하는 함수
int executeLCA(int a, int b)
{
    // 깊이가 다른 경우 깊이를 맞추기 위해 b를 더 높은 깊이로 변경
    if (depth[a] > depth[b])
    {
        swap(a, b);  // a와 b를 스왑하여 항상 b가 더 깊은 노드가 되도록 함
    }

    // 깊이를 맞추기 위해 b를 부모 노드 방향으로 올림
    for (int k = kmax; k >= 0; k--)
    {
        if (pow(2, k) <= depth[b] - depth[a])  // a와 b의 깊이 차가 2^k 이상일 경우
        {
            if (depth[a] <= depth[parent[k][b]])  // a의 깊이와 같아질 때까지 b를 올림
            {
                b = parent[k][b];  // b를 2^k만큼 위로 이동
            }
        }
    }

    // 깊이를 맞춘 후, a와 b가 같아질 때까지 부모를 계속 올림
    for (int k = kmax; k >= 0 && a != b; k--)
    {
        if (parent[k][a] != parent[k][b])  // 부모가 같지 않을 경우
        {
            a = parent[k][a];  // a를 2^k만큼 올림
            b = parent[k][b];  // b를 2^k만큼 올림
        }
    }

    int LCA = a;  // a를 LCA로 가정

    // a와 b가 같지 않을 경우, 한 번 더 부모로 이동
    if (a != b)
    {
        LCA = parent[0][LCA];  // 한 단계 부모로 이동
    }
    return LCA;  // 최소 공통 조상을 반환
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
                parent[0][next] = now_node;  // 현재 노드를 인접 노드의 부모로 설정
                depth[next] = level;  // 인접 노드의 깊이를 현재 레벨로 설정
            }
        }

        count++;  // 현재 레벨에서 처리한 노드 수 증가

        // 현재 레벨의 모든 노드를 처리한 경우
        if (count == now_size)
        {
            count = 0;  // 처리한 노드 수 초기화
            now_size = myqueue.size();  // 다음 레벨의 노드 수 갱신
            level++;  // 레벨 증가
        }
    }
}
