#include "Node.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;



class PrintBinaryTree
{
public:
    static void printTree(Node * head)
    {
        cout << "Binary Tree:\n";
        printInOrder(head, 0, "H", 17);
        cout << endl;
    }

private:
    static void printInOrder(Node * head, int height, string to, int len)
    {
        if (!head) return;
        printInOrder(head->rightchild, height + 1, "v", len);
        string val = to + std::to_string(head->val) + to;
        int lenM = val.size();
        int lenL = (len - lenM) / 2;
        int lenR = len - lenM - lenL;
        val = getSpace(lenL) + val + getSpace(lenR);
        cout << getSpace(height * len) + val << endl;
        printInOrder(head->leftchild, height + 1, "^", len);
    }

    static string getSpace(int num)
    {
        string space = "";
        for (int i = 0; i < num; i++) {
            space.append(" ");
        }
        return space;
    }
};