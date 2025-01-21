#include <iostream>
#include <stack>

using namespace std;

class MinStack {
public:
    MinStack() {}
    
    void push(int val) {
        _stack.push(val);

        if(_minValueStack.empty() || _minValueStack.top() > val){
            _minValueStack.push(val);
        } else {
            _minValueStack.push(_minValueStack.top());
        }
    }
    
    void pop() {
        _stack.pop();
        _minValueStack.pop();
    }
    
    int top() {
        return _stack.top();
    }
    
    int getMin() {
        return _minValueStack.top();
    }

private:
    stack<int> _stack;
    stack<int> _minValueStack;
};

int main()
{
    MinStack minStack;
    
    minStack.push(1);
    minStack.push(2);
    minStack.push(0);
    
    cout << minStack.getMin() << endl;
    
    minStack.pop();
    
    cout << minStack.top() << endl;
    cout << minStack.getMin() << endl;

    return 0;
}