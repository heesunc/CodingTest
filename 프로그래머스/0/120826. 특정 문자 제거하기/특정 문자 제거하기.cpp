#include <string>
#include <vector>
#include <algorithm>
#include <regex>

using namespace std;

string solution(string my_string, string letter) {    
    my_string = regex_replace(my_string, regex(letter),"");
    
    return my_string;
}