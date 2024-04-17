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

// 비교 함수
bool compareLength(const string& a, const string& b) {
	if (a.length() == b.length())
	{
		return a < b;
	}
	return a.length() < b.length();
}

int main() {
	// 시간 단축을 위한 구문
	ios::sync_with_stdio(false);    cin.tie(NULL);    cout.tie(NULL);

	int n; cin >> n;
	vector<string> A(n);

	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
	}

	// 문자열의 길이에 따라 정렬
	sort(A.begin(), A.end(), compareLength);

	// 중복된 요소 제거
	A.erase(unique(A.begin(), A.end()), A.end());

	// 정렬된 문자열 출력
	for (const string& str : A) {
		cout << str << endl;
	}

	return 0;
}