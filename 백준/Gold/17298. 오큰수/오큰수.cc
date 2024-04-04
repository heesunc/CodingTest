#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cctype>
#include <stdlib.h> // stoi, itoa를 위함

using namespace std;

int main() {
	// 시간 단축을 위한 구문
	ios::sync_with_stdio(false);    cin.tie(NULL);    cout.tie(NULL);

	int N; cin >> N;
	vector<int> A(N, 0);
	vector<int> ans(N, 0);

	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}

	stack<int> myStack;
	myStack.push(0);

	for (int i = 1; i < N; i++)
	{
		// 스택이 비지 않고 현재 수열이 스택 top 위치의 값보다 크면
		while (!myStack.empty() && A[myStack.top()] < A[i])
		{
			ans[myStack.top()] = A[i]; // 정답 배열에 오큰수를 현재 수열로 저장
			myStack.pop();
		}
		myStack.push(i); // 신규 데이터 push()
	}

	while (!myStack.empty()) // 스택이 빌 때까지
	{
		ans[myStack.top()] = -1;
		myStack.pop();
	}

	for (int i = 0; i < N; i++)
	{
		cout << ans[i] << " ";
	}
}