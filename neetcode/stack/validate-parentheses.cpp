#include <iostream>
#include <unordered_map>
#include <stack>

using namespace std;

bool isValid(string s) {
    if(s.length() % 2 != 0){
        return false;
    }
    
    unordered_map<char, char> map = {
        {'(',')'},
        {'[',']'},
        {'{','}'}
    };

    stack<char> stackChars;

    for(char c : s){
        if(stackChars.empty()){
            if(map.find(c) != map.end()){
                stackChars.push(c);
                continue;
            } else {
                return false;
            }
        } 
        
        char top = stackChars.top();
        
        if(map[top] == c){
            stackChars.pop();
        } else if(map.find(c) != map.end()){
            stackChars.push(c);            
        } else {
            return false;
        }
    }
    
    return stackChars.empty();
}

int main()
{
    // cout << isValid("[]");
    // cout << isValid("([{}])");
    // cout << isValid("[(])");
    cout << isValid("()[]{}");
    
    return 0;
}