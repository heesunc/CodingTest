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
#include <unordered_set>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	// 돌림판에 붙어있을 수 있는 스티커의 최대 개수를 출력한다. (결과값 X)
	int n; cin >> n;
	vector<int> menu(n * 2);
	stack<int> sticker; // 스티커를 관리할 스택
	int result = 0; // 최대 스티커 수
	unordered_set<int> currentStickers;  // 현재 붙어있는 스티커
	for (int i = 0; i < n * 2; i++)
	{
		cin >> menu[i];
	}

	for (int i = 0; i < menu.size(); i++)
	{
		// 현재 메뉴가 현재 스티커에 붙어있지 않다면
		if (currentStickers.find(menu[i]) == currentStickers.end()) {
			sticker.push(menu[i]);  // 스티커 추가
			currentStickers.insert(menu[i]);  // 스티커 상태 업데이트
		}
		else { // 이미 붙어 있는 경우
			sticker.pop();  // 스티커 제거
			currentStickers.erase(menu[i]);  // 스티커 상태 업데이트
		}
		// 현재 스택의 크기와 최대 크기 비교
		result = max(result, (int)sticker.size());
	}

	cout << result << "\n";

    return 0;
}