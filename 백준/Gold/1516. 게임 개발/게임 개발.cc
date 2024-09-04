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

	int N; cin >> N;
	vector<vector<int>> A;
	vector<int> indegree; 
	vector<int> selfBuild;
	A.resize(N + 1);
	indegree.resize(N + 1);
	selfBuild.resize(N + 1);

	for (int i = 1; i <= N; i++)
	{
		cin >> selfBuild[i]; // 해당 건물을 짓기 위한 시간
		while (true)
		{
			int preTemp;
			cin >> preTemp;

			if (preTemp == -1)
			{
				break;
			}
			A[preTemp].push_back(i);
			indegree[i]++; // 진입 차수 데이터 저장
		}
	}

	queue<int> queue; // 위상 정렬 수행

	for (int i = 1; i <= N; i++)
	{
		if (indegree[i] == 0)
		{
			queue.push(i);
		}
	}

	vector<int> result;
	result.resize(N + 1);

	while (!queue.empty())
	{
		int now = queue.front();
		queue.pop();

		for (int next : A[now])
		{
			indegree[next]--;
			result[next] = max(result[next], result[now] + selfBuild[now]);
			if (indegree[next] == 0)
			{
				queue.push(next);
			}
		}
	}
	for (int i = 1; i <= N; i++)
	{
		cout << result[i] + selfBuild[i] << "\n";
	}
}