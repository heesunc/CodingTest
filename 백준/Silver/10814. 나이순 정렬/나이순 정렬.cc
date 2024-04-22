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
#include <map>

using namespace std;

static vector<pair<int, string>> member;
bool compare(pair<int, string> a, pair<int, string> b) {
	return a.first < b.first;
};

int main() {
	ios::sync_with_stdio(false);	cin.tie(NULL);	cin.tie(NULL);

	int n;	cin >> n;

	member = vector<pair<int, string>>(n);

	for (int i = 0; i < n; i++) {
		cin >> member[i].first >> member[i].second;
	}

	stable_sort(member.begin(), member.end(), compare);

	for (int i = 0; i < n; i++) {
		cout << member[i].first << " " << member[i].second << '\n';
	}

	return 0;
}