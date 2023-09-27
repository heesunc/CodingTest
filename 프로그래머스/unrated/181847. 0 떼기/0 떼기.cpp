#include <string>
#include <vector>

using namespace std;

string solution(string n_str) {
    // Find the first non-zero character index
    size_t firstNonZero = n_str.find_first_not_of('0');
    
    // If there are no non-zero characters, return "0"
    if (firstNonZero == string::npos) {
        return "0";
    }
    
    // Otherwise, return the substring starting from the first non-zero character
    return n_str.substr(firstNonZero);
}
