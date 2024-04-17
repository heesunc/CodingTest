#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <cctype>
#include <stdlib.h> // stoi, itoa를 위함
#include <cmath>
#include <unordered_map>

using namespace std;

int main() {
	// 시간 단축을 위한 구문
	ios::sync_with_stdio(false);    cin.tie(NULL);    cout.tie(NULL);

	int n; cin >> n;
	int s; int sum = 0;
	vector<int> A(n);
	vector<int> B(n);

	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
	}

	for (int i = 0; i < n; i++)
	{
		cin >> B[i];
	}

	sort(A.begin(), A.end());
	sort(B.begin(), B.end(), greater<int>());

	int i = 0;
	while (n--)
	{
		s = A[i] * B[i]; // 이게 최솟값
		sum += s;
		i++;
	}
	cout << sum;	

	return 0;
}