#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> picture, int k) {
    vector<string> answer;
    
    // picture요소 값을 str row에
    for(const string& row : picture)
    {
        // 새로운 str 선언
        string enlargedRow;
        // 요소값인 str row를 char 하나씩 잘라줌
        for (char pixel : row)
        {
            // 그걸 k배만큼 ++i해줌
            for(int i=0; i<k; ++i)
            {
                enlargedRow += pixel;
            }
        }
        for (int i=0; i<k; ++i)
        {
            answer.push_back(enlargedRow);
        }
    }
    
    return answer;
}