#include "linklist.h"

#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    ListNode *phead = new ListNode(0); //作为新链表的头结点
    ListNode *ptr = phead;
    while (l1 && l2)
    {
        if (l1->val < l2->val)
        {
            ptr->next = l1;
            l1 = l1->next;
        }
        else
        {
            ptr->next = l2;
            l2 = l2->next;
        }
        ptr = ptr->next;
    }
    if (l1)
        ptr->next = l1;
    else
        ptr->next = l2;

    return phead->next;
}