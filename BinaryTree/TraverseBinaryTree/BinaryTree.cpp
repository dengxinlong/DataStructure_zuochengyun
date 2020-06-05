#include "BinaryTree.h"

#include <iostream>
#include <vector>

using namespace std;

//未完成
bool createBinaryTree(Node * & root, const std::vector<int> & nums)
{
    if (!nums.size()) return false;
    root = new Node(nums[0]);
    Node * ptr = root;
    for (int i = 1; i < nums.size(); i++) {
        Node * newNode = new Node(nums[i]);
        ptr->
    }
}

bool createNode(Node * & root, int val)
{

}