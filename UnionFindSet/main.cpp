#include <iostream>
#include <unordered_map>
#include <vector>
#include <stack>

template<class T>
class UnionFindSet
{
public:
    UnionFindSet(const std::vector<T> & vals)
    {
        for (auto elem : vals) {
            _fatherMap[elem] = elem;
            _sizeMap[elem] = 1;
        }
    }

    bool isSameSet(T val1, T val2)
    {
        return findHead(val1) == findHead(val2);
    }

    void unionSet(T val1, T val2)
    {
        T head1 = findHead(val1);
        T head2 = findHead(val2);
        if (head1 != head2) {     // 这两个元素的头结点不一致，则将这两个元素所在的集合合并
            int size1 = _sizeMap[head1];
            int size2 = _sizeMap[head2];
            if (size1 >= size2) {
                _fatherMap[head2] = head1;
                _sizeMap[head1] = size1 + size2;
            } else {
                _fatherMap[head1] = head2;
                _sizeMap[head2] = size1 + size2;
            }
        }
    }

private:
    T findHead(T val) //查找某个结点的头结点，递归书写，将每一层的结点全部指向最终的父结点
    {
        T father = _fatherMap[val];
        if (father != val) {
            father = findHead(father);
        }
        _fatherMap[val] = father;
        return father;
    }

    T findHead_2(T val)
    {
        std::stack<T> helpStack;
        T father = _fatherMap[val];
        while (father != val) {
            helpStack.push(val);
            val = father;
            father = _fatherMap[father];
        }
        while (!helpStack.empty()) {
            _fatherMap[helpStack.top()] = father;
            helpStack.pop();
        }
        return father;
    }

private:
    std::unordered_map<T, T> _fatherMap;
    std::unordered_map<T, int> _sizeMap;
};

int main(void)
{
    std::vector<int> nums{1, 2, 3, 4, 5, 6};
    UnionFindSet<int> unionFindSet(nums);
    std::cout << unionFindSet.isSameSet(1, 3) << std::endl;

    unionFindSet.unionSet(1, 3);
    std::cout << unionFindSet.isSameSet(1, 3) << std::endl;

    return 0;
}