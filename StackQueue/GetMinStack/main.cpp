#include <iostream>
#include <stack>

using namespace std;

/*
 *问题描述：实现一个特殊的栈，在实现栈的基本功能的基础上，再实现返
           回栈中最小元素的操作
 */
class MinStack
{
public:
    void push(int value)
    {
        _stack.push(value);
        if (_minStack.empty()) {
            _minStack.push(value);
        } else {
            int elem = value < _minStack.top() ? value : _minStack.top();
            _minStack.push(elem);
        }

    }

    void pop(void)
    {
        if (!_stack.empty()) {
            _stack.pop();
            _minStack.pop();
        }
    }

    int top(void) { return _stack.top(); }

    int getMin(void) { return _minStack.top(); }

private:
    stack<int> _stack;
    stack<int> _minStack;
};

int main(void)
{
    MinStack minStack;
    minStack.push(10);
    minStack.push(1);
    minStack.push(6);

    minStack.push(4);
    minStack.push(7);
    minStack.push(10);
    cout << minStack.getMin() << endl;
    return 0;
}