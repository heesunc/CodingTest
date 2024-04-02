#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int main() {
	// 시간 단축을 위한 구문
	ios::sync_with_stdio(false);    cin.tie(NULL);    cout.tie(NULL);

	string str;	

	/*
	getline(cin, 문자열 변수) 함수를 이용하여 공백을 포함한 한 줄을 입력 받아
	파라미터로 입력된 변수에 저장한다.
    입력된 값이 없을 경우 ""로 저장므로 이를 활용하여 
	반복문 종료 지점을 정의할 수 있다.
	*/

	while (true)
	{
		getline(cin, str);
		if (str == "") break;

		cout << str << "\n";
	}

	return 0;
}