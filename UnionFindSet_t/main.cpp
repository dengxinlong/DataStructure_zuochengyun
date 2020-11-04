/*
 * 说明：并查集
 *       isSameSet(A, B): 查找元素A和元素B是否属于同一个集合
 *       union(A, B): 将A元素所在的集合和B元素所在的集合合并
 */

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <stack>
#include <vector>

using namespace std;

template<class T>
class UnionFindSet
{
public:
    UnionFindSet(const vector<T> & nums)
    {
        for (auto elem : nums) {
            _fatherMap[elem] = elem;
            _sizeMap[elem] = 1;
        }
    }

    bool
    isSameSet(T item1, T item2)
    {
        return findFather(item1) == findFather(item2);
    }

    void
    merge(T item1, T item2)
    {
        T head1 = _fatherMap[item1];
        T head2 = _fatherMap[item2];
        if (head1 != head2) {
            int size1 = _sizeMap[item1];
            int size2 = _sizeMap[item2];
            if (size1 <= size2) {
                _fatherMap[head1] = head2;
                _sizeMap[head2] = size1 + size2;
            } else {
                _fatherMap[head2] = head1;
                _sizeMap[head1] = size1 + size2;
            }
        }
    }

private:
    // 递归版本
    T
    findFather(T item)
    {
        T father = _fatherMap[item];
        if (father != item) {
            father = findFather(father);
        }
        _fatherMap[item] = father;
        return father;
    }

    // 迭代版本
    T findFather_t(T item)
    {
        stack<T> helpStack;
        T cur = item;
        T father = _fatherMap[cur];
        while (cur != father) {
            helpStack.push_back(cur);
            cur = father;
            father = _fatherMap[cur];
        }
        while (!helpStack.empty()) {
            T item = helpStack.top();
            helpStack.pop();
            _fatherMap[item] = father;
        }
    }

private:
    unordered_map<T, T> _fatherMap;
    unordered_map<T, int> _sizeMap;
};

int
main(void)
{
    vector<int> nums{1, 2, 3, 4, 5, 6, 7};
    UnionFindSet<int> unionFindSet(nums);

    cout << unionFindSet.isSameSet(1, 2) << endl;
    unionFindSet.merge(1, 2);
    cout << unionFindSet.isSameSet(1, 2) << endl;
    cout << unionFindSet.isSameSet(2, 4) << endl;


    return 0;
}