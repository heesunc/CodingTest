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

static int N;
static vector<vector<int>> tree;
static int answer = 0;
static int deleteNode = 0;
static vector<bool> visited;
void DFS(int number);

int main() {
    // 입출력 속도를 높이기 위한 설정
    ios::sync_with_stdio(false);  // C와 C++의 입출력 버퍼를 분리하여 성능 향상
    cin.tie(NULL);  // 입력 속도 향상을 위해 입력과 출력의 묶음을 풀음
    cout.tie(NULL);  // 출력 속도 향상을 위해 출력과 입력의 묶음을 풀음

    cin >> N;
    visited.resize(N);
    tree.resize(N);
    int root = 0;

    for (int i = 0; i < N; i++)
    {
        int p; cin >> p;
        if (p != -1)
        {
            tree[i].push_back(p);
            tree[p].push_back(i);
        }
        else // -1이면 루트 노드
        {
            root = i;
        }
    }
    cin >> deleteNode; // 삭제할 노드 번호 입력

    if (deleteNode == root) // 루트를 삭제한다면 0 출력
    {
        cout << 0 << "\n";
    }
    else
    {
        DFS(root);
        cout << answer << "\n";
    }
}

void DFS(int number)
{
    visited[number] = true;
    int cNode = 0; // 자식 노드 개수

    for (int i : tree[number])
    {
        // 방문하지 않은 노드이고 삭제 노드가 아닌 경우 탐색 중지
        if (visited[i] == false && i != deleteNode)
        {
            cNode++;
            DFS(i);
        }
    }
    if (cNode == 0) // 자식 노드 수가 0이면 리프 노드로 간주하고 정답값 증가
    {
        answer++;
    }
}