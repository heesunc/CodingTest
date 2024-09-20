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

// std 네임스페이스를 사용하여 std::를 생략할 수 있음
using namespace std;

static int n;
static int tree[26][2];
void preOrder(int now);
void inOrder(int now);
void postOrder(int now);

int main() {
    // 입출력 속도를 높이기 위한 설정
    ios::sync_with_stdio(false);  // C와 C++의 입출력 버퍼를 분리하여 성능 향상
    cin.tie(NULL);  // 입력과 출력의 동기화를 해제하여 성능 향상
    cout.tie(NULL); // 출력과 입력의 동기화를 해제하여 성능 향상

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        char node_char, left, right;
        cin >> node_char >> left >> right;
        int node = node_char - 'A'; // index변환을 위해 A 문자 빼기

        // 자식 노드가 없을 경우 -1을 저장
        if (left == '.')
        {
            tree[node][0] = -1;
        }
        else
        {
            tree[node][0] = left - 'A';
        }

        if (right == '.')
        {
            tree[node][1] = -1;
        }
        else
        {
            tree[node][1] = right - 'A';
        }
    }
    preOrder(0); cout << "\n";
    inOrder(0); cout << "\n";
    postOrder(0); cout << "\n";
}

void preOrder(int now)
{
    if (now == -1)
    {
        return;
    }
    cout << (char)(now + 'A'); // 현재 노드
    preOrder(tree[now][0]); // 왼쪽 탐색
    preOrder(tree[now][1]); // 오른쪽 탐색
}

void inOrder(int now)
{
    if (now == -1)
    {
        return;
    }
    inOrder(tree[now][0]); // 왼쪽 탐색
    cout << (char)(now + 'A'); // 현재 노드
    inOrder(tree[now][1]); // 오른쪽 탐색
}

void postOrder(int now)
{
    if (now == -1)
    {
        return;
    }
    postOrder(tree[now][0]); // 왼쪽 탐색
    postOrder(tree[now][1]); // 오른쪽 탐색
    cout << (char)(now + 'A'); // 현재 노드
}