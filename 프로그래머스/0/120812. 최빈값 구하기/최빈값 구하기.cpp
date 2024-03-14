#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<int> array) {
    unordered_map<int, int> freqMap;

    // Count the frequency of each number
    for (int num : array) {
        freqMap[num]++;
    }

    // Find the number with the highest frequency
    int mode = -1;
    int maxFreq = 0;
    bool isUnique = true;
    for (const auto& pair : freqMap) {
        if (pair.second > maxFreq) {
            maxFreq = pair.second;
            mode = pair.first;
            isUnique = true;
        } else if (pair.second == maxFreq) {
            isUnique = false; // Found another mode
        }
    }

    // If there are multiple modes, return -1
    if (!isUnique) {
        mode = -1;
    }

    return mode;
}