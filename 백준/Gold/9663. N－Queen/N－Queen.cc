#include <string>       // 문자열 처리를 위한 헤더 파일
#include <iostream>     // 입출력을 위한 헤더 파일
#include <vector>       // 동적 배열(vector)을 사용하기 위한 헤더 파일
#include <algorithm>    // 알고리즘 함수를 사용하기 위한 헤더 파일
#include <stack>        // 스택을 사용하기 위한 헤더 파일
#include <queue>        // 큐를 사용하기 위한 헤더 파일
#include <deque>        // 덱(Deque)을 사용하기 위한 헤더 파일
#include <cctype>       // 문자열의 문자를 검사하기 위한 헤더 파일
#include <stdlib.h>     // 문자열을 숫자로 변환하는 함수를 사용하기 위한 헤더 파일
#include <cmath>        // 수학 함수를 사용하기 위한 헤더 파일
#include <unordered_map> // 해시맵(Unordered Map)을 사용하기 위한 헤더 파일
#include <map>          // 맵(Map)을 사용하기 위한 헤더 파일
#include <sstream>      // 문자열을 스트림으로 변환하기 위한 헤더 파일
#include <cstdlib>      // 일반적인 유틸리티 함수를 사용하기 위한 헤더 파일
#include <iomanip>      // 입출력 서식 지정을 위한 헤더 파일

using namespace std;  // 표준 라이브러리(std)의 네임스페이스를 사용함

int n;
vector<int>board;
void n_queen(int i);
bool promising(int i);
unsigned long long sum = 0;

int main()
{
	cin >> n; //보드 크기
	board.resize(n + 1);
	n_queen(0);
	cout << sum << endl;// << Max;
}
void n_queen(int i)
{
	if (promising(i) == 1) //promising이 1이면 안짜르고 0이면 가지치기
	{
		if (i == n) // 모든 행에 퀸을 놓았음
		{
			sum++;
		}
		else // 현재 행에서 가능한 모든 열에 퀸을 놓기 위한 반복문
		{
			for (int j = 1; j <= n; j++)
			{
				board[i + 1] = j; // i+1번째 행의 j열에 퀸을 놓음
				n_queen(i + 1); // 다음 행으로 이동하여 재귀 홏출
			}
		}			
	}
}
bool promising(int i) // i는 퀸을 놓을 행을 나타내는 변수
{
	int idx = 1;
	bool flag = true;
	while (idx < i && flag) // idx가 넘지 않을 때 까지 반복, 그리고 참인값을 찾으면 promising 종료
	{
		if (board[i] == board[idx] || abs(board[i] - board[idx]) == abs(i - idx)) //같은열과 대각선 전부다 제외
		{
			flag = false;
		}
		idx++;
	}
	return flag;
}