#include <string>
#include <unordered_map>

using namespace std;

string solution(string letter) {
    string answer = "";
    string temp = "";

    unordered_map<string, string> morseToAlpha = {
        {".-", "a"}, {"-...", "b"}, {"-.-.", "c"}, {"-..", "d"}, {".", "e"},
        {"..-.", "f"}, {"--.", "g"}, {"....", "h"}, {"..", "i"}, {".---", "j"},
        {"-.-", "k"}, {".-..", "l"}, {"--", "m"}, {"-.", "n"}, {"---", "o"},
        {".--.", "p"}, {"--.-", "q"}, {".-.", "r"}, {"...", "s"}, {"-", "t"},
        {"..-", "u"}, {"...-", "v"}, {".--", "w"}, {"-..-", "x"}, {"-.--", "y"},
        {"--..", "z"}
    };

    for (char c : letter) {
        if (c != ' ')
            temp.push_back(c);
        else {
            if (!temp.empty()) {
                answer += morseToAlpha[temp];
                temp.clear();
            }
        }
    }

    if (!temp.empty())
        answer += morseToAlpha[temp];

    return answer;
}
