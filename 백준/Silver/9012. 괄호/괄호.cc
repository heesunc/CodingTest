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

string isVPS(string& str)
{
	stack<char> vps;
	for (char c : str)
	{
		if (c == '(')
			vps.push(c);
		else if (c == ')')
		{
			if (!vps.empty() && vps.top() == '(')
				vps.pop();
			else
				return "NO";
		}
	}
	if (vps.empty())
		return "YES";
	else
		return "NO";
}

int main() {
	ios::sync_with_stdio(false);	cin.tie(NULL);	cin.tie(NULL);

	int n;	cin >> n;
	string str;

	for (int i = 0; i < n; i++)
	{
		cin >> str;
		cout << isVPS(str) << "\n";
	}

	return 0;
}