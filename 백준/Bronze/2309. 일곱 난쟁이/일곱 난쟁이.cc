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

using namespace std;

int main() {
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    // 일곱 난쟁이의 키의 합은 100

    vector<int> nine(9);
    int key = 100;
    int ninesum = 0;

    for (int i = 0; i < 9; i++)
    {
        cin >> nine[i];
        ninesum += nine[i];
    }

    int target = ninesum - key;
    vector<int> result;

    for (int i = 0; i < nine.size(); i++)
    {
        for (int j = i + 1; j < nine.size(); j++)
        {
            if (nine[i] + nine[j] == target)
            {
                for (int k = 0; k < nine.size(); k++)
                {
                    if (k != i && k != j)
                    {
                        result.push_back(nine[k]);
                    }
                }
                // 두 난쟁이를 찾았으므로 루프 종료
                goto output;
            }
        }
    }

output:
    // 일곱 난쟁이의 키를 오름차순으로 출력
    sort(result.begin(), result.end());
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << "\n";
    }

    return 0;
}