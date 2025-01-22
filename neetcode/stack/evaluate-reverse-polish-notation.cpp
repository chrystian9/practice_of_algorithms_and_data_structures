#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool isOperator(string token) {
    int number;

    try {
        number = stoi(token);
    } catch (const invalid_argument& e) {
        return true;
    } catch (const out_of_range& e) {
        cerr << "Erro: o número está fora do intervalo de um int." << endl;
    }

    return false;
}

int dfs(vector<string>& tokens) {
    string token = tokens.back();
    tokens.pop_back();

    if(isOperator(token)){
        int rightValue = dfs(tokens);
        int leftValue = dfs(tokens);

        if (token == "+") {
            return leftValue + rightValue;
        } else if(token == "-") {
            return leftValue - rightValue;
        } else if(token == "/") {
            return leftValue / rightValue;
        } else if(token == "*") {
            return leftValue * rightValue;
        }
    }
    
    return stoi(token);
}

int evalRPN(vector<string>& tokens) {
    return dfs(tokens);
}

// int evalRPN(vector<string>& tokens) {
//     stack<int> stack;
//     for (const string& c : tokens) {
//         if (c == "+") {
//             int a = stack.top(); stack.pop();
//             int b = stack.top(); stack.pop();
//             stack.push(b + a);
//         } else if (c == "-") {
//             int a = stack.top(); stack.pop();
//             int b = stack.top(); stack.pop();
//             stack.push(b - a);
//         } else if (c == "*") {
//             int a = stack.top(); stack.pop();
//             int b = stack.top(); stack.pop();
//             stack.push(b * a);
//         } else if (c == "/") {
//             int a = stack.top(); stack.pop();
//             int b = stack.top(); stack.pop();
//             stack.push(b / a);
//         } else {
//             stack.push(stoi(c));
//         }
//     }
//     return stack.top();
// }

int main()
{
    // vector<string> input = {"1","2","+","3","*","4","-"};
    vector<string> input = {"2","1","+","3","*"};
    
    cout << evalRPN(input);
    
    return 0;
}