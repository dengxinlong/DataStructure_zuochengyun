/*
 * 说明：本代码实现随机池，实现insert，delete和getRandom方法
 *      getRandom方法在O(1)时间内返回RandomPool中的一个元素
 */

#include <time.h>
#include <stdlib.h>
#include <unistd.h>

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

template<class T>
class RandomPool
{
public:
    RandomPool()
    : _size(0)
    {}

    void
    insert(T str)
    {
        if (_keyIndexMap.find(str) != _keyIndexMap.end()) return;
        _keyIndexMap[str] = _size;
        _indexKeyMap[_size++] = str;
    }

    void
    remove(T str)
    {
        if (!_size) return;
        int lastIndex = --_size;
        T lastKey = _indexKeyMap[lastIndex];
        int index = _keyIndexMap[str];
        _indexKeyMap[index] = lastKey;
        _keyIndexMap[lastKey] = index;
        _keyIndexMap.erase(str);
        _indexKeyMap.erase(lastIndex);
    }

    T
    getRandom(void)
    {
        if (_size) {
            srand(time(NULL));
            int index = rand() % 10 / 10.0 * _size;
            return _indexKeyMap[index];
        }
    }

private:
    unordered_map<T, int> _keyIndexMap;
    unordered_map<int, T> _indexKeyMap;
    int _size;
};

int
main(void)
{
    RandomPool<string> randomPool;
    randomPool.insert("hello");
    randomPool.insert("world");
    randomPool.insert("good");
    for (int i = 0; i < 5; i++) {
        // sleep(1);
        cout << randomPool.getRandom() << endl;
    }
    randomPool.remove("hello");
    for (int i = 0; i < 5; i++) {
        sleep(1);
        cout << randomPool.getRandom() << endl;
    }
    randomPool.insert("how");
    randomPool.insert("are");
    for (int i = 0; i < 5; i++) {
        sleep(1);
        cout << randomPool.getRandom() << endl;
    }
    return 0;
}