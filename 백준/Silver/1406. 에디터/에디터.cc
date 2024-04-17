#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <cctype>
#include <stdlib.h> // stoi, itoa를 위함
#include <cmath>
#include <unordered_map>

using namespace std;

int main() {
	// 시간 단축을 위한 구문
	ios::sync_with_stdio(false);    cin.tie(NULL);    cout.tie(NULL);

	int n; 
	string s; 
	cin >> s; cin >> n;

	list<char> li(s.begin(), s.end());
	auto cur = li.end();

	while (n--)
	{
		char command; cin >> command;

		if (command == 'L')
		{
			if (cur != li.begin())
				cur--;
		}
		else if (command == 'D')
		{
			if (cur != li.end())
				cur++;
		}
		else if (command == 'B')
		{
			if (cur != li.begin())
				cur = li.erase(--cur);
		}
		else if (command == 'P')
		{
			char inputchar; cin >> inputchar;
			li.insert(cur, inputchar);
		}
	}

	for (auto it = li.begin(); it != li.end(); it++)
	{
		cout << *it;
	}

	return 0;
}