#ifndef __NODE__
#define __NODE__

struct Node
{
    Node(int x)
    : val(x)
    , leftchild(nullptr)
    , rightchild(nullptr)
    , parent(nullptr)
    {}

    int val;
    Node * leftchild;
    Node * rightchild;
    Node * parent;
};



#endif