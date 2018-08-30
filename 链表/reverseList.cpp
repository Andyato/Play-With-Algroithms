/*
【题目】 定义一个函数，输入一个链表的头结点，反转该链表并输出反转后链表的头结点。
*/
#include<vector>
#include<iostream>
using namespace std;
struct ListNode
{
    int data;
    ListNode* next;
    ListNode(int val) : data(val), next(nullptr) {}
};

ListNode* reverseList(ListNode* head)
{
    ListNode* pre;
    ListNode* node = head;
    ListNode* next;
    while(node != nullptr)
    {
        next = node->next;
        node->next = pre;

        //依次后移
        pre = node;
        node = next;
    }
    return pre;
}

ListNode* arr2List(vector<int> &arr)
{
    ListNode* head = new ListNode(arr[0]);
    ListNode* ptr = head;
    for (int i = 1; i < arr.size(); ++i)
    {
        if (ptr->next == nullptr)
            ptr->next = new ListNode(arr[i]);
        ptr = ptr->next;
    }
    return head;
}

int main()
{

    vector<int> arr = {1,2,3,4,5};
    ListNode* head = arr2List(arr);
    cout <<"反转前首节点的值："<< head->data << endl;

    head = reverseList(head);
    cout << "反转后首节点的值：" << head->data << endl;
}