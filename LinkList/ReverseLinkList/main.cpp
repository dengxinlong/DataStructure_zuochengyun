#include "List.h"
#include <iostream>

using namespace std;

//将一个单链表反转
class ReverseLinkList
{
public:
    static void reverseLinkList(ListNode * & head)
    {
        if (!head && !head->next) return;
        ListNode * ptr = head->next;
        head->next = nullptr;
        ListNode * right;
        while (ptr) {
            right = ptr->next;
            ptr->next = head;
            head = ptr;
            ptr = right;
        }
    }

    static void printLinkList(ListNode * head)
    {
        if (!head) return;
        while (head) {
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    }
};

int main(void)
{
    ListNode * head = nullptr;
    vector<int> nums{1, 2, 3, 4, 5, 6};
    create_list(&head, nums);
    ReverseLinkList::printLinkList(head);
    ReverseLinkList::reverseLinkList(head);
    ReverseLinkList::printLinkList(head);


    return 0;
}