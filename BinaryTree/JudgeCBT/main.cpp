#include "Node.h"
#include "printBinaryTree.h"

#include <iostream>
#include <string>
#include <vector>
#include <queue>

//判断一颗二叉树是否是完全二叉树
/*
 * 思路：要判断一个二叉树是否是完全二叉树，完全二叉树是一种结构，和二叉树里面的值没有任何关系
 *      所以必须从结构入手，层次遍历该二叉树，如果一个结点其有右孩子，但是没有左孩子，则不是完全二叉树
 *      如果在遍历的过程中，某个结点有左孩子，但是没有右孩子，或者该结点左右孩子都没有，则在后续的遍历过程中
 *      后面的所有结点都必须没有左右孩子
 */
class JudgeCBT
{
public:
    static bool isCBT(Node * root) {
        if (!root) return true;
        std::queue<Node *> helpQue;
        helpQue.push(root);
        bool leaf = false;
        while (!helpQue.empty()) {
            Node * ptr = helpQue.front();
            helpQue.pop();
            if (!ptr->leftchild && ptr->rightchild
                || (leaf && (ptr->leftchild || ptr->rightchild))) {
                    return false;
            }
            if (ptr->leftchild) helpQue.push(ptr->leftchild);
            if (ptr->rightchild) {
                helpQue.push(ptr->rightchild);
            } else {
                leaf = true;
            }
        }
        return true;
    }
};

int main(void)
{
    Node * root = nullptr;
	PrintBinaryTree::printTree(root);

    bool isBalanced = JudgeCBT::isCBT(root);
    cout << isBalanced << endl;

    std::cout << "====================================" << endl;

    root = new Node(1);
    PrintBinaryTree::printTree(root);

    isBalanced = JudgeCBT::isCBT(root);
    cout << isBalanced << endl;

    std::cout << "====================================" << endl;

    root = new Node(3);
    root->leftchild = new Node(2);
    root->rightchild = new Node(5);
    root->leftchild->leftchild = new Node(-1);
    PrintBinaryTree::printTree(root);

    isBalanced = JudgeCBT::isCBT(root);
    cout << isBalanced << endl;

    std::cout << "====================================" << endl;

    root = new Node(100);
    root->leftchild = new Node(21);
    root->leftchild->leftchild = new Node(37);
    root->rightchild = new Node(-42);
    root->rightchild->leftchild = new Node(0);
    root->rightchild->rightchild = new Node(666);
    PrintBinaryTree::printTree(root);

    isBalanced = JudgeCBT::isCBT(root);
    cout << isBalanced << endl;

    std::cout << "====================================" << endl;
}