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

	for (int z = 0; z < N; z++)
	{
		A[z] = z+1; // 기존 바구니 값은 바구니 번호대로
	}

	int i, j = 0;
	// 두 바구니에 들어있는 공을 서로 교환
	for (int k = 0; k < M; k++)
	{
		cin >> i >> j;
		int temp = A[i - 1];
		A[i - 1] = A[j - 1];
		A[j - 1] = temp;
	}	

	for (int i = 0; i < A.size(); i++)
	{
		cout << A[i] << " ";
	}

	return 0;
}