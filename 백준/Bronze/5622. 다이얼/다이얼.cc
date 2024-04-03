#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cctype>
#include <stdlib.h> // stoi, itoa를 위함

using namespace std;

int main() {
	// 시간 단축을 위한 구문
	ios::sync_with_stdio(false);    cin.tie(NULL);    cout.tie(NULL);

	string str; cin >> str;
	int time = 0;

	for (char ch : str)
	{
		switch (ch)
		{
		case 'A':
		case 'B':
		case 'C':
			time += 3; break;
		case 'D':
		case 'E':
		case 'F':
			time += 4; break;
		case 'G':
		case 'H':
		case 'I':
			time += 5; break;
		case 'J':
		case 'K':
		case 'L':
			time += 6; break;
		case 'M':
		case 'N':
		case 'O':
			time += 7; break;
		case 'P':
		case 'Q':
		case 'R':
		case 'S':
			time += 8; break;
		case 'T':
		case 'U':
		case 'V':
			time += 9; break;
		case 'W':
		case 'X':
		case 'Y':
		case 'Z':
			time += 10; break;
		}
	}

	cout << time;

	return 0;
}