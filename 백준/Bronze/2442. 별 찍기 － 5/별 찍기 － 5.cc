#include <string>
#include <iostream>
using namespace std;

int main() {
	// 시간 단축을 위한 구문
	ios::sync_with_stdio(false);    cin.tie(NULL);    cout.tie(NULL);

	int N; cin >> N;
	
	for (int i = 1; i <= N; i++) {
		cout << string(N - i, ' '); // 공백 출력
		cout << string(2 * i - 1, '*') << endl; // 별표 출력
	}

	return 0;
}