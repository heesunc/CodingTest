#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cctype>
#include <stdlib.h> // stoi, itoa를 위함
#include <cmath>

using namespace std;

int main() {
	// 시간 단축을 위한 구문
	ios::sync_with_stdio(false);    cin.tie(NULL);    cout.tie(NULL);

	int n, tmp;
	cin >> n;

	int countArray[10001] = { 0 };

	for (int i = 0; i < n; i++) {
		cin >> tmp;
		countArray[tmp]++;
	}

	for (int i = 1; i < 10001; i++) {
		if (countArray[i] > 0) {
			for (int j = 0; j < countArray[i]; j++) {
				cout << i << "\n";
			}
		}
	}
}