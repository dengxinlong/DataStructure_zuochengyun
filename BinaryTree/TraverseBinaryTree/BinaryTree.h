#ifndef __BINARYTREE__
#define __BINARYTREE__

#include <iostream>

struct Node
{
    Node(int x)
    : val(x)
    , leftchild(nullptr)
    , rightchild(nullptr)
    {}

    int val;
    Node * leftchild;
    Node * rightchild;
};

bool createBinaryTree(Node * & root, const std::vector<int> & nums);

bool createNode(Node * & root, int val);

#endif