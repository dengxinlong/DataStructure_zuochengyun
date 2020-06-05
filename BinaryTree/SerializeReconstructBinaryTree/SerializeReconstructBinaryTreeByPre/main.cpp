#include "Node.h"
#include "printBinaryTree.h"

#include <iostream>
#include <string>
#include <vector>
#include <queue>

//先序序列化二叉树
//二叉树的序列化就是二叉树的持久化存储，也就是将一颗二叉树序列化后，从磁盘中再次根据序列化后的结果重建该二叉树
class SerializeReconstructBinaryTree
{
public:
    static std::string serializeByPre(Node * root) // 先序序列化二叉树
    {
        if (!root) return std::string("#_");
        std::string ret = std::to_string(root->val) + "_";
        ret += serializeByPre(root->leftchild);
        ret += serializeByPre(root->rightchild);
        return ret;
    }

    static Node * reconByPreString(std::string preStr) // 反序先序序列化，通过先序序列化的结果重新构建二叉树
    {
        std::queue<std::string> valQue;
        std::string temp;
        for (auto elem : preStr) {
            if (elem != '_') {
                temp.push_back(elem);
            } else {
                valQue.push(temp);
                temp = "";
            }
        }
        return reconPreOrder(valQue);
    }

private:
    static Node * reconPreOrder(std::queue<std::string> & valQue)
    {
        std::string val = valQue.front();
        valQue.pop();
        if (val == "#") return nullptr;
        Node * root = new Node(std::stoi(val));
        root->leftchild = reconPreOrder(valQue);
        root->rightchild = reconPreOrder(valQue);
        return root;
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