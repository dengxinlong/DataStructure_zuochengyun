#include <stdlib.h>
#include <time.h>

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>


//设置一个随机池结构，在O(1)时间内存元素，删除元素，同时，随机返回该结构里面的元素
template<class T>
class RandomPool
{
public:
    RandomPool(int size = 0)
    : _size(size)
    {
        srand(time(NULL));
    }

    void insertElem(T key)
    {
        _dataMap[key] = _size;
        _indexMap[_size++] = key;
    }

    void deleteElem(T key)
    {
        auto iter = _dataMap.find(key);
        if (iter != _dataMap.end()) {
            int lastIndex = --_size;
            T lastKey = _indexMap[lastIndex];
            _dataMap[lastKey] = iter->second;
            _indexMap[iter->second] = lastKey;
            _dataMap.erase(iter->first);
            _indexMap.erase(lastIndex);
        }
    }

    T getRandom(void)
    {
        if (_size) {
            int index = rand() % 10 / 10.0 * _size; //生成0 ~ size - 1之间的随机数
            std::cout << "index: " << index << std::endl;
            return _indexMap[index];
        }
    }

private:
    std::unordered_map<T, int> _dataMap;
    std::unordered_map<int, T> _indexMap;
    int _size;
};

int main(void)
{
    RandomPool<std::string> randomPool;
    randomPool.insertElem("good");
    randomPool.insertElem("ghost");
    randomPool.insertElem("god");
    randomPool.insertElem("hello");

    std::cout << randomPool.getRandom() << std::endl;
    std::cout << randomPool.getRandom() << std::endl;
    std::cout << randomPool.getRandom() << std::endl;

    randomPool.deleteElem("good");
    std::cout << randomPool.getRandom() << std::endl;
    std::cout << randomPool.getRandom() << std::endl;
    std::cout << randomPool.getRandom() << std::endl;

    return 0;
}