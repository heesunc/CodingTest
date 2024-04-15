#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cctype>
#include <stdlib.h> // stoi, itoa를 위함
#include <cmath>
#include <unordered_map>

using namespace std;

int main() {
	// 시간 단축을 위한 구문
	ios::sync_with_stdio(false);    cin.tie(NULL);    cout.tie(NULL);

	long N; cin >> N;
	vector<long> A(N);

	for(long i=0; i<N; i++)
	{
		cin >> A[i];
	}
	// 이진탐색을 위해서는 정렬을 해야함
	sort(A.begin(), A.end());

	long M; cin >> M;
	vector<long> B(M);

	for (long i = 0; i < M; i++)
	{
		cin >> B[i];
		printf("%d\n", binary_search(A.begin(), A.end(), B[i]));
	}

	return 0;
}