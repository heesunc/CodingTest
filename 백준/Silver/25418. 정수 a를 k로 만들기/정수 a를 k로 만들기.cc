#include <string>       // 문자열 처리를 위한 헤더 파일
#include <iostream>     // 입출력을 위한 헤더 파일
#include <vector>       // 동적 배열(vector)을 사용하기 위한 헤더 파일
#include <algorithm>    // 알고리즘 함수 (예: min())를 사용하기 위한 헤더 파일
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
#include <ctime>
#include <set>

using namespace std;

int bfs(int a, int k)
{
	vector<bool> visited(k * 2 + 1, false); // 방문체크 (A->K 중간 상태 체크)
	queue<pair<int, int>> q; // 상태 (a값, 연산 횟수)를 저장하는 큐
	q.push({ a, 0 });

	while (!q.empty())
	{
		int current = q.front().first;
		int steps = q.front().second;
		q.pop();

		if (current == k)
		{
			return steps; // 목표 상태에 도달하면 연산 횟수 반환
		}

		// 방문한 상태는 다시 방문하지 않음
		if (current > k || visited[current]) continue;

		visited[current] = true;

		// 두 가지 연산을 큐에 넣음
		q.push({ current + 1,steps + 1 });
		q.push({ current * 2, steps + 1 });
	}
	return -1; // 논리적으로 도달할 수 없는 경우
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int a, k; cin >> a >> k;
	cout << bfs(a, k) << "\n";

	// a를 k로 만들기 위해 필요한 최소 연산 횟수 구하기
	// 최소 연산 횟수 -> BFS
	// 각 연산에서 생성되는 상태를 큐에 넣고 차례대로 탐색

	return 0;
}