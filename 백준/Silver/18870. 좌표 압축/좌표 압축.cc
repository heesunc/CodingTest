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

using namespace std;  // 표준 라이브러리(std)의 네임스페이스를 사용함

int main() {
    ios::sync_with_stdio(0);    cin.tie(0);

    int n;
    cin >> n;

    vector<int> coords(n);
    for (int i = 0; i < n; ++i) {
        cin >> coords[i];
    }

    // 좌표 압축을 위해 벡터를 복사하여 정렬 및 중복 제거
    vector<int> sorted_coords = coords;
    sort(sorted_coords.begin(), sorted_coords.end());
    sorted_coords.erase(unique(sorted_coords.begin(), sorted_coords.end()), sorted_coords.end());

    // 압축된 좌표를 저장할 맵 생성
    unordered_map<int, int> compressed;
    for (int i = 0; i < sorted_coords.size(); ++i) {
        compressed[sorted_coords[i]] = i;
    }

    // 원본 좌표를 압축된 좌표로 변환
    for (int i = 0; i < n; ++i) {
        cout << compressed[coords[i]] << " ";
    }
    cout << endl;
    
    return 0;
}