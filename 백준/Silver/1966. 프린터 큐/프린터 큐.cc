#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);	cin.tie(NULL);	cin.tie(NULL);

	int t;
	int n, m, num;
	cin >> t;

	for (int i = 0; i < t; i++) // 테스트 케이스만큼
	{
		int cnt = 0;
		queue<pair<int, int>>q; // 각 문서의 순서, 중요도 저장
		priority_queue<int>pq; // 중요도만 저장
		cin >> n >> m; // 문서의 개수와 찾고자하는 문서의 인덱스 입력

		for (int j = 0; j < n; j++) // 문서의 개수만큼
		{
			cin >> num;

			q.push({ j, num }); // j는 문서 순서, num은 중요도
			pq.push(num); // 우선순위 큐에 중요도 담기
		}

		while (!pq.empty()) // pq가 빌 때까지
		{
			int idx = q.front().first;  // 문서 순서
			int prior = q.front().second; // 중요도
			q.pop(); // 이러면 계속 front가 바뀌니까
			if (pq.top() == prior) // 중요도가 높은 경우
			{
				cnt++; // 카운트 증가
				pq.pop(); // 해당 중요도 제거
				if (idx == m) // 찾고자 하는 문서일 경우
				{
					cout << cnt << "\n"; // 현재 카운터 값을 출력
					break;
				}
			}
			else // 중요도가 높은 문서가 남아있는 경우
				q.push({ idx, prior });
		}
	}

	return 0;
}