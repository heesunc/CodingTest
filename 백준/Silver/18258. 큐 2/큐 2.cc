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
	queue<int> A; // 큐
	int num; // push 연산시 스택에 넣을 정수
	int npop = 0; // pop
	string str;

	for (int i = 0; i < N; i++)
	{
		cin >> str;

		// push
		if (str == "push")
		{
			cin >> num;
			A.push(num);
		}
		else if (str == "pop")
		{
			if (A.size() == 0)
				cout << "-1\n"; // -1출력
			else
			{
				npop = A.front();
				cout << npop << "\n";
				A.pop();
			}
		}
		else if (str == "size")
		{
			cout << A.size() << "\n";
		}
		else if (str == "empty")
		{
			if (A.empty())
				cout << "1\n";
			else
				cout << "0\n";
		}
		else if (str == "front")
		{
			if (A.size() == 0)
				cout << "-1\n"; // -1 출력
			else
				cout << A.front() << "\n";
		}
		else if (str == "back")
		{
			if (A.size() == 0)
				cout << "-1\n"; // -1 출력
			else
				cout << A.back() << "\n";
		}
	}

	return 0;
}