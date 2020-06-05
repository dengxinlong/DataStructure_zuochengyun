#include "Node.h"
#include "printBinaryTree.h"

#include <iostream>
#include <string>
#include <vector>
#include <stack>

//求出一个完全二叉树的结点个数
//两种解法：遍历整颗二叉树，求出结点个数；利用完全二叉树的结构，根据高度求出结点个数
/*
 * 思路：
 *      这里从它的高度入手，首先求得该树的总高度，判断右子树的高度是否达到最后一层，
 *      如果到达最后一层，则表示其左子树是满的，则左子树的结点个数为2 ^ (high - 1) - 1，右子树也是一颗完全二叉树，采用同样的方式递归
 *      如果没有达到最后一层，则表明右子树为满二叉树(高度比整颗二叉树少2)，左子树同样是一颗完全二叉树，递归
 */
class CompleteTreeNodeNumber
{
public:
    static int nodeNumber(Node * root) {
        if (!root) return 0;
        return nodeNumber(root, 1, mostLeftLevel(root, 1));
    }

private:
    static int nodeNumber(Node * root, int level, int high)
    {
        if (mostLeftLevel(root->rightchild, level + 1) == high) {
            return ((1 << (high - level)) + nodeNumber(root->rightchild, level + 1, high));
        } else {
            return ((1 << (high - level - 1)) + nodeNumber(root->leftchild, level + 1, high));
        }
    }

    static int mostLeftLevel(Node * root, int level)
    {
        while (root) {
            level++;
            root = root->leftchild;
        }
        return level - 1;
    }
};

//递归判断
class JudgeBSTRecursive
{
public:
    static bool isBST(Node * root)
    {
        Node * pre = nullptr;
        return isBST(root, pre);
    }

private:
    static bool isBST(Node * root, Node * & pre) {
        if (!root) return true;
        bool leftRet = isBST(root->leftchild, pre);
        if (pre && pre->val > root->val) return false;
        pre = root;
        bool rightRet = isBST(root->rightchild, pre);
        return leftRet && rightRet;
    }
};

int main(void)
{
    Node * root = nullptr;
	PrintBinaryTree::printTree(root);

    bool isBalanced = CompleteTreeNodeNumber::nodeNumber(root);
    cout << isBalanced << endl;

    std::cout << "====================================" << endl;

    root = new Node(1);
    PrintBinaryTree::printTree(root);

    isBalanced = CompleteTreeNodeNumber::nodeNumber(root);
    cout << isBalanced << endl;

    std::cout << "====================================" << endl;

    root = new Node(2);
    root->leftchild = new Node(1);
    root->rightchild = new Node(3);
    // root->leftchild->leftchild = new Node(-1);
    // root->leftchild->leftchild->rightchild = new Node(1);
    PrintBinaryTree::printTree(root);

    isBalanced = CompleteTreeNodeNumber::nodeNumber(root);
    cout << isBalanced << endl;

    std::cout << "====================================" << endl;

    root = new Node(100);
    root->leftchild = new Node(21);
    root->leftchild->leftchild = new Node(37);
    root->rightchild = new Node(-42);
    root->rightchild->leftchild = new Node(0);
    root->rightchild->rightchild = new Node(666);
    PrintBinaryTree::printTree(root);

    isBalanced = CompleteTreeNodeNumber::nodeNumber(root);
    cout << isBalanced << endl;

    std::cout << "====================================" << endl;
}