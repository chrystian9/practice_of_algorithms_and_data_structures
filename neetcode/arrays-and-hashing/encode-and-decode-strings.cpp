#include <iostream>
#include <vector>

using namespace std;

string encode(vector<string>& strs) {
    string result = "";

    for(const string s : strs){
        result += s + "spr-";
    }

    return result;
}

vector<string> decode(string s) {
    vector<string> result;
    string str = "";

    for(int i=0; i<s.size(); i++){
        if(s[i] == 's' and s[i+1] == 'p' and s[i+2] == 'r' and s[i+3] == '-') {
            result.push_back(str);
            str = "";
            i += 3;
        }else{
            str += s[i];
        }
    }

    return result;
}

int main()
{
    vector<string> input = {"neet","code","love","you"};
    // vector<string> input = {"we","say",":","yes"};

    string encodeStrs = encode(input);

    vector<string> decodeStrs = decode(encodeStrs);

    cout << "[";
    for(const string str : decodeStrs){
        cout << "\"" << str << "\" ";
    }
    cout << "]";
    
    return 0;
}