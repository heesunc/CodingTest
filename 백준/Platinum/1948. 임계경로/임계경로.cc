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
	ios::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);

	int N, M; cin >> N >> M;

	vector<vector<pair<int, int>>> A;
	vector<vector<pair<int, int>>> reverseA;
	vector<int> indegree; // 진입 차수 배열
	A.resize(N + 1);
	reverseA.resize(N + 1);
	indegree.resize(N + 1);

	for (int i = 0; i < M; i++)
	{
		int S, E, V;
		cin >> S >> E >> V;
		A[S].push_back(make_pair(E, V));
		reverseA[E].push_back(make_pair(S, V)); // 역방향 에지 정보 저장
		indegree[E]++; // 진입 차수 배열 초기화
	}

	int startDosi, endDosi;
	cin >> startDosi >> endDosi;
	queue<int> mqueue; // 위상 정렬 수행
	mqueue.push(startDosi);
	vector<int> result;
	result.resize(N + 1);

	while (!mqueue.empty())
	{
		int now = mqueue.front();
		mqueue.pop();

		for (pair<int, int> next : A[now])
		{
			indegree[next.first]--;
			result[next.first] = max(result[next.first], result[now] + next.second);

			if (indegree[next.first] == 0)
			{
				mqueue.push(next.first);
			}
		}
	}

	// 위상 정렬 reverse
	int resultCount = 0;
	vector<bool> visited;
	visited.resize(N + 1);
	queue<int> rqueue;
	rqueue.push(endDosi);
	visited[endDosi] = true;

	while (!rqueue.empty())
	{
		int now = rqueue.front();
		rqueue.pop();

		for (pair<int, int> next : reverseA[now])
		{
			if (result[next.first] + next.second == result[now])
			{
				resultCount++;
				// 중복 카운트 방지를 위해 이미 방문한 노드 제외
				if (visited[next.first] == false)
				{
					visited[next.first] = true;
					rqueue.push(next.first);
				}
			}
		}
	}
	cout << result[endDosi] << "\n";
	cout << resultCount << "\n";
}