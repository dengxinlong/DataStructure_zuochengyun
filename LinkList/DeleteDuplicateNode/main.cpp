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

class Solution {
public:
    ListNode* removeDuplicateNodes(ListNode* head) {
        if (!head || !head->next) return head;
        for (ListNode * ptr = head; ptr; ptr = ptr->next) {
            std::cout << ptr->val << endl;
            for (ListNode * cur = ptr->next, * pre = ptr; cur;) {
                if (cur->val == ptr->val) {
                    pre->next = cur->next;
                    delete cur;
                    cur = pre->next;
                } else {
                    pre = cur;
                    cur = cur->next;
                }
            }
        }
        return head;
    }
};

int main(void)
{
    ListNode * head = nullptr;
    vector<int> nums{1, 2, 3, 3, 2, 1};
    create_list(&head, nums);
    ReverseLinkList::printLinkList(head);
    ReverseLinkList::reverseLinkList(head);
    ReverseLinkList::printLinkList(head);
    Solution so;
    so.removeDuplicateNodes(head);
    ReverseLinkList::printLinkList(head);

    return 0;
}