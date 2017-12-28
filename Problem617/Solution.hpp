//
// Created by CFWLoader on 7/27/17.
//


#include <cstddef>

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


#ifndef PROBLEM617_SOLUTION_H
#define PROBLEM617_SOLUTION_H


class Solution
{
public:

    TreeNode *mergeTrees(TreeNode *t1, TreeNode *t2)
    {

        int t_case = t2 == NULL ? 0 : 1;

        t_case += t1 == NULL ? 0 : 2;

        TreeNode* ret_val = NULL;

        switch (t_case)
        {
            case 1:
                ret_val = new TreeNode(t2->val);
                ret_val->left = mergeTrees(NULL, t2->left);
                ret_val->right = mergeTrees(NULL, t2->right);
                break;
            case 2:
                ret_val = new TreeNode(t1->val);
                ret_val->left = mergeTrees(t1->left, NULL);
                ret_val->right = mergeTrees(t1->right, NULL);
                break;
            case 3:
                ret_val = new TreeNode(t1->val + t2->val);
                ret_val->left = mergeTrees(t1->left, t2->left);
                ret_val->right = mergeTrees(t1->right, t2->right);
                break;
            default:
                break;
        }

        return ret_val;
    }
};


#endif //PROBLEM617_SOLUTION_H
