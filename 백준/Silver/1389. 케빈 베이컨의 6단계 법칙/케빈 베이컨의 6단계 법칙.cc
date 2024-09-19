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

static int N, M;
static long mdistance[101][101];

int main() {
    // 입출력 속도를 높이기 위한 설정
    ios::sync_with_stdio(false);  // C와 C++의 입출력 버퍼를 분리하여 성능 향상
    cin.tie(NULL);  // 입력 속도 향상을 위해 입력과 출력의 묶음을 풀음
    cout.tie(NULL);  // 출력 속도 향상을 위해 출력과 입력의 묶음을 풀음

    cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (i == j)
            {
                mdistance[i][j] = 0;
            }
            else
            {
                mdistance[i][j] = 10000001;
            }
        }
    }

    for (int i = 0; i < M; i++)
    {
        int s, e;
        cin >> s >> e; // 양방향 그래프
        mdistance[s][e] = 1;
        mdistance[e][s] = 1;
    }

    // 플로이드-워셜 알고리즘 수행
    // i -> k -> j의 경로가 존재하는 경우, i -> j로 가는 경로도 존재한다고 판단
    // mdistance[i][j]를 1로 갱신
    for (int k = 1; k <= N; k++)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if (mdistance[i][j] > mdistance[i][k] + mdistance[k][j])
                {
                    mdistance[i][j] = mdistance[i][k] + mdistance[k][j];
                }
            }
        }
    }
    int Min = INT_MAX;
    int Answer = -1;

    for (int i = 1; i <= N; i++)
    {
        int temp = 0;
        for (int j = 1; j <= N; j++)
        {
            temp = temp + mdistance[i][j];
        }
        if (Min > temp) // 가장 작은 케빈 베이컨의 수를 지닌 i 찾기
        {
            Min = temp;
            Answer = i;
        }
    }
    cout << Answer;

    return 0;
}
