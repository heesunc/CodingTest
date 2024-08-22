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
#include <climits> // INT_MAX를 사용하기 위한 헤더 파일
#include <numeric>  // accumulate를 사용하기 위해 필요한 헤더 파일

using namespace std;  // 표준 라이브러리(std)의 네임스페이스를 사용함

int main() {
	// 시간 단축을 위한 구문
	ios::sync_with_stdio(false);    cin.tie(NULL);    cout.tie(NULL);

	int N; cin >> N;

	// 음수 큐
	priority_queue<int, vector<int>, greater<int>> mpq;
    // 양수 큐
    priority_queue<int> ppq;
    int one = 0;
    int zero = 0;

	for (int i = 0; i < N; i++)
	{
		int A; cin >> A;
        if (A < 0) // A가 0보다 작을 경우 음수 큐에 저장
        {
            mpq.push(A);
        }
        else if (A > 1) // A가 1보다 클 경우 양수 큐에 저장
        {
            ppq.push(A);
        }
        else if (A == 1) // A가 1일 경우 카운트
        {
            one++;
        }
        else // A가 0일 경우 카운트
        {
            zero++;
        }
	}

    int sum = 0;

    // 양수 큐 처리
    while (ppq.size() > 1) // 큐의 크기가 1보다 큰 경우에 반복
    {
        int ptop1 = ppq.top();
        ppq.pop();

        int ptop2 = ppq.top();
        ppq.pop();

        sum += (ptop1 * ptop2);
    }
    if (!ppq.empty()) // sum에 큐에 남아 있는 값 더해줌
    {
        sum += ppq.top();
        ppq.pop();
    }

    // 음수 큐 처리
    while (mpq.size() > 1)
    {
        int mtop1 = mpq.top();
        mpq.pop();

        int mtop2 = mpq.top();
        mpq.pop();

        sum += (mtop1 * mtop2);
    }
    if (!mpq.empty())
    {
        // 0이 존재하는 경우 mpq에 push해서 곱해도 0이기 때문에 따로 작성하지 않음
        if (zero == 0) 
        {
            sum += mpq.top();
            mpq.pop();
        }
    }
    sum += one;
    cout << sum << " ";
	return 0;
}