#include "Node.h"
#include "printBinaryTree.h"

#include <iostream>
#include <string>
#include <vector>
#include <stack>

//判断一颗二叉树是否是二叉搜索树
//由二叉搜索树的性质可以得，对二叉搜索树进行中序遍历，其为升序序列
class JudgeBST
{
public:
    static bool isBST(Node * root) {
        if (!root) return true;
        std::stack<Node *> helpStack;
        // helpStack.push(root);
        Node * pre = nullptr;
        while (!helpStack.empty() || root) {
            if (root) {
                helpStack.push(root);
                root = root->leftchild;
            } else {
                Node * ptr = helpStack.top();
                helpStack.pop();
                if (pre && pre->val > ptr->val) return false;
                pre = ptr;
                root = ptr->rightchild;
            }
        }
        return true;
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

    bool isBalanced = JudgeBST::isBST(root);
    cout << isBalanced << endl;

    std::cout << "====================================" << endl;

    root = new Node(1);
    PrintBinaryTree::printTree(root);

    isBalanced = JudgeBST::isBST(root);
    cout << isBalanced << endl;

    std::cout << "====================================" << endl;

    root = new Node(2);
    root->leftchild = new Node(1);
    root->rightchild = new Node(3);
    // root->leftchild->leftchild = new Node(-1);
    // root->leftchild->leftchild->rightchild = new Node(1);
    PrintBinaryTree::printTree(root);

    isBalanced = JudgeBST::isBST(root);
    cout << isBalanced << endl;

    std::cout << "====================================" << endl;

    root = new Node(100);
    root->leftchild = new Node(21);
    root->leftchild->leftchild = new Node(37);
    root->rightchild = new Node(-42);
    root->rightchild->leftchild = new Node(0);
    root->rightchild->rightchild = new Node(666);
    PrintBinaryTree::printTree(root);

    isBalanced = JudgeBST::isBST(root);
    cout << isBalanced << endl;

    std::cout << "====================================" << endl;
}