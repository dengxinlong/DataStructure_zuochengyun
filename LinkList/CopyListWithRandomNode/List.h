#ifndef __LIST_T__
#define __LIST_T__

#include <vector>
#include <iostream>

using namespace std;

//定义链表中的结点结构
struct ListNode
{
    ListNode(int x)     //构造函数
    : val(x)
    , next(nullptr)
    , random(nullptr)
    {}

    int val;
    ListNode *next;
    ListNode * random; // 随机指针，可以指向任意一个结点
};

bool create_list(ListNode * *list, const vector<int> & nums);

bool destroy(ListNode * * list);

bool insert_list(ListNode * *list, int elem);

bool delete_list(ListNode * *list, int & elem);

bool search_list(const ListNode * list, int elem);

void display_list(const ListNode * list);




#endif