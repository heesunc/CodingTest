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
static int MOD = 1000000007;  // 나머지 연산에 사용할 값
long getMul(int s, int e);  // 구간 곱을 계산하는 함수 선언
void changeVal(int index, long val);  // 특정 인덱스의 값을 변경하는 함수 선언
void setTree(int i);  // 트리를 초기화하는 함수 선언

int main() {
    ios::sync_with_stdio(false);  // C++ 입출력 성능 향상을 위해 C 표준 스트림과의 동기화 비활성화
    cin.tie(NULL);  // 입출력의 동기화를 해제하여 성능을 향상
    cout.tie(NULL); // 출력 동기화를 해제하여 성능 향상

    int N, M, K;
    cin >> N >> M >> K;  // N: 입력 데이터 개수, M: 구간 곱을 구하는 쿼리 수, K: 값을 변경하는 쿼리 수
    int treeHeight = 0;
    int Length = N;

    // 트리 높이 계산 (N개의 데이터를 수용할 수 있는 최소한의 트리 높이)
    while (Length != 0)
    {
        Length /= 2;
        treeHeight++;
    }
    int treeSize = int(pow(2, treeHeight + 1));  // 트리의 전체 크기 (리프 노드 포함)
    int leftNodeStartIndex = treeSize / 2 - 1;  // 리프 노드 시작 인덱스
    tree.resize(treeSize + 1);  // 트리 크기 설정
    fill(tree.begin(), tree.end(), 1);  // 트리 값 1로 초기화 (곱셈이기 때문에 초기값 1)

    // 데이터를 리프 노드로 입력받기
    for (int i = leftNodeStartIndex + 1; i <= leftNodeStartIndex + N; i++)
    {
        cin >> tree[i];  // 입력 값을 리프 노드에 저장
    }
    setTree(treeSize - 1);  // 트리 초기화 함수 호출 (리프 노드부터 트리 구성)

    // M + K번의 쿼리 처리 (값 변경 쿼리와 구간 곱 쿼리)
    for (int i = 0; i < M + K; i++)
    {
        long a, s, e;
        cin >> a >> s >> e;

        if (a == 1)
        {
            // 값 변경 쿼리 (s번째 값을 e로 변경)
            changeVal(leftNodeStartIndex + s, e);
        }
        else if (a == 2)
        {
            // 구간 곱 쿼리 (s부터 e까지의 구간 곱을 계산)
            s = s + leftNodeStartIndex;  // 트리 상의 시작 인덱스 계산
            e = e + leftNodeStartIndex;  // 트리 상의 끝 인덱스 계산
            cout << getMul(s, e) << "\n";  // 구간 곱을 계산하여 출력
        }
    }
}

// 구간 곱을 계산하는 함수
// 구간 내의 각 노드 값을 곱한 후 MOD로 나눈 나머지를 반환
long getMul(int s, int e)
{
    long partMul = 1;  // 구간 곱을 저장할 변수, 초기값은 1 (곱셈의 항등원)

    // 구간 [s, e]에서 곱을 구하는 과정
    while (s <= e)
    {
        if (s % 2 == 1)
        {
            // s가 홀수일 때 해당 노드 값을 곱하고 오른쪽으로 이동
            partMul = partMul * tree[s] % MOD;  // MOD 연산을 적용하여 값 갱신
            s++;
        }
        if (e % 2 == 0)
        {
            // e가 짝수일 때 해당 노드 값을 곱하고 왼쪽으로 이동
            partMul = partMul * tree[e] % MOD;  // MOD 연산을 적용하여 값 갱신
            e--;
        }
        s = s / 2;  // 부모 노드로 이동
        e = e / 2;  // 부모 노드로 이동
    }
    return partMul;  // 구간 내 곱셈 결과 반환
}

// 특정 인덱스의 값을 변경하는 함수
void changeVal(int index, long val)
{
    tree[index] = val;  // 리프 노드의 값을 변경

    // 부모 노드 값을 업데이트하며 트리 갱신
    while (index > 1)
    {
        index = index / 2;  // 부모 노드로 이동
        // 부모 노드는 왼쪽 자식과 오른쪽 자식의 곱셈 결과
        tree[index] = tree[index * 2] % MOD * tree[index * 2 + 1] % MOD;
    }
}

// 트리를 초기화하는 함수 (리프 노드부터 부모 노드까지)
void setTree(int i)
{
    while (i != 1)
    {
        // 부모 노드 값은 자식 노드 값들의 곱셈 결과
        tree[i / 2] = tree[i / 2] * tree[i] % MOD;
        i--;  // 왼쪽으로 이동하여 다른 노드들 갱신
    }
}