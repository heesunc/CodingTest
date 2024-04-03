#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cctype>

using namespace std;

int main() {
	// 시간 단축을 위한 구문
	ios::sync_with_stdio(false);    cin.tie(NULL);    cout.tie(NULL);

	int n; cin >> n;
	string str;
	string answer;

	for (int i = 0; i < n; i++)
	{
		cin >> str;

		answer = str.substr(0, 1) + str.substr(str.size() - 1);

		cout << answer << '\n';
	}

	return 0;
}