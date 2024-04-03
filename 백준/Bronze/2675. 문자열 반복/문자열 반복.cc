#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cctype>

using namespace std;

int main() {
	// 시간 단축을 위한 구문
	ios::sync_with_stdio(false);    cin.tie(NULL);    cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int r;
        string str;
        cin >> r >> str;

        // 각 문자의 반복 횟수를 누적하여 출력
        for (char c : str) {
            for (int j = 0; j < r; j++) {
                cout << c;
            }
        }
        cout << '\n';
    }

    return 0;
}