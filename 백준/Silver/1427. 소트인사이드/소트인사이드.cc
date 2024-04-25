#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <cctype>
#include <stdlib.h> // stoi, itoa를 위함
#include <cmath>
#include <unordered_map>
#include <map>
#include <sstream> // 공백 구분
#include <cstdlib>
#include <iomanip> // setprecision을 사용하기 위해 필요

using namespace std;

int main() {
    ios::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);

    string str; cin >> str;
    vector<int> A(str.size(), 0);

    for (int i = 0; i < str.size(); i++)
    {
        A[i] = stoi(str.substr(i, 1));
    }

    for (int i = 0; i < str.length(); i++)
    {
        int Max = i;
        for (int j = i + 1; j < str.length(); j++)
        {
            if (A[j] > A[Max])
            {
                Max = j;
            }
        }
        if (A[i] < A[Max])
        {
            int temp = A[i];
            A[i] = A[Max];
            A[Max] = temp;
        }
    }
    for (int i = 0; i < A.size(); i++)
    {
        cout << A[i];
    }
}