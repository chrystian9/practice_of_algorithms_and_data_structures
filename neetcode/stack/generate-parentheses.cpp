#include <iostream>
#include <vector>

using namespace std;

void backtrack(int n, int openCount, int closedCount, string& stack, vector<string>& result) {
    if(openCount == closedCount and openCount == n){
        result.push_back(stack);
        return;
    }
    
    if(openCount < n){
        stack.push_back('(');
        backtrack(n, openCount + 1, closedCount, stack, result);
        stack.pop_back();
    }
    
    if(closedCount < openCount){
        stack.push_back(')');
        backtrack(n, openCount, closedCount + 1, stack, result);
        stack.pop_back();
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> result;
    string stack;
    backtrack(n, 0, 0, stack, result);
    return result;
}

int main()
{
    vector<string> result = generateParenthesis(4);
    
    for(const string& v : result){
        cout << v << ", ";
    }
    
    return 0;
}