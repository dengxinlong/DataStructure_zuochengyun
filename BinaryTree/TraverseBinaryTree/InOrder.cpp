#include "Node.h"
#include "printBinaryTree.h"

#include <iostream>
#include <stack>

using namespace std;

class InOrder
{
public:
    static void printInOrder(Node * root)
    {
        if (!root) return;
        stack<Node *> treeStack;
        while (!treeStack.empty() || root) {
            if (root) {
                treeStack.push(root);
                root = root->leftchild;
            } else {
                Node * ptr = treeStack.top();
                cout << ptr->val << " ";
                treeStack.pop();
                root = ptr->rightchild;
            }
        }
    }
};


int main(void)
{
    Node * root = new Node(1);
    root->leftchild = new Node(2);
    root->rightchild = new Node(3);
    root->leftchild->leftchild = new Node(4);
    root->leftchild->rightchild = new Node(5);
    root->leftchild->leftchild->leftchild = new Node(6);
    root->rightchild->leftchild = new Node(7);
    root->rightchild->rightchild = new Node(8);
    root->rightchild->rightchild->leftchild = new Node(9);
    root->rightchild->rightchild->rightchild = new Node(10);
    PrintBinaryTree::printTree(root);
    InOrder::printInOrder(root);

    return 0;
}