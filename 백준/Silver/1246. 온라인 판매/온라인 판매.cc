#include <string>       // 문자열 처리를 위한 헤더 파일
#include <iostream>     // 입출력을 위한 헤더 파일
#include <vector>       // 동적 배열(vector)을 사용하기 위한 헤더 파일
#include <algorithm>    // 알고리즘 함수 (예: min())를 사용하기 위한 헤더 파일
#include <stack>        // 스택 자료구조를 사용하기 위한 헤더 파일
#include <queue>        // 큐 및 우선순위 큐(priority_queue)를 사용하기 위한 헤더 파일
#include <deque>        // 덱(Deque, 양방향 큐)을 사용하기 위한 헤더 파일
#include <cctype>       // 문자 처리를 위한 헤더 파일
#include <stdlib.h>     // 문자열을 숫자로 변환하는 함수(예: atoi())를 위한 헤더 파일
#include <cmath>        // 수학 함수를 사용하기 위한 헤더 파일
#include <unordered_map> // 해시맵(unordered_map)을 사용하기 위한 헤더 파일
#include <map>          // 맵(map, 정렬된 딕셔너리)을 사용하기 위한 헤더 파일
#include <sstream>      // 문자열 스트림을 사용하기 위한 헤더 파일
#include <cstdlib>      // 유틸리티 함수(예: rand(), exit())를 위한 헤더 파일
#include <iomanip>      // 입출력 서식을 지정하기 위한 헤더 파일
#include <climits>      // INT_MAX(최대 정수값)을 사용하기 위한 헤더 파일
#include <numeric>      // accumulate(누적 합)를 사용하기 위한 헤더 파일
#include <limits.h>     // 시스템 한계값들을 정의하는 헤더 파일 (ex: LONG_MAX)
#include <ctime>
#include <set>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	// n개의 달걀, 잠재 고객 m명
	int n, m; cin >> n >> m;

	vector<int> p(m);
	// i번째 고객
	for (int i = 0; i < m; i++)
	{
		cin >> p[i];
	}

	sort(p.begin(), p.end());

	// p[i]중 가격의 하나를 선택해서, 그 중 최대 수익이 무엇인지
	
	int maxMoney = 0; int bestMoney = 0;
	// 각 고객이 제시한 가격을 판매 가격 후보로 사용
	for (int i = 0; i < m; i++) 
	{
		int price = p[i]; // 현재 선택한 가격
		int sellCount = min(n, m - i); // 현재 가격 이상으로 달걀을 살 수 있는 고객 수와 달걀 수 중 작은 값
		int profit = price * sellCount; // 현재 가격으로 팔았을 때의 수익

		// 최대 수익과 가격 갱신
		if (profit > maxMoney) 
		{
			maxMoney = profit;
			bestMoney = price;
		}
	}

	// 결과 출력
	cout << bestMoney << " " << maxMoney << endl;

	return 0;
}