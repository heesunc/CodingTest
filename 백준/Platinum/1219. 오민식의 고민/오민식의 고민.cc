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

using namespace std; // std 네임스페이스를 사용하여 std::를 생략 가능하게 함

typedef tuple<int, int, int> edge;
static int N, M, sCity, eCity;
static vector<long> mdistance, cityMoney;
static vector<edge> edges;

int main() {
    // 입출력 속도를 높이기 위한 설정
    ios::sync_with_stdio(false);  // C와 C++의 입출력 버퍼를 분리하여 성능 향상
    cin.tie(NULL);  // 입력 속도 향상을 위해 입력과 출력의 묶음을 풀음
    cout.tie(NULL);  // 출력 속도 향상을 위해 출력과 입력의 묶음을 풀음

    cin >> N >> sCity >> eCity >> M;
    mdistance.resize(N);
    cityMoney.resize(N);

    fill(mdistance.begin(), mdistance.end(), LONG_MIN); // 최단 거리 배열 초기화

    for (int i = 0; i < M; i++)
    {
        int start, end, price;
        cin >> start >> end >> price;
        edges.push_back(make_tuple(start, end, price));
    }
    for (int i = 0; i < N; i++)
    {
        cin >> cityMoney[i];
    }
    mdistance[sCity] = cityMoney[sCity]; // 변형 벨만-포드 알고리즘 수행

    // 양수 사이클이 전파되도록 충분히 큰 수로 반복하기
    for (int i = 0; i <= N + 50; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int start = get<0>(edges[j]);
            int end = get<1>(edges[j]);
            int price = get<2>(edges[j]);

            // 시작 노드가 미방문이면 continue
            if (mdistance[start] == LONG_MIN)
            {
                continue;
            }
            // 시작 노드가 양수 사이클에 연결된 노드라면 종료 노드도 연결 노드로 갱신
            else if (mdistance[start] == LONG_MAX)
            {
                mdistance[end] = LONG_MAX;
            }
            // 더 많은 돈을 벌 수 있는 새로운 경로를 발견하면 새로운 경로값으로 갱신
            else if (mdistance[end] < mdistance[start] + cityMoney[end] - price)
            {
                mdistance[end] = mdistance[start] + cityMoney[end] - price;
                // N-1 반복 이후 갱신되는 종료 노드는 양수 사이클 연결 노드로 변경
                if (i >= N - 1)
                {
                    mdistance[end] = LONG_MAX;
                }
            }
        }
    }

    if (mdistance[eCity] == LONG_MIN)
    {
        cout << "gg" << "\n"; // 도착 불가능
    }
    else if (mdistance[eCity] == LONG_MAX)
    {
        cout << "Gee" << "\n"; // 양수 사이클 연결
    }
    else
    {
        cout << mdistance[eCity] << "\n"; // 그 이외의 경우
    }

    return 0;
}
