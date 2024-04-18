#include <string>
#include <iostream>

using namespace std;

int main() {
	// 시간 단축을 위한 구문
	ios::sync_with_stdio(false);    cin.tie(NULL);    cout.tie(NULL);

	int n;
	int prime=0, sum=0;

	for (int i = 0; i < 5; i++)
	{
		cin >> n;
		prime = n * n;
		sum += prime;
	}

	cout << sum % 10;

	return 0;
}