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

static vector<long> tree;  // 세그먼트 트리를 저장할 벡터
long getMin(int s, int e);  // 구간에서 최소값을 계산하는 함수 선언
void setTree(int i);  // 트리를 초기화하는 함수 선언

int main() {
    ios::sync_with_stdio(false);  // C++의 입출력 성능을 향상시키기 위해 C 표준 스트림과의 동기화 비활성화
    cin.tie(NULL);  // 입출력의 동기화를 해제하여 성능 향상
    cout.tie(NULL); // 출력의 동기화를 해제하여 성능 향상

    int N, M;
    cin >> N >> M;  // N은 입력받을 데이터 수, M은 쿼리(구간 최소값을 요청하는 횟수)

    int treeHeight = 0;
    int Length = N;

    // 트리의 높이 계산
    while (Length != 0)
    {
        Length /= 2;
        treeHeight++;
    }

    // 트리의 크기 계산
    int treeSize = int(pow(2, treeHeight + 1));  // 트리 전체 노드 개수 (리프 노드 포함)
    int leftNodeStartIndex = treeSize / 2 - 1;  // 리프 노드의 시작 인덱스

    // 트리 초기화하기
    tree.resize(treeSize + 1);  // 트리 벡터 크기를 설정
    fill(tree.begin(), tree.end(), LONG_MAX);  // 모든 트리 값을 LONG_MAX로 초기화

    // 데이터를 리프 노드에 입력받기
    for (int i = leftNodeStartIndex + 1; i <= leftNodeStartIndex + N; i++)
    {
        cin >> tree[i];  // 입력값을 리프 노드에 채움
    }
    setTree(treeSize - 1);  // 트리 초기화 함수 호출 (리프 노드부터 부모 노드로 올라가면서 트리 값 계산)

    // M번의 쿼리 실행
    for (int i = 0; i < M; i++)
    {
        long s, e;
        cin >> s >> e;  // 구간 [s, e] 입력받음
        s = s + leftNodeStartIndex;  // 트리 인덱스 상의 시작 노드 위치
        e = e + leftNodeStartIndex;  // 트리 인덱스 상의 끝 노드 위치
        cout << getMin(s, e) << "\n";  // 구간에서 최소값을 계산하여 출력
    }
}

long getMin(int s, int e)
{
    long Min = LONG_MAX;  // 최소값을 저장할 변수, 초기값은 최대값(LONG_MAX)

    // 구간 [s, e]에서 최소값을 찾는 과정
    while (s <= e)
    {
        // 시작점이 홀수인 경우, 현재 구간의 최소값을 비교
        if (s % 2 == 1)
        {
            Min = min(Min, tree[s]);  // s에 해당하는 노드의 값과 현재 최소값을 비교
            s++;  // s를 오른쪽으로 이동
        }
        s = s / 2;  // 부모 노드로 이동

        // 끝점이 짝수인 경우, 현재 구간의 최소값을 비교
        if (e % 2 == 0)
        {
            Min = min(Min, tree[e]);  // e에 해당하는 노드의 값과 현재 최소값을 비교
            e--;  // e를 왼쪽으로 이동
        }
        e = e / 2;  // 부모 노드로 이동
    }
    return Min;  // 최종적으로 구간 내에서 찾은 최소값 반환
}

void setTree(int i)
{
    // 부모 노드로 이동하면서 트리 값을 업데이트
    while (i != 1)
    {
        // 부모 노드의 값이 자식 노드보다 크면 자식 노드 값으로 업데이트
        if (tree[i / 2] > tree[i])
        {
            tree[i / 2] = tree[i];  // 부모 노드에 자식 노드의 최소값을 저장
        }
        i--;  // 왼쪽으로 이동하여 다른 노드들 갱신
    }
}