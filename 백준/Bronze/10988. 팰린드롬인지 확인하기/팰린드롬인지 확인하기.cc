#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cctype>
#include <stdlib.h> // stoi, itoa를 위함

using namespace std;

int main() {
	// 시간 단축을 위한 구문
	ios::sync_with_stdio(false);    cin.tie(NULL);    cout.tie(NULL);

	string str; cin >> str;
	string str2 = str;

	reverse(str2.begin(), str2.end());

	if (str == str2)
	{
		cout << 1;
	}
	else
	{
		cout << 0;
	}

	return 0;
}