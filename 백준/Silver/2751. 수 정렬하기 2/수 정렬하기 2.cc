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

	int N; cin >> N;
	vector <int> A(0);
	int M;

	for (int i = 0; i < N; i++)
	{
		cin >> M;
		A.push_back(M);
	}

	sort(A.begin(), A.end());

	for (int i = 0; i < A.size(); i++)
	{
		cout << A[i] << "\n";
	}
}