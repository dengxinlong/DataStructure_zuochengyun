#include "Node.h"
#include "printBinaryTree.h"

#include <iostream>

using namespace std;

//找到一个结点的后继结点(中序遍历)
class SuccessorNode
{
public:
    static Node * successorNode(Node * node)
    {
        if (!node) return nullptr;
        if (node->rightchild) {
            return getLeftMost(node->rightchild);
        } else {
            Node * parent = node->parent;
            while (parent && parent->leftchild != node) {
                node = parent;
                parent = node->parent;
            }
            return parent;
        }
    }
private:
    static Node * getLeftMost(Node * node)
    {
        if (!node) return nullptr;
        while (node->leftchild) {
            node = node->leftchild;
        }
        return node;
    }
};

int main(void)
{
    Node * root = new Node(1);
    root->parent = nullptr;
    root->leftchild = new Node(2);
    root->rightchild = new Node(3);
    root->leftchild->parent = root;
    root->rightchild->parent = root;
    root->leftchild->leftchild = new Node(4);
    root->leftchild->rightchild = new Node(5);
    root->leftchild->leftchild->parent = root->leftchild;
    root->leftchild->rightchild->parent = root->leftchild;
    root->leftchild->leftchild->leftchild = new Node(6);
    root->rightchild->leftchild = new Node(7);
    root->leftchild->leftchild->leftchild->parent = root->leftchild->leftchild;
    root->rightchild->leftchild->parent = root->rightchild;
    root->rightchild->rightchild = new Node(8);
    root->rightchild->rightchild->leftchild = new Node(9);
    root->rightchild->rightchild->rightchild = new Node(10);
    root->rightchild->rightchild->parent = root->rightchild->rightchild;
    root->rightchild->rightchild->leftchild->parent = root->rightchild->rightchild;
    root->rightchild->rightchild->rightchild->parent = root->rightchild->rightchild;

    PrintBinaryTree::printTree(root);
    Node * node = SuccessorNode::successorNode(root->rightchild);
    cout << node->val << endl;
    return 0;
}