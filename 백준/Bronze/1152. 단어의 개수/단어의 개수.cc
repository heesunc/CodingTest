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

	//int n;
	//cin >> n;

	string str;
	getline(cin, str); // 공백을 포함하여 입력

	int count = 1;
	
	// 공백이 입력되면 1이 출력됨을 해결해주기
	if (str.size() == 1 && str[0] == ' ')
	{
		count = 0;
	}
	
	// 문자열은 공백으로 시작하거나 끝날 수 있으니 i = 1, 끝에서 -1
	for (int i = 1; i < str.size() - 1; i++) {
		if (str[i] == ' ')
		{
			count++;
		}
	}
	cout << count;

	return 0;
}