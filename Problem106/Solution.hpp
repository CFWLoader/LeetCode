//
// Created by CFWLoader on 1/2/18.
//

#ifndef PROBLEM106_SOLUTION_HPP
#define PROBLEM106_SOLUTION_HPP

#include <vector>

using std::vector;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        return buildTree(inorder, postorder, 0, inorder.size() - 1, postorder.size() - 1);

    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder, int inLeft, int inRight, int postIdx)
    {
        if(inLeft > inRight)
        {
            return nullptr;
        }

        int rootIdx;

        for(int idx = inLeft; idx <= inRight; ++idx)
        {
            if(inorder[idx] == postorder[postIdx])
            {
                rootIdx = idx;
            }
        }

        TreeNode* root = new TreeNode(postorder[postIdx]);

        // TODO
        root->left = buildTree(inorder, postorder, inLeft, rootIdx - 1, rootIdx - 1);

        root->right = buildTree(inorder, postorder, rootIdx + 1, inRight, postIdx - 1);

        return root;
    }
};

#endif //PROBLEM106_SOLUTION_HPP
