#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    int squareRoot = sqrt(n);
    if (squareRoot * squareRoot == n) {
        return 1; // n is a square number
    } else {
        return 2; // n is not a square number
    }
}