#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	// 시간 단축을 위한 구문
	ios::sync_with_stdio(false);    cin.tie(NULL);    cout.tie(NULL);

	int strn;	
	cin >> strn;

	vector<int> n(strn, 0);
	for (int i = 0; i < strn; i++)
	{
		cin >> n[i];
	}

	sort(n.begin(), n.end());

	for (int i = 0; i < n.size(); i++)
	{
		cout << n[i] << "\n";
	}

	return 0;
}