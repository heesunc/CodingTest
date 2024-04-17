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

vector<pair<int, int>> v;

int main() {
	// 시간 단축을 위한 구문
	ios::sync_with_stdio(false);    cin.tie(NULL);    cout.tie(NULL);

	int N;
	cin >> N;
	int x, y;

	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		v.push_back({ y, x });
	}

	// pair와 같은 복합 자료구조인 경우, 
	// 첫 번째 요소를 기준으로 먼저 정렬하고, 
	// 첫 번째 요소가 같은 경우에는 두 번째 요소를 기준으로 정렬
	sort(v.begin(), v.end());
	for (int i = 0; i < N; i++) {
		cout << v[i].second << ' ' << v[i].first << '\n';
	}

	return 0;
}