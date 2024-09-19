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
#include <limits.h>

using namespace std; // std 네임스페이스를 사용하여 std::를 생략 가능하게 함

void munion(int a, int b);
int find(int a);
static vector<int> parent;

// 에지 정보 구조체 생성, 가중치 값 기준 오름차순 정렬로 설정
typedef struct Edge
{
    int s, e, v;
    bool operator > (const Edge& temp) const {
        return v > temp.v;
    }
} Edge;

int main() {
    // 입출력 속도를 높이기 위한 설정
    ios::sync_with_stdio(false);  // C와 C++의 입출력 버퍼를 분리하여 성능 향상
    cin.tie(NULL);  // 입력 속도 향상을 위해 입력과 출력의 묶음을 풀음
    cout.tie(NULL);  // 출력 속도 향상을 위해 출력과 입력의 묶음을 풀음

    int N, sum = 0; cin >> N;
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            char tempc = cin.get();

            if(tempc == '\n')
            {
                tempc = cin.get();
            }
            int temp = 0;

            if (tempc >= 'a' && tempc <= 'z')
            {
                temp = tempc - 'a' + 1;
            }
            else if (tempc >= 'A' && tempc <= 'Z')
            {
                temp = tempc - 'A' + 27;
            }
            sum = sum + temp; // 모든 랜선의 길이 저장

            if (i != j && temp != 0)
            {
                pq.push(Edge{ i,j,temp });
            }
        }
    }

    parent.resize(N);

    for (int i = 0; i < N; i++)
    {
        parent[i] = i;
    }

    int useEdge = 0;
    int result = 0;

    while (!pq.empty())
    {
        Edge now = pq.top();
        pq.pop();
        // 같은 부모가 아니라면 (연결해도 사이클이 생기지 않는다면)
        if (find(now.s) != find(now.e))
        {
            munion(now.s, now.e);
            result = result + now.v;
            useEdge++;
        }
    }
    if (useEdge == N - 1)
    {
        cout << sum - result << "\n";
    }
    else
    {
        cout << -1 << "\n";
    }

    //return 0;
}

void munion(int a, int b)
{
    // a와 b의 대표 노드 찾기
    a = find(a);
    b = find(b);

    // 두 원소의 대표 노드끼리 연결하기
    if (a != b)
    {
        parent[b] = a;
    }
}

int find(int a)
{
    // a가 대표 노드면 반환
    if (a == parent[a])
    {
        return a;
    }
    else // a의 대표 노드 값을 find(parent[a]) 값으로 저장
    {
        // 재귀 함수 형태로 구현 -> 경로 압축 부분
        return parent[a] = find(parent[a]);
    }
}