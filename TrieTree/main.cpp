#include <iostream>
#include <vector>
#include <string>

// 前缀数的实现
//实现的功能，在前缀树中，以str字符串为前缀的字符串个数是多少；str字符串在前缀树中出现的次数；
class TrieTree
{
public:
    void insertElem(const std::string & str)
    {
        if (!str.size()) return;
        Node * node = &_root;
        for (auto elem : str) {
            int index = elem - 'a';
            if (!(node->_next[index])) {
                node->_next[index] = new Node;
            }
            node = node->_next[index];
            node->_path++;
        }
        node->_end++;
    }

    void deleteElem(const std::string & str)
    {
        if (search(str)) { // 首先该字符串必须存在于前缀树中
            // std::vector<Node *> helpDel;
            Node * node = &_root;
            for (auto elem : str) {
                int index = elem - 'a';
                if (!(--node->_next[index]->_path)) { // 这段代码有问题，删除结点后，后面的结点将不能访问了，存在断链情况
                    node->_next[index] = nullptr; //存在内存泄漏
                    return;
                }
                node = node->_next[index];
            }
            node->_end--;
        }
    }

    int search(const std::string & str)
    {
        if (!str.size()) return 0;
        Node * node = &_root;
        for (auto elem : str) {
            int index = elem - 'a';
            if (!(node->_next[index])) return 0;
            node = node->_next[index];
        }
        return node->_end;
    }

    int prefixNumber(const std::string & str)
    {
        int ret = 0;
        if (!str.size()) return 0;
        Node * node = &_root;
        for (auto elem : str) {
            int index = elem - 'a';
            if (!(node->_next[index])) return 0;
            node = node->_next[index];
        }
        return node->_path;
    }

private:
    class Node
    {
    public:
        Node()
        : _path(0)
        , _end(0)
        , _next(26, nullptr)
        {}

    public:
        int _path;
        int _end;
        std::vector<Node *> _next;
    };

private:
    Node _root;
};


int main(void)
{
    TrieTree trieTree;
    // std::cout << trieTree.search("ghost") << std::endl;
    trieTree.insertElem("ghost");
    std::cout << trieTree.search("ghost") << std::endl;
    trieTree.deleteElem("ghost");
    std::cout << trieTree.search("ghost") << std::endl;
    trieTree.insertElem("ghost");
    trieTree.insertElem("ghost");
    trieTree.deleteElem("ghost");
    std::cout << trieTree.search("ghost") << std::endl;
    trieTree.deleteElem("ghost");
    std::cout << trieTree.search("ghost") << std::endl;
    trieTree.insertElem("ghosta");
    trieTree.insertElem("ghostac");
    trieTree.insertElem("ghostab");
    trieTree.insertElem("ghostad");
    trieTree.deleteElem("ghosta");
    std::cout << "----------------\n";
    std::cout << trieTree.search("ghost") << std::endl;
    std::cout << trieTree.prefixNumber("ghost") << std::endl;

    return 0;
}