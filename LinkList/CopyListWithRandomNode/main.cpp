#include "List.h"

#include <iostream>
#include <vector>
#include <unordered_map>

//问题描述：复制含有随机指针结点的链表

//解法一：利用hashMap来存储每个结点的复制结点，key: 当前结点，val: 复制结点；
//       这样全部的复制结点创建完毕，复制结点的下一个结点可以通过以当前结点的下一个结点作为key获得
//       复制结点的random结点可以以当前结点的random结点作为key获得
class CopyListWithRandomNode_1
{
public:
    static ListNode * copyListWithRandomNode(ListNode * head)
    {
        std::unordered_map<ListNode *, ListNode *> hashMap;
        ListNode * ptr = head;
        while (ptr) {
            hashMap.insert({ptr, new ListNode(ptr->val)});
            ptr = ptr->next;
        }
        ptr = head;
        while (ptr) {
            hashMap[ptr]->next = hashMap[ptr->next];
            hashMap[ptr]->random = hashMap[ptr->random];
            ptr = ptr->next;
        }
        return hashMap[head];
    }

    static void printRandLinkedList(const ListNode * head)
    {
        const ListNode * cur = head;
		std::cout << "order: " << endl;
		while (cur) {
            std::cout << cur->val << " ";
            cur = cur->next;
		}
		std::cout << endl;
		cur = head;
		std::cout << "random: " << endl;
		while (cur) {
            if (cur->random) std::cout << cur->random->val << " ";
            else std::cout << "- " << " ";
            cur = cur->next;
        }
		std::cout << endl;
    }
};

//解法二：利用链表本身的结构来获知复制结点的随机结点
//       在每一个结点后面插入一个复制结点，这样复制结点的下一个结点就能直接获取
//       复制结点的随机结点就是被复制结点的随机结点下一个结点了
class CopyListWithRandomNode_2
{
public:
    static ListNode * copyListWithRandomNode(ListNode * head)
    {
        if (!head) return nullptr;

        ListNode * ptr = head;
        ListNode * next = nullptr;
        while (ptr) { // 将复制结点全部建立在原有结点的后面
            next = ptr->next;
            ptr->next = new ListNode(ptr->val);
            ptr->next->next = next;
            ptr = next;
        }

        ptr = head;
        while (ptr) { // 设置随机结点
            ptr->next->random = ptr->random ? ptr->random->next : nullptr;
            ptr = ptr->next->next;
        }

        //将复制链表和原链表分离开来
        ptr = head;
        ListNode * ret = head->next;
        ListNode * copyNode = nullptr;
        while (ptr) {
            next = ptr->next->next;
            copyNode = ptr->next;
            ptr->next = next;
            copyNode->next = next ? next->next : nullptr;
            ptr = next;
        }
        return ret;
    }

    static void printRandLinkedList(const ListNode * head)
    {
        const ListNode * cur = head;
		std::cout << "order: " << endl;
		while (cur) {
            std::cout << cur->val << " ";
            cur = cur->next;
		}
		std::cout << endl;
		cur = head;
		std::cout << "random: " << endl;
		while (cur) {
            if (cur->random) std::cout << cur->random->val << " ";
            else std::cout << "- " << " ";
            cur = cur->next;
        }
		std::cout << endl;
    }
};

int main(void)
{
    ListNode * head = nullptr;
    ListNode * res1 = nullptr;
    ListNode * res2 = nullptr;
    CopyListWithRandomNode_1::printRandLinkedList(head);
    res1 = CopyListWithRandomNode_1::copyListWithRandomNode(head);
    CopyListWithRandomNode_1::printRandLinkedList(res1);
    // res2 = copyListWithRand2(head);
    // printRandLinkedList(res2);
    // printRandLinkedList(head);
    std::cout << endl;

    head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);

    head->random = head->next->next->next->next->next;                // 1 -> 6
    head->next->random = head->next->next->next->next->next;           // 2 -> 6
    head->next->next->random = head->next->next->next->next;           // 3 -> 5
    head->next->next->next->random = head->next->next;                // 4 -> 3
    head->next->next->next->next->random = nullptr;                     // 5 -> null
    head->next->next->next->next->next->random = head->next->next->next; // 6 -> 4

    CopyListWithRandomNode_1::printRandLinkedList(head);
    res1 = CopyListWithRandomNode_1::copyListWithRandomNode(head);
    CopyListWithRandomNode_1::printRandLinkedList(res1);
    // res2 = copyListWithRand2(head);
    // printRandLinkedList(res2);
    // printRandLinkedList(head);
    std::cout << endl;

    return 0;
}