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

void BFS();
// 6가지 이동 케이스를 표현하기 위한 배열
static int Sender[] = { 0,0,1,1,2,2 };
static int Receiever[] = { 1,2,0,2,0,1 };
// A B의 용량만 있으면 C의 용량이 고정되므로 2개로만 체크 가능
static bool visited[201][201];
static bool answer[201];
static int now[3]; // A B C 물의 양을 저장하는 배열

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> now[0] >> now[1] >> now[2];
	BFS();

	for (int i = 0; i < 201; i++)
	{
		if (answer[i])
		{
			cout << i << " ";
		}
	}
}

void BFS()
{
	queue<pair<int, int>> queue;
	queue.push(make_pair(0, 0));
	visited[0][0] = true;
	answer[now[2]] = true;

	while (!queue.empty())
	{
		pair<int, int> p = queue.front();
		queue.pop();
		int A = p.first;
		int B = p.second;
		int C = now[2] - A - B; // C는 전체 물의 양에서 A와 B를 뺀 것

		for (int k = 0; k < 6; k++)
		{
			int next[] = { A,B,C };
			next[Receiever[k]] += next[Sender[k]];
			next[Sender[k]] = 0;

			// 대상 물통의 용량보다 물이 많아 넘칠 때
			if (next[Receiever[k]] > now[Receiever[k]])
			{
				// 초과하는 만큼 다시 이전 물통에 넣음
				next[Sender[k]] = next[Receiever[k]] - now[Receiever[k]];
				// 대상 물통은 최대로 채움
				next[Receiever[k]] = now[Receiever[k]];
			}

			// A와 B의 물의 양을 통하여 방문 배열 체크
			if (!visited[next[0]][next[1]])
			{
				visited[next[0]][next[1]] = true;
				queue.push(make_pair(next[0], next[1]));
				// A의 물의 양이 0일 때 C의 물의 용량을 정답 변수에 저장
				if (next[0] == 0)
				{
					answer[next[2]] = true;
				}
			}
		}
	}
}