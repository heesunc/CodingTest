#include <string>
#include <iostream>

using namespace std;

int main() {
	// 시간 단축을 위한 구문
	ios::sync_with_stdio(false);    cin.tie(NULL);    cout.tie(NULL);

	int N; cin >> N;

	for (int i = N; i > 0; i--) {
		cout << string(N - i, ' '); // 공백 출력
		cout << string(i, '*') << endl; // 별표 출력
	}

	return 0;
}