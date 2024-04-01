#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int main() {
	// 시간 단축을 위한 구문
	ios::sync_with_stdio(false);    cin.tie(NULL);    cout.tie(NULL);

	long A, B, C;
	cin >> A >> B >> C;

	long sum = 0;
	sum = A + B + C;

	cout << sum;

	return 0;
}