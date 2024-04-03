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

	int a, b; cin >> a >> b; // 두 수
	string stra = to_string(a); string strb = to_string(b); // 형변환
	
	reverse(stra.begin(), stra.end());
	reverse(strb.begin(), strb.end());
	
	a = atoi(stra.c_str());
	b = atoi(strb.c_str());
	
	if (a > b)
	{
		cout << a;
	}
	else
	{
		cout << b;
	}

	return 0;
}