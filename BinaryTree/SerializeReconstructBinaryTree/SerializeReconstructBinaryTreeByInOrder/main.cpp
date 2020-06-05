#include "Node.h"
#include "printBinaryTree.h"

#include <iostream>
#include <string>
#include <vector>
#include <queue>

//中序序列化二叉树
//二叉树的序列化就是二叉树的持久化存储，也就是将一颗二叉树序列化后，从磁盘中再次根据序列化后的结果重建该二叉树
class SerializeReconstructBinaryTree
{
public:
    static std::string serializeByInOrder(Node * root) // 中序序列化二叉树
    {
        if (!root) return std::string("#_");
        std::string ret = serializeByInOrder(root->leftchild);
        ret += std::to_string(root->val) + std::string("_");
        ret += serializeByInOrder(root->rightchild);
        return ret;
    }

    static Node * reconByInOrderString(std::string preStr) // 反序中序序列化，通过中序序列化的结果重新构建二叉树
    {
        std::queue<std::string> valQue;
        std::string temp;
        for (auto elem : preStr) {
            if (elem != '_') {
                temp += elem;
            } else {
                valQue.push(temp);
                temp = "";
            }
        }
        return reconInOrder(valQue);
    }

private:
    static Node * reconInOrder(std::queue<std::string> & valQue)
    {
        
    }
};

int main(void)
{
    Node * root = nullptr;
	PrintBinaryTree::printTree(root);

    std::string pre = SerializeReconstructBinaryTree::serializeByPre(root);
    cout << "serialize tree by pre-order: " << pre << endl;
    root = SerializeReconstructBinaryTree::reconByPreString(pre);
    cout << "reconstruct tree by pre-order, " << endl;
    PrintBinaryTree::printTree(root);

    std::cout << "====================================" << endl;

    root = new Node(1);
    PrintBinaryTree::printTree(root);

    pre = SerializeReconstructBinaryTree::serializeByPre(root);
    std::cout << "serialize tree by pre-order: " << pre << endl;
    root = SerializeReconstructBinaryTree::reconByPreString(pre);
    std::cout << "reconstruct tree by pre-order, " << endl;
    PrintBinaryTree::printTree(root);

    std::cout << "====================================" << endl;

    root = new Node(1);
    root->leftchild = new Node(2);
    root->rightchild = new Node(3);
    root->leftchild->leftchild = new Node(4);
    root->rightchild->rightchild = new Node(5);
    PrintBinaryTree::printTree(root);

    pre = SerializeReconstructBinaryTree::serializeByPre(root);
    std::cout << "serialize tree by pre-order: " << pre << endl;
    root = SerializeReconstructBinaryTree::reconByPreString(pre);
    std::cout << "reconstruct tree by pre-order, " << endl;
    PrintBinaryTree::printTree(root);

    std::cout << "====================================" << endl;

    root = new Node(100);
    root->leftchild = new Node(21);
    root->leftchild->leftchild = new Node(37);
    root->rightchild = new Node(-42);
    root->rightchild->leftchild = new Node(0);
    root->rightchild->rightchild = new Node(666);
    PrintBinaryTree::printTree(root);

    pre = SerializeReconstructBinaryTree::serializeByPre(root);
    std:: cout << "serialize tree by pre-order: " << pre << endl;
    root = SerializeReconstructBinaryTree::reconByPreString(pre);
    std::cout << "reconstruct tree by pre-order, " << endl;
    PrintBinaryTree::printTree(root);

    std::cout << "====================================" << endl;
}