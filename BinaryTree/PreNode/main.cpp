#include "Node.h"
#include "printBinaryTree.h"

#include <iostream>

using namespace std;

//找到一个结点的前驱结点(中序遍历)
class PreNode
{
public:
    static Node * preNode(Node * node)
    {
        if (!node) return nullptr;
        if (node->leftchild) {
            return getRightMost(node->leftchild);
        } else {
            Node * parent = node->parent;
            while (parent && parent->rightchild != node) {
                node = parent;
                parent = node->parent;
            }
            return parent;
        }
    }
private:
    static Node * getRightMost(Node * node)
    {
        if (!node) return nullptr;
        while (node->rightchild) {
            node = node->rightchild;
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
    Node * node = PreNode::preNode(root->rightchild->leftchild);
    cout << node->val << endl;

    bool down = true;
    cout << (down ? "true" : "false") << endl;
    return 0;
}