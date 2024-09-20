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

// 트라이(Trie) 자료 구조에서 노드를 표현하는 클래스
class Node {
public:
    // 각 노드에서 26개의 자식 노드를 가짐 (알파벳 소문자 a-z에 해당하는 26개의 배열)
    Node* next[26];
    bool isEnd; // 해당 노드가 문자열의 끝인지 여부를 저장하는 플래그

    // 생성자: 노드를 초기화할 때 isEnd는 false로, 자식 노드들은 nullptr로 초기화됨
    Node() : isEnd(false) {
        fill(next, next + 26, nullptr); // next 배열을 모두 nullptr로 채움
    }

    // 소멸자: 할당된 모든 자식 노드를 메모리에서 해제함
    ~Node() {
        for (auto& child : next) // 자식 노드를 순회하며
            delete child; // 자식 노드에 할당된 메모리를 해제
    }

    // 트라이에 문자열을 삽입하는 함수
    void insert(const char* key) {
        // 문자열의 끝에 도달하면 isEnd를 true로 설정
        if (*key == 0) {
            isEnd = true;
        }
        else {
            // 현재 문자의 알파벳 순서를 인덱스로 변환 ('a'는 0, 'z'는 25)
            int next_index = *key - 'a';

            // 해당 자식 노드가 없으면 새로 생성
            if (next[next_index] == nullptr) {
                next[next_index] = new Node();
            }
            // 다음 문자를 처리하도록 재귀 호출
            next[next_index]->insert(key + 1);
        }
    }

    // 트라이에서 문자열을 검색하는 함수
    Node* find(const char* key) {
        // 문자열의 끝에 도달했으면 현재 노드를 반환
        if (*key == 0) {
            return this;
        }
        // 현재 문자의 인덱스를 계산
        int next_index = *key - 'a';

        // 해당 인덱스에 자식 노드가 없으면 nullptr 반환 (즉, 문자열이 트라이에 없음)
        if (next[next_index] == nullptr) {
            return nullptr;
        }
        // 다음 문자를 처리하도록 재귀 호출
        return next[next_index]->find(key + 1);
    }
};

int main() {
    // 입출력 속도를 높이기 위한 설정
    ios::sync_with_stdio(false);  // C와 C++의 입출력 버퍼를 분리하여 성능 향상
    cin.tie(NULL);  // 입력과 출력의 동기화를 해제하여 성능 향상
    cout.tie(NULL); // 출력과 입력의 동기화를 해제하여 성능 향상

    int n, m;
    cin >> n >> m; // n은 집합에 속하는 문자열의 개수, m은 확인할 문자열의 개수
    Node* root = new Node(); // 트라이의 루트 노드를 생성

    // n개의 문자열을 트라이에 삽입
    while (n > 0) {
        char text[501]; // 최대 500자까지 문자열 입력을 받음
        cin >> text; // 문자열 입력
        root->insert(text); // 트라이에 삽입
        n--; // 남은 문자열 개수 감소
    }

    int count = 0; // 집합 S에 속하는 문자열의 개수를 세기 위한 변수

    // m개의 문자열을 트라이에서 검색
    while (m > 0) {
        char text[501]; // 최대 500자까지 문자열 입력을 받음
        cin >> text; // 문자열 입력
        Node* result = root->find(text); // 트라이에서 해당 문자열 검색

        // 검색 결과가 존재하고, 그 문자열이 끝나는 지점이 맞다면 카운트를 증가
        if (result && result->isEnd) {
            count++; // 집합 S에 포함되는 문자열
        }
        m--; // 남은 검색 문자열 개수 감소
    }
    cout << count << "\n"; // 집합 S에 포함된 문자열의 개수를 출력

    // 메모리 누수를 방지하기 위해 동적 할당된 트라이를 해제하는 코드가 필요함
}
