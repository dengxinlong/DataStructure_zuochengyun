/*
 * 题目：获得一个流中的中位数，流表示持续有数据的输入，获取当前输入的所有的一个中位数
 */

#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

class GetStreamMiddle
{
public:
    void
    addNum(int num)
    {
        if (_maxHeap.empty()) {
            _maxHeap.push(num);
            return;
        }

        if (_maxHeap.top() >= num) {
            _maxHeap.push(num);
        } else {
            if (_minHeap.empty()) {
                _minHeap.push(num);
                return;
            }
            if (_minHeap.top() > num) {
                _maxHeap.push(num);
            } else {
                _minHeap.push(num);
            }
        }
        modifyTwoHeap();
    }

    void
    modifyTwoHeap()
    {
        if (_maxHeap.size() - _minHeap.size() == 2) {
            _minHeap.push(_maxHeap.top());
            _maxHeap.pop();
        } else if (_minHeap.size() - _maxHeap.size() == 2) {
            _maxHeap.push(_minHeap.top());
            _minHeap.pop();
        }
    }

    int
    getStreamMiddle()
    {
        int maxHeapSize = _maxHeap.size();
        int minHeapSize = _minHeap.size();
        if (maxHeapSize + minHeapSize == 0) return 0;
        int maxHeapHead = _maxHeap.top();
        int minHeapHead = _minHeap.top();
        if (((maxHeapSize + minHeapSize) & 1) == 0) {
            return (maxHeapHead + minHeapHead) / 2;
        }
        return maxHeapSize > minHeapSize ? maxHeapHead : minHeapHead;
    }

private:
    priority_queue<int, vector<int>, less<int>> _maxHeap;
    priority_queue<int, vector<int>, greater<int>> _minHeap;
};