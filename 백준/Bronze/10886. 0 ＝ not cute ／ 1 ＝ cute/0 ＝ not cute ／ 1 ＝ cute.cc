#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);

    int n; cin >> n;
    vector<int> a;

    for (int i = 0; i < n; i++)
    {
        int c; cin >> c;
        a.push_back(c);
    }

    int countc = 0; int countu = 0;
    for (int i=0; i<a.size(); i++)
    {
        if (a[i] == 1)
            countc++;
        else if (a[i] == 0)
            countu++;
    }

    if (countc > countu)
    {
        cout << "Junhee is cute!";
    }
    else if (countu > countc)
    {
        cout << "Junhee is not cute!";
    }
}