#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct Node
{
    Node(int x)
    : val(x)
    , leftchild(nullptr)
    , rightchild(nullptr)
    {}

    int val;
    Node * leftchild;
    Node * rightchild;
};

//后序遍历为左右根，前序遍历根左右，那么前序遍历的非递归可以改写为根右左，将根右左产生的序列依次压入另一个栈stack中，依次输出stack中的数据就是后序遍历
class PreOrder
{
public:
    static void printPreOrder(Node * root)
    {
        if (!root) return;
        stack<Node *> treeStack;
        stack<Node *> helpStack;
        treeStack.push(root);
        while (!treeStack.empty()) {
            Node * ptr = treeStack.top();
            helpStack.push(ptr);
            treeStack.pop();
            if (!ptr->leftchild) {
                treeStack.push(ptr->leftchild);
            }
            if (!ptr->rightchild) {
                treeStack.push(ptr->rightchild);
            }
        }

        while (!helpStack.empty()) {
            cout << helpStack.top()->val << " ";
            helpStack.pop();
        }
    }
};