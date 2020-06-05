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

class PreOrder
{
public:
    static void printPreOrder(Node * root)
    {
        if (!root) return;
        stack<Node *> treeStack;
        treeStack.push(root);
        while (!treeStack.empty()) {
            Node * ptr = treeStack.top();
            treeStack.pop();
            cout << ptr->val << " ";
            if (!ptr->rightchild) {
                treeStack.push(ptr->rightchild);
            }
            if (!ptr->leftchild) {
                treeStack.push(ptr->leftchild);
            }
        }
    }
};

int main(void)
{
    Node * root = new Node(1);
    Node * leftNode = new Node(2);
    root->leftchild = leftNode;
    Node * rightNode = new Node(3);
    root->rightchild = rightNode;

    return 0;
}