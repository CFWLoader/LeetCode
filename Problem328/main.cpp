#include <iostream>

#include "Solution.hpp"

using namespace std;

ListNode* generateList(int);

int destroyList(ListNode*);

int testCase1();

int main()
{
    testCase1();

    return 0;
}

ListNode* generateList(int size)
{
    ListNode* head = nullptr;

    head = new ListNode(1);

    ListNode* ptr = head;

    for(int index = 2; index <= size; ++index)
    {
        ptr->next = new ListNode(index);

        ptr = ptr->next;
    }

    return head;
}

int destroyList(ListNode* head)
{
    ListNode* ptr = head->next;

    while(ptr != nullptr)
    {
        delete head;

        head = ptr;

        ptr = head->next;
    }

    delete head;

    return 0;
}

int testCase1()
{
    ListNode* head = generateList(5), *ptr = nullptr;

    Solution solution;

    cout << "Original List:" << endl;

    for(ptr = head; ptr != nullptr; ptr = ptr->next)
    {
        cout << ptr->val << " ";
    }

    cout << endl;

    head = solution.oddEvenList(head);

    cout << "After algo:" << endl;

    for(ptr = head; ptr != nullptr; ptr = ptr->next)
    {
        cout << ptr->val << " ";
    }

    cout << endl;

    destroyList(head);

    head = nullptr;

    return 0;
}
