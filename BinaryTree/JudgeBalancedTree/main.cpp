#include "Node.h"
#include "printBinaryTree.h"

#include <iostream>
#include <string>
#include <vector>
#include <queue>

//判断一颗二叉树是否是平衡树
class JudgeBalancedBinaryTree
{
public:
    static bool isBalancedBinaryTree(Node * root) {
        std::vector<int> rets = isBalanced(root);
        return rets[1];
    }

private:
    static std::vector<int> isBalanced(Node * root)
    {
        if (!root) return std::vector<int>{0, 1};
        std::vector<int> leftRets = isBalanced(root->leftchild);
        std::vector<int> rightRets = isBalanced(root->rightchild);

        int high = leftRets[0] > rightRets[0] ? leftRets[0] + 1 : rightRets[0] + 1;
        int isBalanced = rightRets[1] && leftRets[1] &&  std::abs(leftRets[0] - rightRets[0]) <= 1 ? 1 : 0;
        return std::vector<int>{high, isBalanced};
    }
};

int main(void)
{
    Node * root = nullptr;
	PrintBinaryTree::printTree(root);

    bool isBalanced = JudgeBalancedBinaryTree::isBalancedBinaryTree(root);
    cout << isBalanced << endl;

    std::cout << "====================================" << endl;

    root = new Node(1);
    PrintBinaryTree::printTree(root);

    isBalanced = JudgeBalancedBinaryTree::isBalancedBinaryTree(root);
    cout << isBalanced << endl;

    std::cout << "====================================" << endl;

    root = new Node(1);
    root->leftchild = new Node(2);
    root->rightchild = new Node(3);
    root->leftchild->leftchild = new Node(4);
    root->leftchild->leftchild->rightchild = new Node(5);
    PrintBinaryTree::printTree(root);

    isBalanced = JudgeBalancedBinaryTree::isBalancedBinaryTree(root);
    cout << isBalanced << endl;

    std::cout << "====================================" << endl;

    root = new Node(100);
    root->leftchild = new Node(21);
    root->leftchild->leftchild = new Node(37);
    root->rightchild = new Node(-42);
    root->rightchild->leftchild = new Node(0);
    root->rightchild->rightchild = new Node(666);
    PrintBinaryTree::printTree(root);

    isBalanced = JudgeBalancedBinaryTree::isBalancedBinaryTree(root);
    cout << isBalanced << endl;

    std::cout << "====================================" << endl;
}