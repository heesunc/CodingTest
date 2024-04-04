#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cctype>
#include <stdlib.h> // stoi, itoa를 위함

using namespace std;

int main() {
	// 시간 단축을 위한 구문
	ios::sync_with_stdio(false);    cin.tie(NULL);    cout.tie(NULL);

	int N; cin >> N;

	queue<int> myQueue;

	for (int i = 1; i <= N; i++)
	{
		myQueue.push(i);
	}

	while (myQueue.size() > 1) // 카드가 한 장 남을 때까지
	{
		myQueue.pop();
		myQueue.push(myQueue.front());
		myQueue.pop();
	}

	cout << myQueue.front();
}