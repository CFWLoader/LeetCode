//
// Created by CFWLoader on 8/3/17.
//

#ifndef PROBLEM513_SOLUTION_HPP
#define PROBLEM513_SOLUTION_HPP

#include <cstddef>

#include <tuple>

using std::tuple;
using std::get;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class WrongSolution
{
public:
    int findBottomLeftValue(TreeNode *root)
    {
//        TreeNode *ptr = root;
//
//        int row = 1, col = 0, val;
//
//        while (ptr != NULL)
//        {
//            val = ptr->val;
//
//            ++col;
//
//            ptr = ptr->left;
//        }
//
//        ptr = root;
//
//        int newVal;
//
//        while (ptr != NULL)
//        {
//            newVal = findBottomLeftValue(ptr->right, row, col, val, row + 1);
//
//            ptr = ptr->left;
//        }
//
//        return newVal;

        return get<0>(findBottomLeftValue(root, 1, 0, root->val, 1));
    }

    tuple<int,int,int> findBottomLeftValue(TreeNode *root, int preRow, int preCol, int preVal, int depth)
    {
        if (root == NULL)return tuple<int,int,int>(preVal, preRow, preCol);

        TreeNode *ptr = root;

        int row = depth, col = 0, val;

        while (ptr != NULL)
        {
            val = ptr->val;

            ++col;

            ptr = ptr->left;
        }

        printf("Val:%d, Score:%d, Compare(%d, %d).\n", val, row * col, preVal, preRow * preCol);

        if (row * col < preRow * preCol
            or
            row * col == preRow * preCol and col < preCol)
        {
            val = preVal;
            row = preRow;
            col = preCol;
        }

        // printf("Val:%d, Score:%d, Compare(%d, %d).\n", val, row * col, preVal, preRow * preCol);

        ptr = root;

        tuple<int,int,int> retInfo;

        int newVal;

        while (ptr != NULL)
        {
            retInfo = findBottomLeftValue(ptr->right, row, col, val, depth + 1);

            val = get<0>(retInfo);
            row = get<1>(retInfo);
            col = get<2>(retInfo);

            ptr = ptr->left;
        }

        return retInfo;
    }
};

#endif //PROBLEM513_SOLUTION_HPP
