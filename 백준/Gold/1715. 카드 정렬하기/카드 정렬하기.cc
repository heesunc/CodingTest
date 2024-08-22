#include <string>       // 문자열 처리를 위한 헤더 파일
#include <iostream>     // 입출력을 위한 헤더 파일
#include <vector>       // 동적 배열(vector)을 사용하기 위한 헤더 파일
#include <algorithm>    // 알고리즘 함수를 사용하기 위한 헤더 파일
#include <stack>        // 스택을 사용하기 위한 헤더 파일
#include <queue>        // 큐를 사용하기 위한 헤더 파일
#include <deque>        // 덱(Deque)을 사용하기 위한 헤더 파일
#include <cctype>       // 문자열의 문자를 검사하기 위한 헤더 파일
#include <stdlib.h>     // 문자열을 숫자로 변환하는 함수를 사용하기 위한 헤더 파일
#include <cmath>        // 수학 함수를 사용하기 위한 헤더 파일
#include <unordered_map> // 해시맵(Unordered Map)을 사용하기 위한 헤더 파일
#include <map>          // 맵(Map)을 사용하기 위한 헤더 파일
#include <sstream>      // 문자열을 스트림으로 변환하기 위한 헤더 파일
#include <cstdlib>      // 일반적인 유틸리티 함수를 사용하기 위한 헤더 파일
#include <iomanip>      // 입출력 서식 지정을 위한 헤더 파일
#include <climits> // INT_MAX를 사용하기 위한 헤더 파일
#include <numeric>  // accumulate를 사용하기 위해 필요한 헤더 파일

using namespace std;  // 표준 라이브러리(std)의 네임스페이스를 사용함

int main() {
	// 시간 단축을 위한 구문
	ios::sync_with_stdio(false);    cin.tie(NULL);    cout.tie(NULL);

	int N; cin >> N;
	// 작은 값이 우선 순위를 가지는 우선순위 큐
	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 0; i < N; i++)
	{
		int A; cin >> A;
		pq.push(A);
	}

    int sum = 0;
    // 큐에서 가장 큰 두 값을 꺼내서 합산한 후 다시 큐에 삽입
    while (pq.size() != 1) {
        // 가장 큰 두 값을 얻기
        int top1 = pq.top(); // 첫 번째 top (가장 큰 값)
        pq.pop();            // 첫 번째 top 제거

        int top2 = pq.top(); // 두 번째 top (두 번째로 큰 값)
        pq.pop();            // 두 번째 top 제거

        sum += top1 + top2;

        // 두 값을 더한 결과를 큐에 다시 삽입
        pq.push(top1 + top2);
    }
    cout << sum << " ";
	return 0;
}