#include <iostream>
#include <vector>

using namespace std;

//固定大小实现栈结构
template<class T>
class Stack
{
public:
    Stack(int size)
    : _size(size)
    , _index(0)
    , nums(new T[_size]{0})
    { }

    ~Stack() { delete [] nums; }

    void push(T value)
    {
        if (isFull())
            return;
        nums[_index++] = value;
    }

    T pop(void)
    {
        if (!isEmpty())
            return nums[--_index];
    }

    T peek(void)
    {
        if (!isEmpty())
            return nums[_index - 1];
    }

    bool isEmpty(void) { return _index == 0; }

    bool isFull(void) { return _index == _size; }

    void print(void)
    {
        for (int i = 0; i < _index; ++i) {
            cout << nums[i] << " ";
        }
        cout << endl;
    }

private:
    int _size;
    int _index;
    T * nums;
};

int main(void)
{
    Stack<int> stack(10);
    for (int i = 0; i < 10; i++)
        stack.push(i);
    stack.print();
    cout << stack.pop() << endl;
    cout << stack.pop() << endl;
    cout << stack.pop() << endl;
    cout << stack.peek() << endl;

    return 0;
}