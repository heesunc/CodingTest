#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int main() {
	// 시간 단축을 위한 구문
	ios::sync_with_stdio(false);    cin.tie(NULL);    cout.tie(NULL);

	string str;	
	cin >> str;
	int a;
	cin >> a;
	char c = str[a-1];

	cout << c;

	return 0;
}