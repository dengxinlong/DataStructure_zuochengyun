#include <iostream>
#include <array>

using namespace std;

//固定大小实现队列
template<class T>
class Queue
{
public:
    Queue(int size)
    : _size(size)
    , _first(0)
    , _last(0)
    , _curSize(0)
    , _nums(new T[_size]{0})
    {}

    void enqueue(T value)
    {
        if (isFull()) {
            return;
        }
        _nums[_last] = value;
        _last = _last == _size - 1 ? 0 : _last + 1;
        _curSize++;
    }

    T dequque(void)
    {
        if (!isEmpty()) {
            int temp = _first;
            _first = _first == _size - 1 ? 0 : _first + 1;
            _curSize--;
            return _nums[temp];
        }
    }

    T peek(void)
    {
        if (!isEmpty()) {
            return _nums[_first];
        }
    }

    bool isEmpty(void) { return _curSize == 0; }
    bool isFull(void) { return _curSize == _size; }

private:
    int _size;
    int _first;
    int _last;
    int _curSize;
    T * _nums;
};

int main(void)
{
    Queue<int> queue(10);
    for (int i = 0; i < 10; i++) {
        queue.enqueue(i);
    }
    cout << queue.dequque() << endl;
    cout << queue.dequque() << endl;
    cout << queue.dequque() << endl;
    cout << queue.peek() << endl;
    cout << queue.dequque() << endl;
    return 0;
}