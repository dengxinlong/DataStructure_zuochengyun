#include "List.h"

#include <iostream>
#include <vector>
#include <unordered_set>

/*
 *问题描述：链表相交问题，找到两个链表相交的第一个结点
 *         两个链表相交，这两个链表可能有环，可能没有环，需要分情况讨论
 *         第一步：先判断两个链表是否有环；
 *         第二步：如果两个链表没有环，则退化为判断普通单链表相交问题，根据两个链表的长度来找到第一个相交的结点
 *         第三步：如果两个链表有环，存在三种拓扑结构
 *                1. 两个有环链表不相交；2. 两个相交的有环链表在结尾处形成环；3. 两个链表连接到一个环中
 */
class FindFirstIntersectionNode
{
public:
    static ListNode * getFirstIntersectionNode(ListNode * head1, ListNode * head2)
    {
        if (!head1 || !head2) return nullptr;
        //先判断两个链表是否有环，得到环结点
        ListNode * loop1 = getLoopNodeHashSet(head1);
        ListNode * loop2 = getLoopNodeHashSet(head2);

        if (!loop1 && !loop2) { // 无环链表相交
            return noLoopIntersectionNode(head1, head2);
        }

        if (loop1 && loop2) {   // 有环链表相交
            return loopIntersectionNode(head1, loop1, head2, loop2);
        }

        //一个有环，一个无环，不可能相交
        return nullptr;
    }

private:
    //两种方法得到环结点
    //第一种：利用hashSet结构，遍历将链表中的结点放入hashSet中，在往后遍历过程中，如果hashSet中有结点，则表示有环，该结点就是环结点，如果遍历到最后都没有，则无环
    //第二种：双指针，slow，faster，slow走一步，faster走两步，如果没有环，则faster最终将遍历结束；
    //       如果有环，则最终会相遇，相遇时，faster重新回到头指针位置，这时候走一步，当再次相交时，相交结点就是环结点
    static ListNode * getLoopNodeHashSet(ListNode * head)
    {
        std::unordered_set<ListNode *> hashSet;
        for (ListNode * ptr = head; ptr; ptr = ptr->next) {
            if (hashSet.count(ptr)) {
                return ptr;
            } else {
                hashSet.insert(ptr);
            }
        }
        return nullptr;
    }

    static ListNode * getLoopNodeTwoIndex(ListNode * head)
    {
        if (!head || !head->next) return nullptr;
        ListNode * slow = head->next;
        ListNode * faster = head->next->next;
        while (slow != faster) {
            if (!faster || !faster->next) return nullptr;
            slow = slow->next;
            faster = faster->next->next;
        }
        faster = head;
        while (slow != faster) {
            faster = faster->next;
            slow = slow->next;
        }
        return slow;
    }

    //找出无环链表的相交结点
    //两种方法：1. 将链表1中的所有结点全部放入hashSet中，遍历链表2，判断hashSet中是否有链表2中的结点，有则表示相交，该结点就是第一个相交结点
    static ListNode * noLoopIntersectionNodeHashSet(ListNode * head1, ListNode * head2)
    {
        std::unordered_set<ListNode *> hashSet;
        for (ListNode * ptr = head1; ptr; ptr = ptr->next) {
            hashSet.insert(ptr);
        }
        for (ListNode * ptr = head2; ptr; ptr = ptr->next) {
            if (hashSet.count(ptr)) return ptr;
        }
        return nullptr;
    }

    static ListNode * noLoopIntersectionNode(ListNode * head1, ListNode * head2)
    {
        ListNode * ptrA = head1;
        ListNode * ptrB = head2;
        while (ptrA != ptrB) {
            if (!ptrA) ptrA = head2;
            else ptrA = ptrA->next;

            if (!ptrB) ptrB = head1;
            else ptrB = ptrB->next;
        }
        return ptrA;

        //或者这样写
        // int len1 = 0, len2 = 0;
        // for (ListNode * ptr = head1; ptr; ptr = ptr->next) {
        //     len1++;
        // }
        // for (ListNode * ptr = head2; ptr; ptr = ptr->next) {
        //     len2++;
        // }
        // ListNode * moreLenNode = len1 > len2 ? head1 : head2;
        // ListNode * lessLenNode = len1 > len2 ? head2 : head1;
        // for (int i = 0; i < std::abs(len1 - len2); i++) {
        //     moreLenNode = moreLenNode->next;
        // }
        // while (moreLenNode != lessLenNode) {
        //     moreLenNode = moreLenNode->next;
        //     lessLenNode = lessLenNode->next;
        // }
        // return lessLenNode;
    }

    //找出两个有环链表的第一个相交结点，没有则返回null
    static ListNode * loopIntersectionNode(ListNode * head1, ListNode * loop1, ListNode * head2, ListNode * loop2)
    {
        if (loop1 == loop2) { // 退化为两个无环链表相交
            ListNode * ptr1 = head1;
            ListNode * ptr2 = head2;
            while (ptr1 != ptr2) {
                if (ptr1 == loop1) ptr1 = head2;
                else ptr1 = ptr1->next;

                if (ptr2 == loop2) ptr2 = head1;
                else ptr2 = ptr2->next;
            }
            return ptr1;
        } else {
            ListNode * ptr = loop1->next;
            while (ptr != loop2) {
                if (ptr == loop1) return nullptr;
                ptr = ptr->next;
            }
            return ptr;
        }
    }
};

int main(void)
{
    ListNode * head = nullptr;


    return 0;
}