#include "List.h"

//讲数组nums中的元素全部复制到单链表 *list 中，采用头插法的方式建立单链表
bool create_list(ListNode * *list, const vector<int> & nums)
{
    // if (!*list)
    // {
    //     (*list) = new ListNode(nums[0]);
    // }

    // ListNode * ptr = *list;
    // for (int i = 1; i < nums.size(); i++)
    // {
    //     ListNode * pcur = new ListNode(nums[i]);
    //     pcur->next = ;
    //     list = pcur;
    // }
    for (const auto elem : nums)
    {
        ListNode * ptr = new ListNode(elem);
        ptr->next = *list;
        (*list) = ptr;

    }
    return true;
}

bool destroy(ListNode * * list)
{
    while (*list)
    {
        ListNode * ptr = (*list);
        (*list) = (*list)->next;
        delete ptr;
    }

    return true;
}

bool insert_list(ListNode * *list, int elem)
{
    if (!*list)
    {
        (*list) = new ListNode(elem);
        return true;
    }

    ListNode * ptr = *list;
    ListNode * pre = ptr;
    while (ptr)
    {
        if (ptr->val < elem)
        {
            pre = ptr;
            ptr = ptr->next;
        }
        else
            break;
    }

    ListNode * insert_node = new ListNode(elem);
    pre->next = insert_node;
    insert_node->next = ptr;
    return true;
}

bool delete_list(ListNode * *list, int & elem)
{
    ListNode * ptr = *list;
    ListNode * pre = ptr;

    if (!search_list(*list, elem))
        return false;

    while (ptr->val != elem)
    {
        pre = ptr;
        ptr = ptr->next;
    }
    pre->next = ptr->next;
    delete ptr;

    return true;
}

bool search_list(const ListNode * list, int elem)
{
    while (list)
    {
        if (list->val == elem)
            return true;
        else
            return false;
    }
    return false;
}

void display_list(const ListNode * list)
{
    while (list)
    {
        cout << list->val << " ";
        list = list->next;
    }
    cout << endl;
}
