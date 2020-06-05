#include <iostream>
#include <stack>

using namespace std;

//利用栈实现队列结构，需要注意栈为空的情况
template<class T>
class StackToQueue
{
public:
    void push(T value)
    {
        _stack.push(value);
    }

    void pop(void)
    {
        if (_helpStack.empty() && !_stack.empty()) {
            while (_stack.size() > 1) {
                _helpStack.push(_stack.top());
                _stack.pop();
            }
            _stack.pop();
        } else if (!_helpStack.empty()){
            _helpStack.pop();
        }
    }

    T front(void)
    {
        if (_helpStack.empty() && !_stack.empty()) {
            while (_stack.size() > 1) {
                _helpStack.push(_stack.top());
                _stack.pop();
            }
            int value = _stack.top();
            _helpStack.push(value);
            _stack.pop();
            return value;
        } else if (!_helpStack.empty()){
            return _helpStack.top();
        }
    }

private:
    stack<T> _stack;
    stack<T> _helpStack;
};

int main(void)
{
    StackToQueue<int> queue;
    queue.push(2);
    queue.push(3);
    cout << queue.front() << endl;
    queue.pop();
    cout << queue.front() << endl;
    queue.push(4);
    queue.push(5);
    queue.push(6);
    queue.push(7);
    cout << queue.front() << endl;
    queue.pop();
    cout << queue.front() << endl;
    return 0;
}