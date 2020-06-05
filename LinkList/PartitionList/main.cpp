#include "List.h"

#include <iostream>
#include <vector>

using namespace std;

//将一个链表划分等三部分，第一部分小于val，第二部分等于val，第三部分大于val

//解法一：将链表中的数据全部复制到一个数组中，在数组中将数据分成三份，然后将数组中的数据拷贝回链表中
//时间复杂度O(N), 空间复杂度O(N)
class PartitionList_1
{
public:
    static void partitionList(ListNode * & head, int val)
    {
        if (!head || !head->next) return;
        vector<int> nums;
        for (ListNode * ptr = head; ptr; ptr = ptr->next) {
            nums.push_back(ptr->val);
        }
        partitionArray(nums, val);
        int i = 0;
        ListNode * ptr = head;
        while (ptr) {
            ptr->val = nums[i++];
            ptr = ptr->next;
        }
    }

private:
    static void partitionArray(vector<int> & nums, int val)
    {
        if (nums.size() <= 1) return;
        int less = -1;
        int more = nums.size();
        int cur =  0;
        while (cur < more) {
            if (nums[cur] < val) {
                std::swap(nums[++less], nums[cur++]);
            } else if (nums[cur] == val) {
                cur++;
            } else {
                std::swap(nums[cur], nums[--more]);
            }
        }
    }
};

//解法二：建立三个链表，分别为小于val的链表，等于val的链表，大于val的链表
class PartitionList_2
{
public:
    static ListNode * partitionList(ListNode * head, int val)
    {
        ListNode * lessHead = nullptr, * lessTail = nullptr;
        ListNode * equalHead = nullptr, * equalTail = nullptr;
        ListNode * moreHead = nullptr, * moreTail = nullptr;
        ListNode * next = nullptr;
        while (head) {
            next = head->next;
            head->next = nullptr;
            if (head->val < val) {
                if (!lessHead) {
                    lessHead = lessTail = head;
                } else {
                    lessTail->next = head;
                    lessTail = lessTail->next;
                }
            } else if (head->val == val) {
                if (!equalHead) {
                    equalHead = equalTail = head;
                } else {
                    equalTail->next = head;
                    equalTail = equalTail->next;
                }
            } else {
                if (!moreHead) {
                    moreHead = moreTail = head;
                } else {
                    moreTail->next = head;
                    moreTail = moreTail->next;
                }
            }
            head = next;
        }

        //将三个链表拼接起来
        if (lessTail) {
            lessTail->next = equalHead;
            equalTail = equalTail ? equalTail : lessTail;
        }
        if (equalTail) {
            equalTail->next = moreHead;
        }

        return lessHead ? lessHead : equalHead ? equalHead : moreHead;
    }
};

int main(void)
{
    vector<int> nums{3, 1, 5, 8, 2, 6, 1, 0, 3, 9};
    ListNode * head = nullptr;
    create_list(&head, nums);
    for (ListNode * ptr = head; ptr; ptr = ptr->next) {
        cout << ptr->val << " ";
    }
    cout << endl;
    head = PartitionList_2::partitionList(head, 8);
    for (ListNode * ptr = head; ptr; ptr = ptr->next) {
        cout << ptr->val << " ";
    }
    cout << endl;

    return 0;
}