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

void merge_sort(int s, int e);  // 병합 정렬 함수의 선언
static vector<int> A;           // 정렬할 배열
static vector<int> tmp;         // 임시 배열
static long result;             // 역순의 수를 저장하는 변수

int main() {
	ios::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);

	int N; cin >> N;
	A = vector<int>(N + 1, 0); // 정렬할 배열
	tmp = vector<int>(N + 1, 0); // 정렬 시 잠시 사용할 임시 배열

	for (int i = 1; i <= N; i++)
	{
		cin >> A[i];
	}

	result = 0;
	merge_sort(1, N); // 병합 정렬 수행
	cout << result << "\n";
}

void merge_sort(int s, int e) {
	if (e - s < 1) {                // 재귀 종료 조건: 배열의 크기가 1 이하이면 종료
		return;
	}

	int m = s + (e - s) / 2;        // 배열을 반으로 나누기 위한 중간 지점 계산
	merge_sort(s, m);               // 왼쪽 부분 배열을 정렬하기 위해 재귀 호출
	merge_sort(m + 1, e);           // 오른쪽 부분 배열을 정렬하기 위해 재귀 호출

	for (int i = s; i <= e; i++) {
		tmp[i] = A[i];              // 임시 배열에 배열의 값 복사
	}

	int k = s;                      // 임시 배열의 인덱스 변수
	int index1 = s;                 // 왼쪽 부분 배열의 시작 인덱스
	int index2 = m + 1;             // 오른쪽 부분 배열의 시작 인덱스

	while (index1 <= m && index2 <= e) {
		if (tmp[index1] > tmp[index2]) {
			A[k] = tmp[index2];     // 오른쪽 부분 배열의 값이 더 작으면 역순 발생
			result = result + index2 - k; // 발생한 역순의 수를 더함
			k++;
			index2++;
		}
		else {
			A[k] = tmp[index1];     // 왼쪽 부분 배열의 값이 더 작으면 그대로 진행
			k++;
			index1++;
		}
	}
	while (index1 <= m) {
		A[k] = tmp[index1];         // 남은 왼쪽 부분 배열의 값들을 복사
		k++;
		index1++;
	}
	while (index2 <= e) {
		A[k] = tmp[index2];         // 남은 오른쪽 부분 배열의 값들을 복사
		k++;
		index2++;
	}
}
