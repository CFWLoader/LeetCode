//
// Created by CFWLoader on 9/15/17.
//

#ifndef PROBLEM109_SOLUTION_HPP
#define PROBLEM109_SOLUTION_HPP

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

//  Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode *sortedListToBST(ListNode *head)
    {
        return sortedListToBST(head, nullptr);
    }

private:

    TreeNode *sortedListToBST(ListNode *head, ListNode *tail)
    {
//        std::cout << "Head:";
//
//        if(head == nullptr)
//        {
//            std::cout <<  "NULL";
//        }
//        else
//        {
//            std::cout << head->val;
//        }
//
//        std::cout << " Tail:";
//
//        if (tail == nullptr) {
//            std::cout << "NULL";
//        } else
//        {
//            std::cout << tail->val;
//        }
//
//
//        std::cout << std::endl;

        if(head == tail)
        {
            return nullptr;
        }

        if(head->next == tail)
        {
            return new TreeNode(head->val);
        }

        // Use fast-slow pointer to find the middle point.
        ListNode* mid = head, *twiceSpeed = head;

        while(twiceSpeed->next != tail)
        {
            if(twiceSpeed->next->next != tail)
            {
                mid = mid->next;

                twiceSpeed = twiceSpeed->next->next;
            }
            else
            {
                twiceSpeed = twiceSpeed->next;
            }
        }

//        std::cout << "Find mid:" << mid->val << std::endl;

        TreeNode* root = new TreeNode(mid->val);

        root->left = sortedListToBST(head, mid);

        root->right = sortedListToBST(mid->next, tail);

        return root;

    }
};

#endif //PROBLEM109_SOLUTION_HPP
