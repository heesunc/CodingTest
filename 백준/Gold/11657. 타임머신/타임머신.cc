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

typedef tuple<int, int, int> edge;  // 3개의 정수를 하나의 튜플로 묶어 edge로 정의
static int N, M;  // N: 정점의 수, M: 간선의 수를 나타내는 정적 변수
static vector<long> mdistance;  // 각 정점까지의 최단 거리를 저장하는 벡터
static vector<edge> edges;  // 간선 정보를 저장하는 벡터

int main() {
    // 입출력 속도를 높이기 위한 설정
    ios::sync_with_stdio(false);  // C와 C++의 입출력 버퍼를 분리하여 성능 향상
    cin.tie(NULL);  // 입력 속도 향상을 위해 입력과 출력의 묶음을 풀음
    cout.tie(NULL);  // 출력 속도 향상을 위해 출력과 입력의 묶음을 풀음

    cin >> N >> M;  // N과 M을 입력받음
    mdistance.resize(N + 1);  // mdistance 벡터의 크기를 N+1로 조정
    fill(mdistance.begin(), mdistance.end(), LONG_MAX);  // 모든 정점까지의 거리를 무한대로 초기화

    for (int i = 0; i < M; i++)  // M개의 간선을 입력받는 반복문
    {
        int start, end, time;  // 시작 정점, 끝 정점, 가중치를 입력받음
        cin >> start >> end >> time;  // 간선 정보 입력
        edges.push_back(make_tuple(start, end, time));  // 입력받은 간선을 edges 벡터에 저장
    }

    // 벨만-포드 알고리즘 수행
    mdistance[1] = 0;  // 시작 정점(1번 정점)의 거리를 0으로 설정

    for (int i = 1; i < N; i++)  // N-1번 반복하는 외부 루프
    {
        for (int j = 0; j < M; j++)  // M개의 간선을 순회하는 내부 루프
        {
            edge medge = edges[j];  // 현재 간선을 가져옴
            int start = get<0>(medge);  // 간선의 시작 정점
            int end = get<1>(medge);  // 간선의 끝 정점
            int time = get<2>(medge);  // 간선의 가중치

            // 더 가까운 최단 거리가 있다면 갱신
            if (mdistance[start] != LONG_MAX && mdistance[end] > mdistance[start] + time)
            {
                mdistance[end] = mdistance[start] + time;  // 최단 거리 갱신
            }
        }
    }
    bool mCycle = false;  // 음수 사이클 존재 여부를 저장할 변수

    for (int i = 0; i < M; i++)  // 한 번 더 간선을 순회하여 음수 사이클 여부 확인
    {
        edge medge = edges[i];  // 현재 간선을 가져옴
        int start = get<0>(medge);  // 간선의 시작 정점
        int end = get<1>(medge);  // 간선의 끝 정점
        int time = get<2>(medge);  // 간선의 가중치

        // 음수 사이클이 존재하는지 확인
        if (mdistance[start] != LONG_MAX && mdistance[end] > mdistance[start] + time)
        {
            mCycle = true;  // 음수 사이클이 있으면 mCycle을 true로 설정
        }
    }

    // 음수 사이클이 없는 경우
    if (!mCycle)
    {
        for (int i = 2; i <= N; i++)  // 2번 정점부터 N번 정점까지 확인
        {
            if (mdistance[i] == LONG_MAX)  // 최단 거리가 갱신되지 않은 경우
            {
                cout << -1 << "\n";  // -1 출력 (경로 없음)
            }
            else
            {
                cout << mdistance[i] << "\n";  // 최단 거리를 출력
            }
        }
    }
    else
    {
        cout << -1 << "\n";  // 음수 사이클이 있을 경우 -1 출력
    }
}
