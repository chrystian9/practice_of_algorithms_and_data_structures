#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool isAnagram(string s, string t) {
    if(s.length() != t.length()) return false;

    unordered_map<char, int> stringsDict1;
    unordered_map<char, int> stringsDict2;

    for (int i=0; i < s.length(); i++) {
        stringsDict1[s[i]]++;
        stringsDict2[t[i]]++;
    }

    if (stringsDict1.size() != stringsDict2.size()) return false;

    for (const auto& pair : stringsDict1) {
        if (stringsDict2.find(pair.first) == stringsDict2.end() || stringsDict2[pair.first] != pair.second)
            return false;
    }

    return true;
}

int main()
{
    cout << isAnagram("racecar", "carrace");
    
    return 0;
}