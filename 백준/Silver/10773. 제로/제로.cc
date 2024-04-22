#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cctype>
#include <stdlib.h> // stoi, itoa를 위함
#include <cmath>
#include <unordered_map>

using namespace std;

int main() {
	// 시간 단축을 위한 구문
	ios::sync_with_stdio(false);    cin.tie(NULL);    cout.tie(NULL);

	int N; cin >> N; // 명령어 개수
	stack<int> A; // 스택

	int num; // push 연산시 스택에 넣을 정수
	int npop = 0; // pop
	//string str;

	for (int i = 0; i < N; i++)
	{
		cin >> num;

		if (num == 0)
		{
			A.pop();
		}
		else
		{
			A.push(num);
		}
	}

	int result = 0;
	if (A.empty())
	{
		cout << result;
		return 0;
	}

	while (!A.empty())
	{
		result += A.top();
		A.pop();
	}
	cout << result;

	return 0;
}