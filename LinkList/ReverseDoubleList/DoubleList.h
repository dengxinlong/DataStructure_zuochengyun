#ifndef __DOUBLElIST__
#define __DOUBLElIST__

#include <vector>

struct ListNode
{
    ListNode(int num)
    : val(num)
    , next(nullptr)
    , last(nullptr)
    { }

    int val;
    ListNode * next;
    ListNode * last;
};

bool createList(ListNode * & head, ListNode * & tail, const std::vector<int> & nums);

void printList(ListNode * head, ListNode * tail);








#endif