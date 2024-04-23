#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>

using namespace std;

void josephus(int n, int k) {
    deque<int> circle;

    // 원형으로 배치된 요소들을 덱에 추가
    for (int i = 1; i <= n; ++i) {
        circle.push_back(i);
    }

    cout << "<";
    while (!circle.empty()) {
        // k번째 요소를 제거하고 출력
        for (int i = 0; i < k - 1; ++i) {
            circle.push_back(circle.front());
            circle.pop_front();
        }
        cout << circle.front();
        circle.pop_front(); // k번째 요소 제거
        if (!circle.empty()) cout << ", ";
    }
    cout << ">" << endl;
}

int main() {
	ios::sync_with_stdio(false);	cin.tie(NULL);	cin.tie(NULL);

	int n;	cin >> n;
	int k;  cin >> k;
	
	josephus(n, k);

	return 0;
}