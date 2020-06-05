#include "DoubleList.h"

#include <iostream>
#include <vector>

using namespace std;

//反转双向链表，因为双向链表是双向的，head和tail交换就可以了，但这里还是实际操作一下
class ReverseLinkList
{
public:
    static void reverseLinkList(ListNode * & head, ListNode * & tail)
    {
        if (!head || !head->next) return;
        ListNode * ptr = head->next;
        head->next = nullptr;
        tail = head;
        ListNode * right;
        while (ptr) {
            right = ptr->next;
            ptr->next = head;
            head->last = ptr;
            head = ptr;
            ptr = right;
        }
        head->last = nullptr;
    }
};

int main(void)
{
    vector<int> nums{1, 2, 3, 4, 5, 6};
    ListNode * head = nullptr, * tail = nullptr;
    createList(head, tail, nums);
    printList(head, tail);
    ReverseLinkList::reverseLinkList(head, tail);
    printList(head, tail);
    return 0;
}