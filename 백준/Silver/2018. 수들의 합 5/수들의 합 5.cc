#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // 시간 단축을 위한 구문
    ios::sync_with_stdio(false);    cin.tie(NULL);    cout.tie(NULL);

    int N;
    cin >> N;

    int count = 1;
    int start_index = 1;
    int end_index = 1;
    int sum = 1;

    while (end_index != N)
    {
        if (sum == N)
        {
            count++;
            end_index++;
            sum = sum + end_index;
        }
        else if (sum > N)
        {
            sum = sum - start_index;
            start_index++;
        }
        else
        {
            end_index++;
            sum = sum + end_index;
        }
    }
    cout << count << "\n";
}