#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int main() {
	// 시간 단축을 위한 구문
	ios::sync_with_stdio(false);    cin.tie(NULL);    cout.tie(NULL);

	int N; // 4의 배수
	cin >> N;

	for (int i = 0; i < N; i += 4)
	{
		cout << "long ";
	}

	cout << "int";

	return 0;
}