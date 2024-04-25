#include <string>       // 문자열 처리를 위한 헤더 파일
#include <iostream>     // 입출력을 위한 헤더 파일
#include <vector>       // 동적 배열(vector)을 사용하기 위한 헤더 파일
#include <algorithm>    // 알고리즘 함수를 사용하기 위한 헤더 파일

using namespace std;  // 표준 라이브러리(std)의 네임스페이스를 사용함

int main() {
	ios::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);

	int N; int M;
	cin >> N >> M;

	vector<int> A(N);
	vector<int> B(M);

	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}

	for (int i = 0; i < M; i++)
	{
		cin >> B[i];
	}

	A.insert(A.end(), B.begin(), B.end());
	sort(A.begin(), A.end());

	for (int i =0; i<A.size(); i++)
	{
		cout << A[i] << " ";
	}
}