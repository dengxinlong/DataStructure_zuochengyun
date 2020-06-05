#include "Node.h"
#include "printBinaryTree.h"

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>

//后序序列化二叉树
//二叉树的序列化就是二叉树的持久化存储，也就是将一颗二叉树序列化后，从磁盘中再次根据序列化后的结果重建该二叉树
class SerializeReconstructBinaryTree
{
public:
    static std::string serializeByPost(Node * root) // 后序序列化二叉树
    {
        if (!root) return std::string("#_");
        std::string ret = serializeByPost(root->leftchild);
        ret += serializeByPost(root->rightchild);
        ret += std::to_string(root->val) + "_";
        return ret;
    }

    static Node * reconByPostString(std::string postStr) // 反序后序序列化，通过后序序列化的结果重新构建二叉树
    {
        std::stack<std::string> valStack;
        std::string temp;
        for (auto elem : postStr) {
            if (elem != '_') {
                temp.push_back(elem);
            } else {
                valStack.push(temp);
                temp = "";
            }
        }
        return reconPostOrder(valStack);
    }

private:
    static Node * reconPostOrder(std::stack<std::string> & valStack)
    {
        std::string val = valStack.top();
        valStack.pop();
        if (val == "#") return nullptr;
        Node * root = new Node(std::stoi(val));
        root->rightchild = reconPostOrder(valStack);
        root->leftchild = reconPostOrder(valStack);
        return root;
    }
};

int main(void)
{
    Node * root = nullptr;
	PrintBinaryTree::printTree(root);

    std::string Post = SerializeReconstructBinaryTree::serializeByPost(root);
    cout << "serialize tree by pre-order: " << Post << endl;
    root = SerializeReconstructBinaryTree::reconByPostString(Post);
    cout << "reconstruct tree by pre-order, " << endl;
    PrintBinaryTree::printTree(root);

    std::cout << "====================================" << endl;

    root = new Node(1);
    PrintBinaryTree::printTree(root);

    Post = SerializeReconstructBinaryTree::serializeByPost(root);
    cout << "serialize tree by pre-order: " << Post << endl;
    root = SerializeReconstructBinaryTree::reconByPostString(Post);
    cout << "reconstruct tree by pre-order, " << endl;
    PrintBinaryTree::printTree(root);

    std::cout << "====================================" << endl;

    root = new Node(1);
    root->leftchild = new Node(2);
    root->rightchild = new Node(3);
    root->leftchild->leftchild = new Node(4);
    root->rightchild->rightchild = new Node(5);
    PrintBinaryTree::printTree(root);

    Post = SerializeReconstructBinaryTree::serializeByPost(root);
    cout << "serialize tree by pre-order: " << Post << endl;
    root = SerializeReconstructBinaryTree::reconByPostString(Post);
    cout << "reconstruct tree by pre-order, " << endl;
    PrintBinaryTree::printTree(root);

    std::cout << "====================================" << endl;

    root = new Node(100);
    root->leftchild = new Node(21);
    root->leftchild->leftchild = new Node(37);
    root->rightchild = new Node(-42);
    root->rightchild->leftchild = new Node(0);
    root->rightchild->rightchild = new Node(666);
    PrintBinaryTree::printTree(root);

    Post = SerializeReconstructBinaryTree::serializeByPost(root);
    cout << "serialize tree by pre-order: " << Post << endl;
    root = SerializeReconstructBinaryTree::reconByPostString(Post);
    cout << "reconstruct tree by pre-order, " << endl;
    PrintBinaryTree::printTree(root);

    std::cout << "====================================" << endl;
}