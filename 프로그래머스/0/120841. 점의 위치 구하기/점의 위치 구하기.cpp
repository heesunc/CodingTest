#include <string>
#include <vector>

using namespace std;

int solution(vector<int> dot) {    
    // x 좌표와 y 좌표가 모두 양수이면 제1사분면
    if (dot[0] >= 0 && dot[1] >= 0)
        return 1;
    // x 좌표가 음수, y 좌표가 양수이면 제2사분면
    else if (dot[0] < 0 && dot[1] >= 0)
        return 2;
    // x 좌표와 y 좌표가 모두 음수이면 제3사분면
    else if (dot[0] < 0 && dot[1] < 0)
        return 3;
    else
        return 4;
}