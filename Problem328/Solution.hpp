//
// Created by cfwloader on 2/20/16.
//

#ifndef PROBLEM328_SOLUTION_HPP
#define PROBLEM328_SOLUTION_HPP

/**
 * Definition for singly-linked list.
 **/
struct ListNode
{
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr)
    { }
};

class Solution
{
public:
    // Notice that this problem is about calculating the equivalent index of the nodes, not the nodes' stored value.
    ListNode *oddEvenList(ListNode *head)
    {
        if(head == nullptr)
        {
            return nullptr;
        }

        if(head->next == nullptr)
        {
            return head;
        }

        ListNode* oddHead = head, *evenHead = head->next;

        head->next = evenHead->next;

        ListNode* ptr = head->next, *oddPtr = oddHead, *evenPtr = evenHead;

        for(int index = 3; ptr != nullptr; ++index, ptr = ptr->next)
        {
            if(index % 2 != 0)
            {
                oddPtr->next = ptr;

                oddPtr = oddPtr->next;
            }
            else
            {
                evenPtr->next = ptr;

                evenPtr = evenPtr->next;
            }

        }

        evenPtr->next = nullptr;

        oddPtr->next = evenHead;

        return oddHead;
    }

    ListNode *oddEvenList0(ListNode *head)                  // Wrong Answer because of wrong comprehension of requirement.
    {
        if(head == nullptr)
        {
            return nullptr;
        }

        if(head->next == nullptr)
        {
            return head;
        }

        ListNode* head1 = head, *head2 = head->next;

        head->next = head2->next;

        int traitValue = head1 -> val % 2;

        ListNode* ptr = head1->next, *ptr1 = head1, *ptr2 = head2;

        while(ptr != nullptr)
        {
            if(ptr->val % 2 == traitValue)
            {
                ptr1->next = ptr;

                ptr1 = ptr1->next;
            }
            else
            {
                ptr2->next = ptr;

                ptr2 = ptr2->next;
            }

            ptr = ptr->next;
        }

        ptr2->next = nullptr;

        ptr1->next = head2;

        return head1;
    }

    /*
    ListNode* findNextOddNode(ListNode* node)
    {
        if(node == nullptr)
        {
            return nullptr;
        }

        ListNode* target = node->next;

        while(target != nullptr)
        {
            if(target->val % 2 == 0)
            {
                return target;
            }

            target = target->next;
        }

        return target;
    }
     */
};

#endif //PROBLEM328_SOLUTION_HPP
