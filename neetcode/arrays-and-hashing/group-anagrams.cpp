#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) { // O(n)
    if(strs.size() == 1) return {{strs[0]}};
    
    struct VectorHash {
        size_t operator()(const vector<int>& vec) const {
            size_t hash = 0;
            for (int val : vec) {
                hash ^= hash<int>()(val) + 0x9e3779b9 + (hash << 6) + (hash >> 2);
            }
            return hash;
        }
    };

    unordered_map<vector<int>, vector<string>, VectorHash> resultMap;

    for(const string& str : strs) {
        vector<int> key(26, 0);
        
        for (char c : str) {
            key[c - 'a']++;
        }
        
        resultMap[key].push_back(str);
    }

    vector<vector<string>> resultVector;
    
    for (const auto& pair : resultMap) {
        resultVector.push_back(pair.second);
    }
    
    return resultVector;
}

int main()
{
    vector<string> input = {"cab","tin","pew","duh","may","ill","buy","bar","max","doc"};
    
    vector<vector<string>> result = groupAnagrams(input);
    
    cout << "[";
    for(const vector<string>& v : result){
        cout << "[";
        for(const string& str : v){
            cout << "\"" << str << "\" ";
        }
        cout << "] ";
    }
    cout << "]";
    
    return 0;
}