#include <string>
#include <iostream>

using namespace std;

int main() {
	// 시간 단축을 위한 구문
	ios::sync_with_stdio(false);    cin.tie(NULL);    cout.tie(NULL);

	int N; cin >> N;

	for (int i = 0; i<N; i++)
	{
		for (int j = N; j > i; j--)
		{
			cout << "*";
		}
		cout << "\n";
	}

	return 0;
}