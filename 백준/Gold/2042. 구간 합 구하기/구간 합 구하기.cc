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
long getSum(int s, int e);  // 구간 합을 계산하는 함수
void changeVal(int index, long val);  // 특정 값을 변경하는 함수
void setTree(int i);  // 트리를 초기화하는 함수

int main() {
    ios::sync_with_stdio(false);  // C와 C++ 입출력 버퍼 분리로 입출력 성능 향상
    cin.tie(NULL);  // 입출력의 동기화를 해제하여 성능 향상
    cout.tie(NULL); // 출력의 동기화를 해제하여 성능 향상

    int N, M, K;
    cin >> N >> M >> K;  // N: 원소 개수, M: 변경 횟수, K: 구간 합 구하는 횟수
    int treeHeight = 0;  // 트리 높이 저장 변수
    int Length = N;

    // 트리 높이 계산
    while (Length != 0)
    {
        Length /= 2;
        treeHeight++;
    }

    // 트리 크기 계산 (2^트리 높이 + 1)
    int treeSize = int(pow(2, treeHeight + 1));
    // 리프 노드가 시작하는 인덱스 계산
    int leftNodeStartIndex = treeSize / 2 - 1;
    // 트리 벡터 크기 설정
    tree.resize(treeSize + 1);

    // 리프 노드에 입력된 데이터를 트리에 저장
    for (int i = leftNodeStartIndex + 1; i <= leftNodeStartIndex + N; i++)
    {
        cin >> tree[i];  // 리프 노드에 데이터 입력
    }

    // 세그먼트 트리 구축
    setTree(treeSize - 1);

    // M + K 번의 연산 처리
    for (int i = 0; i < M + K; i++)
    {
        long a, s, e;
        cin >> a >> s >> e;

        if (a == 1) // 값 변경 연산
        {
            changeVal(leftNodeStartIndex + s, e);
        }
        else if (a == 2) // 구간 합 연산
        {
            s = s + leftNodeStartIndex;
            e = e + leftNodeStartIndex;
            cout << getSum(s, e) << "\n";  // 구간 합 출력
        }
    }
}

// 구간 합을 계산하는 함수
long getSum(int s, int e)
{
    long partSum = 0;  // 구간 합을 저장할 변수

    // 두 구간을 탐색하며 합을 계산
    while (s <= e)
    {
        // 왼쪽 구간이 홀수면 해당 노드 포함 후 다음으로 이동
        if (s % 2 == 1)
        {
            partSum = partSum + tree[s];
            s++;
        }
        // 오른쪽 구간이 짝수면 해당 노드 포함 후 이전으로 이동
        if (e % 2 == 0)
        {
            partSum = partSum + tree[e];
            e--;
        }
        // 부모 노드로 이동
        s = s / 2;
        e = e / 2;
    }
    return partSum;  // 구간 합 반환
}

// 특정 값 변경 함수
void changeVal(int index, long val)
{
    long diff = val - tree[index];  // 변경할 값과 기존 값의 차이

    // 루트 노드까지 올라가며 값 갱신
    while (index > 0)
    {
        tree[index] = tree[index] + diff;  // 차이만큼 더해줌
        index = index / 2;  // 부모 노드로 이동
    }
}

// 세그먼트 트리를 초기화하는 함수
void setTree(int i)
{
    // 리프 노드에서 루트 노드까지 값 계산
    while (i != 1)
    {
        tree[i / 2] += tree[i];  // 부모 노드에 자식 노드 값 더해줌
        i--;  // 왼쪽 자식 노드로 이동
    }
}