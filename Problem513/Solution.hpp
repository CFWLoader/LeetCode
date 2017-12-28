//
// Created by CFWLoader on 8/3/17.
//

#ifndef PROBLEM513_SOLUTION_HPP
#define PROBLEM513_SOLUTION_HPP

#include <vector>

using std::vector;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {

        int layerCounter = 0, val;

        // vector<vector<TreeNode*>*> bfsVec;

        vector<TreeNode*>* currentLayer = new vector<TreeNode*>, *nextLayer;

        currentLayer->push_back(root);

        // bfsVec.push_back(currentLayer);

        while(currentLayer->size() > 0)
        {
            nextLayer = new vector<TreeNode*>;

            val = (*currentLayer)[0]->val;

            for(vector<TreeNode*>::iterator nodeIter = currentLayer->begin();
                    nodeIter != currentLayer->end();
                    ++nodeIter)
            {
                if((*nodeIter)->left != NULL)nextLayer->push_back((*nodeIter)->left);

                if((*nodeIter)->right != NULL)nextLayer->push_back((*nodeIter)->right);
            }

            delete currentLayer;

            currentLayer = nextLayer;
        }

        return val;

    }
};

#endif //PROBLEM513_SOLUTION_HPP
