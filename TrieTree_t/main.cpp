/*
 * 说明：前缀树的实现，在每个结点中添加了一些其他的元素，便于利用前缀树来查找一些其他的消息
 */
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class TrieTree
{
public:
    TrieTree()
    : _root(new Node)
    {}

    void
    insertElem(string str)
    {
        if (!str.size()) return;
        Node * ptr = _root;
        for (auto elem : str) {
            int index = elem - 'a';
            if (ptr->_next[index] == nullptr) {
                ptr->_next[index] = new Node;
            }
            ptr = ptr->_next[index];
            ptr->_path++;
        }
        ptr->_end++;
    }

    // 需要递归删除
    void
    deleteElem(string str)
    {
        if (!searchElem(str)) return; // 如果str不存在于前缀树中，则直接返回
        if (!str.size()) return;
        vector<Node *> helper;
        helper.push_back(_root);
        Node * ptr = _root;
        for (auto elem : str) {
            int index = elem - 'a';
            helper.push_back(ptr->_next[index]);
            ptr->_next[index]->_path--;
            ptr = ptr->_next[index];
        }
        // 将删除元素后，前缀树中path为0的结点删除，通过将可能需要删除的结点放入数组当中，会丢失index信息
        for (int i = 1; i < helper.size(); ++i) {
            if (helper[i]->_path == 0) {
                helper[i - 1]->_next[]
            }
        }
    }

    // 查找在前缀树中有有多少个str字符串之前插入过
    int
    searchElem(string str)
    {
        if (!str.size()) return;
        Node * ptr = _root;
        for (auto elem : str) {
            int index = elem - 'a';
            if (ptr->_next[index] == nullptr) {
                return 0;
            }
            ptr = ptr->_next[index];
        }
        return ptr->_end;
    }

    int
    prefixNum(string str)
    {
        if (!str.size()) return;
        Node * ptr = _root;
        for (auto elem : str) {
            int index = elem - 'a';
            if (ptr->_next[index] == nullptr) {
                return 0;
            }
            ptr = ptr->_next[index];
        }
        return ptr->_path;
    }

private:
    // 构造前缀树中结点信息
    class Node
    {
    public:
        Node()
        : _path(0)
        , _end(0)
        , _next(26, nullptr)
        {}

    private:
        int _path;
        int _end;
        vector<Node *> _next;
    };

    Node * _root;
};

int
main(void)
{

}
