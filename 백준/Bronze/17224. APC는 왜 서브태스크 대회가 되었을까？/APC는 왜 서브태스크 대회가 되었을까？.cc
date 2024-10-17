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

    // 첫 번째 줄: N, L, K 입력받기
	int N, L, K; cin >> N >> L >> K;

    // 두 번째 줄부터: 각 문제의 쉬운 버전과 어려운 버전 난이도를 저장할 벡터
    vector<pair<int, int>> problems(N);

    // 문제의 난이도(sub1, sub2)를 입력받기
    for (int i = 0; i < N; ++i) {
        int sub1, sub2;
        cin >> sub1 >> sub2;
        problems[i] = { sub1, sub2 };  // (쉬운 난이도, 어려운 난이도) 쌍을 저장
    }

    vector<int> result;

    for (int i = 0; i < problems.size(); i++)
    {
        // sub1, sub2의 난이도가 L 이하일 경우
        if (problems[i].first <= L && problems[i].second <= L)
        {
            result.push_back(140);
        }
        // sub1의 난이도만 풀 수 있는 경우
        else if (problems[i].first <= L && problems[i].second > L)
        {
            result.push_back(100);
        }
    }
    
    // 내림차순
    sort(result.begin(), result.end(), greater<int>());
    int score = 0;

    // result를 풀 수 있는 개수 k만큼만 score에 더해주어야함
    // k보다 result가 적을 수 있음

    if (K <= result.size())
    {
        for (int i = 0; i < K; i++)
        {
            score += result[i];
        }
    }
    else
    {
        for (int i = 0; i < result.size(); i++)
        {
            score += result[i];
        }
    }    

    cout << score << "\n";

	return 0;
}