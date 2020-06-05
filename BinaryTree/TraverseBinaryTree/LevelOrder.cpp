#include "Node.h"
#include "printBinaryTree.h"

#include <iostream>
#include <queue>

using namespace std;

class LevelOrder
{
public:
    static void printLevelOrder(Node * root)
    {
        if (!root) return;
        std::queue<Node *> helpQue;
        helpQue.push(root);
        while (!helpQue.empty()) {
            Node * ptr = helpQue.front();
            helpQue.pop();
            std::cout << ptr->val << " ";
            if (ptr->leftchild) {
                helpQue.push(ptr->leftchild);
            }
            if (ptr->rightchild) {
                helpQue.push(ptr->rightchild);
            }
        }
        std::cout << std::endl;
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
    LevelOrder::printLevelOrder(root);

    return 0;
}