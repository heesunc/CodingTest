#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int main() {
	// 시간 단축을 위한 구문
	ios::sync_with_stdio(false);    cin.tie(NULL);    cout.tie(NULL);

	string str;	cin >> str;
	int count = 0;

	for (int i = 0; i < str.size(); i++)
	{
		count++;
	}

	cout << count;

	return 0;
}