#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int T; 
    cin >> T; // 테스트 케이스 개수 입력
    string a, b;

    for (int i = 0; i < T; i++) {
        cin >> a >> b;

        // 두 문자열의 길이가 다르면 바로 불가능 출력
        if (a.length() != b.length()) {
            cout << "Impossible" << "\n";
            continue;
        }

        // 문자열을 정렬하여 비교
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        if (a == b) {
            cout << "Possible" << "\n";
        } else {
            cout << "Impossible" << "\n";
        }
    }

    return 0;
}
