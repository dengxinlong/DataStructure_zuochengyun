#include "Node.h"
#include "printBinaryTree.h"

#include <iostream>
#include <string>
#include <vector>
#include <queue>

//层次序列化二叉树
//二叉树的序列化就是二叉树的持久化存储，也就是将一颗二叉树序列化后，从磁盘中再次根据序列化后的结果重建该二叉树
class SerializeReconstructBinaryTree
{
public:
    static std::string serializeBylevel(Node * root) // 层序序列化二叉树
    {
        if (!root) return std::string("#_");
        std::queue<Node *> helpQue;
        std::string ret;
        helpQue.push(root);
        ret += std::to_string(root->val) + std::string("_");
        while (!helpQue.empty()) {
            Node * ptr = helpQue.front();
            helpQue.pop();
            if (ptr->leftchild) {
                ret += std::to_string(ptr->leftchild->val) + std::string("_");
                helpQue.push(ptr->leftchild);
            } else {
                ret += std::string("#_");
            }
            if (ptr->rightchild) {
                ret += std::to_string(ptr->rightchild->val) + std::string("_");
                helpQue.push(ptr->rightchild);
            } else {
                ret += std::string("#_");
            }
        }
        return ret;
    }

    static Node * reconLevelOrder(std::string levelStr) // 由中序序列化的结果构建二叉树
    {
        std::queue<Node *> helpQue;
        std::string temp;
        std::vector<std::string> vals;
        for (auto elem : levelStr) {
            if (elem != '_') {
                temp.push_back(elem);
            } else {
                vals.push_back(temp);
                temp = "";
            }
        }
        int index = 0;
        Node * root = generateNodeByLevel(vals[index++]);
        if (root) {
            helpQue.push(root);
        }
        while (!helpQue.empty() && index < vals.size()) { //后面的条件其实不需要，但是从严谨性考虑，还是加上了
            Node * ptr = helpQue.front();
            helpQue.pop();
            ptr->leftchild = generateNodeByLevel(vals[index++]);
            if (ptr->leftchild) helpQue.push(ptr->leftchild);
            ptr->rightchild = generateNodeByLevel(vals[index++]);
            if (ptr->rightchild) helpQue.push(ptr->rightchild);
        }
        return root;
    }

private:
    static Node * generateNodeByLevel(std::string str)
    {
        if (str == "#") return nullptr;
        return new Node(std::stoi(str));
    }
};

int main(void)
{
    Node * root = nullptr;
	PrintBinaryTree::printTree(root);

    std::string level = SerializeReconstructBinaryTree::serializeBylevel(root);
    std::cout << "serialize tree by level: " << level << std::endl;
    root = SerializeReconstructBinaryTree::reconLevelOrder(level);
    std::cout << "reconstruct tree by level, " << std::endl;
    PrintBinaryTree::printTree(root);

    std::cout << "====================================" << endl;

    root = new Node(1);
    PrintBinaryTree::printTree(root);

    level = SerializeReconstructBinaryTree::serializeBylevel(root);
    std::cout << "serialize tree by level: " << level << std::endl;
    root = SerializeReconstructBinaryTree::reconLevelOrder(level);
    std::cout << "reconstruct tree by level, " << std::endl;
    PrintBinaryTree::printTree(root);

    std::cout << "====================================" << endl;

    root = new Node(1);
    root->leftchild = new Node(2);
    root->rightchild = new Node(3);
    root->leftchild->leftchild = new Node(4);
    root->rightchild->rightchild = new Node(5);
    PrintBinaryTree::printTree(root);

    level = SerializeReconstructBinaryTree::serializeBylevel(root);
    std::cout << "serialize tree by level: " << level << std::endl;
    root = SerializeReconstructBinaryTree::reconLevelOrder(level);
    std::cout << "reconstruct tree by level, " << std::endl;
    PrintBinaryTree::printTree(root);

    std::cout << "====================================" << endl;

    root = new Node(100);
    root->leftchild = new Node(21);
    root->leftchild->leftchild = new Node(37);
    root->rightchild = new Node(-42);
    root->rightchild->leftchild = new Node(0);
    root->rightchild->rightchild = new Node(666);
    PrintBinaryTree::printTree(root);

    level = SerializeReconstructBinaryTree::serializeBylevel(root);
    std::cout << "serialize tree by level: " << level << std::endl;
    root = SerializeReconstructBinaryTree::reconLevelOrder(level);
    std::cout << "reconstruct tree by level, " << std::endl;
    PrintBinaryTree::printTree(root);

    std::cout << "====================================" << endl;
}