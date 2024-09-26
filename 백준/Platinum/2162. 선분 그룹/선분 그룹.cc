#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

struct Line {
    int x1, y1, x2, y2;
};

int N;
Line line[3001];
int parent[3001];
int cnt[3001];

// 경로 압축을 적용한 유니온 파인드의 getParent 함수
int getParent(int a) {
    if (a == parent[a]) return parent[a];
    return parent[a] = getParent(parent[a]);
}

// 랭크 기반 유니온을 추가한 unionSet 함수
void unionSet(int a, int b) {
    a = getParent(a); b = getParent(b);
    if (a != b) {
        parent[b] = a;  // 랭크를 사용하지 않지만 간단하게 작은 값을 우선으로 함
    }
}

// CCW를 계산하는 함수
int CCW(int x1, int y1, int x2, int y2, int x3, int y3) {
    long long temp = (x1 * y2 + x2 * y3 + x3 * y1) - (y1 * x2 + y2 * x3 + y3 * x1);
    if (temp < 0) return -1;
    else if (temp > 0) return 1;
    return 0;
}

// 두 선분이 교차하는지 여부를 판정하는 함수
bool isCross(Line L1, Line L2) {
    int x1 = L1.x1, y1 = L1.y1, x2 = L1.x2, y2 = L1.y2;
    int x3 = L2.x1, y3 = L2.y1, x4 = L2.x2, y4 = L2.y2;

    int ccw1 = CCW(x1, y1, x2, y2, x3, y3);
    int ccw2 = CCW(x1, y1, x2, y2, x4, y4);
    int ccw3 = CCW(x3, y3, x4, y4, x1, y1);
    int ccw4 = CCW(x3, y3, x4, y4, x2, y2);

    // 두 선분이 교차하는 조건
    if (ccw1 * ccw2 <= 0 && ccw3 * ccw4 <= 0) {
        // 선분이 겹치는지 여부 확인
        if (min(x1, x2) <= max(x3, x4) && min(x3, x4) <= max(x1, x2) &&
            min(y1, y2) <= max(y3, y4) && min(y3, y4) <= max(y1, y2)) {
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 입력 받기
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> line[i].x1 >> line[i].y1 >> line[i].x2 >> line[i].y2;
        parent[i] = i;  // 초기 부모는 자기 자신
    }

    // 교차 여부 확인 및 유니온 파인드 사용
    memset(cnt, 0, sizeof(cnt));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j < i; j++) {
            if (isCross(line[i], line[j])) {
                unionSet(i, j);
            }
        }
    }

    // 각 그룹의 크기를 카운트
    for (int i = 1; i <= N; i++) {
        cnt[getParent(i)]++;
    }
    
    // 결과 계산
    int gCount = 0;
    int Max = 0;
    for (int i = 1; i <= N; i++) {
        if (cnt[i]) gCount++;  // 그룹의 개수
        Max = max(Max, cnt[i]);  // 가장 큰 그룹의 크기
    }

    cout << gCount << '\n';  // 그룹의 개수 출력
    cout << Max << '\n';     // 가장 큰 그룹의 크기 출력

    return 0;
}
