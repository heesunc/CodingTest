#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int main() {
	// 시간 단축을 위한 구문
	ios::sync_with_stdio(false);    cin.tie(NULL);    cout.tie(NULL);

	int N, M; // 바구니, 횟수 
	cin >> N >> M;

	vector<int> A(N, 0); // 바구니 벡터

	int i, j, k = 0;

	for (int q = 0; q < M; q++)
	{
		cin >> i >> j >> k;
		
		for (i; i <= j; i++)
		{
			A[i-1] = k;
		}
	}

	for (int i = 0; i < A.size(); i++)
	{
		cout << A[i] << " ";
	}

	return 0;
}