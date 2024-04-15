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

	// 알파벳 대소문자로 된 단어가 주어짐
	string str; cin >> str;

	// 가장 많이 사용된 알파벳이 무엇인지 대문자로 출력
	// 대문자와 소문자는 구분하지 않음
	// -> 다 대문자로 바꾸고 시작하자
	transform(str.begin(), str.end(), str.begin(), ::toupper);
	unordered_map<char, int> Map;

	for (char ch : str) {
		if (isalpha(ch)) // 알파벳인 경우에만 카운트
			Map[ch]++;
	}

	int maxFrequency = 0;
	char mostFrequentChar = '?';

	// 가장 많이 등장한 문자의 빈도수 찾기
	for (const auto& pair : Map) {
		if (pair.second > maxFrequency) {
			mostFrequentChar = pair.first;
			maxFrequency = pair.second;
		}
		else if (pair.second == maxFrequency) {
			mostFrequentChar = '?';
		}
	}	

	if (mostFrequentChar == '?') {
		cout << "?" << endl;
	}
	else {
		cout << mostFrequentChar << endl;
	}

	return 0;
}