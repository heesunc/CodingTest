#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <cctype>
#include <stdlib.h> // stoi, itoa를 위함
#include <cmath>
#include <unordered_map>
#include <map>
#include <sstream>

using namespace std;

// R일때마다 Reverse를 해주게 되면 시간초과가 됨
// T/F를 설정해줘서 reverse후 pop_back이나 pop_front를 출력하기

bool solution(deque<int>& dq, string& command) {
	bool rev = false; // true : back에서, false : front에서
	for (char& cmd : command) {
		if (cmd == 'R') rev = !rev;
		else {
			if (dq.size() == 0) return false;

			if (rev) dq.pop_back();
			else dq.pop_front();
		}
	}
	if (rev) reverse(dq.begin(), dq.end()); // 한번 뒤집어서 출력을 편하게 한다.
	return true;
}

int main() {
	ios::sync_with_stdio(false);	cin.tie(NULL);	cin.tie(NULL);

    deque<int> dq;
    string command, line, token;
    int tcase, cnt;

    cin >> tcase;
    while (tcase--) {
        cin >> command >> cnt >> line;

        rotate(line.begin(), line.begin() + 1, line.end()); // 시계방향 1칸 회전
        line.pop_back(); line.pop_back(); // 괄호 제거
        stringstream sstream(line);
        while (getline(sstream, token, ','))
            dq.push_back(stoi(token)); // 쉼표 기준으로 문자열 tokenization

        if (solution(dq, command)) {
            cout << '[';
            while (!dq.empty()) {
                cout << dq.front();
                dq.pop_front();
                if (dq.size() >= 1) cout << ',';
            }
            cout << "]\n";
        }
        else cout << "error\n";
    }
}