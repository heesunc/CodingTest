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

vector<string> split(string input, char delimiter);
int mySum(string a);

int main() {
	// 시간 단축을 위한 구문
	ios::sync_with_stdio(false);    cin.tie(NULL);    cout.tie(NULL);

	// 핵심 : 더하기에 해당하는 부분에 괄호를 쳐서 모두 계산한 후, 빼기를 실행

	int answer = 0;
	string s; cin >> s;
	vector<string> str = split(s, '-'); // -

	for (int i = 0; i < str.size(); i++)
	{
		int temp = mySum(str[i]);
		if (i == 0)
		{
			answer = answer + temp; // 제일 앞에 것만 더하고 
		}
		else
		{
			answer = answer - temp; // 뒤에 부분은 더한 값을 빼줌
		}
	}

	cout << answer << "\n";
	
	return 0;
}

// cpp에는 내장함수로 split이 없기 때문에 직접 만들어주어야 함, sstream사용
vector<string> split(string input, char delimiter)
{
	vector<string> result;
	stringstream mystream(input);
	string splitdata;

	while (getline(mystream, splitdata, delimiter))
	{
		result.push_back(splitdata);
	}
	return result;
}

// 나뉜 그룹의 더하기 연산 수행 함수
int mySum(string a)
{
	int sum = 0;
	vector<string> temp = split(a, '+');

	for (int i = 0; i < temp.size(); i++)
	{
		sum += stoi(temp[i]);
	}
	return sum;
}