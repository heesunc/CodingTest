#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer(n, vector<int>(n,0));
    
    int i=0, j=-1, k=0, sw=1, p=n;
    
    while(true)
    {
        for(int l=0; l<p; l++)
        {
            k=k+1;
            j=j+sw;
            answer[i][j] = k;
        }
        p=p-1;
        if(p<=0) break;
        
        for(int m=0; m<p; m++)
        {
            k=k+1;
            i=i+sw;
            answer[i][j]=k;
        }
        sw*=-1;
    }
    
    for(int q=0; q<n; q++)
    {
        for(int r=0; r<n; r++)
        {
            answer[q][r];
        }
    }
    
    return answer;
}