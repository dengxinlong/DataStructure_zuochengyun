#include "DoubleList.h"

#include <iostream>

using namespace std;

//构建一个双向链表
bool createList(ListNode * & head, ListNode * & tail, const std::vector<int> & nums)
{
    if (!nums.size()) return false;
    ListNode * ptr =new ListNode(nums[0]);
    tail = head = ptr;
    for (int i = 1; i < nums.size(); i++) {
        ListNode * ptr = new ListNode(nums[i]);
        ptr->next = head;
        head->last = ptr;
        head = ptr;
    }
}

void printList(ListNode * head, ListNode * tail)
{
    if (!head || !tail) return;
    //正向打印
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
    while (tail) {
        cout << tail->val << " ";
        tail = tail->last;
    }
    cout << endl;
}