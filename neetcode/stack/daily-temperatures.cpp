#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) {
    stack<int> indices;
    stack<int> resultStack;

    resultStack.push(0);
    for (int i = temperatures.size() - 2; i >= 0; --i) {
        if(temperatures[i] >= temperatures[i+1]){
            if(resultStack.top() == 0){
                resultStack.push(0);
            } else {
                bool control = true;

                while(control){
                    if(indices.size() == 0){
                        resultStack.push(0);
                        control = false;
                    } else {
                        int nextHighestValueIndex = indices.top();

                        if(temperatures[i] >= temperatures[nextHighestValueIndex]){
                            indices.pop();
                        } else {
                            resultStack.push(nextHighestValueIndex - i);
                            control = false;
                        }
                    }
                }
            }
        } else {
            resultStack.push(1);
            indices.push(i+1);
        }
    }

    vector<int> result;

    for (int i = 0; i < temperatures.size(); i++) {
        result.push_back(resultStack.top());
        resultStack.pop();
    }

    return result;
}

int main()
{
    vector<int> input = {30,38,30,36,35,40,28};
    vector<int> result = dailyTemperatures(input);
    
    for(const int& v : result){
        cout << v << ", ";
    }
    
    return 0;
}