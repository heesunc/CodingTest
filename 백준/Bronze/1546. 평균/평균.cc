// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.

#include <string>
#include <vector>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n = 0; // 시험을 본 과목의 개수
    int a[1000]; // 과목 데이터 저장

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i]; // a[i]의 값(성적) 입력
    }

    long sum = 0;
    long max = 0;

    for (int i =0; i<n; i++)
    {
        if (max < a[i])
        {
            max = a[i];
        }
        sum = sum + a[i];
    }

    double result = sum * 100.0 / max / n;

    cout << result << endl;

    return 0;
}