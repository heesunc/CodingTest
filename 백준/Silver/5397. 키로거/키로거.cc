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

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int t; cin >> t;
	while (t--)
	{
		string l; cin >> l;
		stack<char> left;
		stack<char> right;

		for (char c : l)
		{
			if (c == '-') // 왼쪽 스택에서 문자를 제거
			{
				if (!left.empty())
				{
					left.pop();
				}				
			}
			else if (c == '<') // 왼쪽 스택에서 오른쪽 스택으로 문자를 이동
			{
				if (!left.empty())
				{
					right.push(left.top());
					left.pop();
				}				
			}
			else if (c == '>') // 오른쪽 스택에서 왼쪽 스택으로 문자를 이동
			{
				if (!right.empty())
				{
					left.push(right.top());
					right.pop();
				}							
			}
			else if (c != '-' && c != '<' && c != '>')
			{
				left.push(c);
			}
		}

		// 비밀번호를 만들기 위해 왼쪽 스택과 오른쪽 스택을 이용
		string result;
		while (!left.empty()) {
			result += left.top();
			left.pop();
		}
		reverse(result.begin(), result.end());

		// 오른쪽 스택에 있는 문자들을 그대로 추가
		while (!right.empty()) {
			result += right.top();
			right.pop();
		}

		// 결과 출력
		cout << result << endl;
	}
	return 0;
}