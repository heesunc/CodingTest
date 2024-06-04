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

using namespace std;  // 표준 라이브러리(std)의 네임스페이스를 사용함

int main() {
	// 시간 단축을 위한 구문
	ios::sync_with_stdio(false);    cin.tie(NULL);    cout.tie(NULL);

	int N; cin >> N; // 명령어 개수
	deque<int> A; // 큐
	int num; // push 연산시 스택에 넣을 정수
	int npop = 0; // pop
	string str;

	for (int i = 0; i < N; i++)
	{
		cin >> str;

		// push
		if (str == "1")
		{
			cin >> num;
			A.push_front(num);
		}
		else if (str == "2")
		{
			cin >> num;
			A.push_back(num);
		}
		else if (str == "3")
		{
			if (A.empty())
			{
				cout << "-1\n";
			}
			else
			{
				npop = A.front();
				cout << npop << "\n";
				A.pop_front();
			}				
		}
		else if (str == "4")
		{
			if (A.empty())
			{
				cout << "-1\n";
			}
			else
			{
				npop = A.back();
				cout << npop << "\n";
				A.pop_back();
			}				
		}
		else if (str == "5")
		{
			cout << A.size() << "\n";
		}
		else if (str == "6")
		{
			if (A.empty())
			{
				cout << "1\n";
			}
			else
			{
				cout << "0\n";
			}
		}
		else if (str == "7")
		{
			if (A.empty())
				cout << "-1\n";
			else
				cout << A.front() << "\n";
		}
		else if (str == "8")
		{
			if (A.empty())
				cout << "-1\n";
			else
				cout << A.back() << "\n";
		}
	}
	return 0;
}