#include <iostream>
#include <queue>

using namespace std;

//利用队列结构实现栈结构
template <class T>
class QueueToStack
{
public:
    void push(T value)
    {
        _queue.push(value);
    }

    void pop(void)
    {
        if (!_queue.empty()) {
            while (_queue.size() > 1) {
                _helpQueue.push(_queue.front());
                _queue.pop();
            }
            _queue.pop();
            _queue.swap(_helpQueue);
        }
    }

    T top(void)
    {
        //这里使用了C++提供的back方法，如果没有该方法，实现top成员函数的思路和上面的pop思路类似
        if (!_queue.empty()) {
            return _queue.back();
        }
    }

private:
    queue<T> _queue;
    queue<T> _helpQueue;
};

int main(void)
{
    QueueToStack<int> stack;
    stack.push(1);
    stack.push(3);
    stack.push(2);
    cout << stack.top() << endl;
    stack.pop();
    cout << stack.top() << endl;
    stack.push(5);
    stack.push(6);
    stack.push(8);
    stack.push(9);
    stack.push(3);
    cout << stack.top() << endl;
    stack.pop();
    return 0;
}