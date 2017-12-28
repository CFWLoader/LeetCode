//
// Created by CFWLoader on 9/15/17.
//

#ifndef PROBLEM82_SOLUTION_HPP
#define PROBLEM82_SOLUTION_HPP

// Definition for singly-linked list.
struct ListNode
{
    int val;

    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

        ListNode* new_head = head,
                *iter = head,
                *beforeDup = head,
                *dupStart = nullptr,
                *nextPtr = nullptr;

        bool duplicated = false;

        while(iter != nullptr)
        {
            if(iter->next != nullptr and iter->val == iter->next->val)
            {
                duplicated = true;

                dupStart = dupStart == nullptr ? iter : dupStart;

//                dupEnd = iter->next;
            }
            else if(duplicated and iter->next != nullptr and iter->val != iter->next->val)
            {

                duplicated = false;

                iter = iter->next;

                beforeDup->next = iter;

                if(dupStart == new_head)
                {
                    beforeDup = new_head = iter;
                }

                while(dupStart != iter)
                {
                    nextPtr = dupStart->next;

                    delete dupStart;

                    dupStart = nextPtr;
                }

                dupStart = nextPtr = nullptr;

                continue;
            }

            beforeDup = duplicated ? beforeDup : iter;

            iter = iter->next;
        }

        if(duplicated)
        {
            beforeDup->next = nullptr;

            if(dupStart == new_head)
            {
                new_head = nullptr;
            }

            while(dupStart != nullptr)
            {
                nextPtr = dupStart->next;

                delete dupStart;

                dupStart = nextPtr;
            }
        }

        return new_head;
    }
};

#endif //PROBLEM82_SOLUTION_HPP
