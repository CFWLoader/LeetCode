//
// Created by CFWLoader on 8/2/17.
//

#ifndef PROBLEM637_SOLUTION_HPP_H
#define PROBLEM637_SOLUTION_HPP_H

#include <cstddef>

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

class Solution
{
public:
    vector<double> averageOfLevels(TreeNode *root)
    {
        if(root == NULL)return vector<double>({0});

        vector<double> layerAverages;

        vector<vector<TreeNode*>> layerValues(1);

        int currentLayer = 0;

        layerValues[currentLayer].push_back(root);

        while(layerValues[currentLayer].size() > 0)
        {
            vector<TreeNode*> nextLayer;

            layerAverages.push_back(0);

            for(vector<TreeNode*>::iterator nodeIter = layerValues[currentLayer].begin();
                    nodeIter != layerValues[currentLayer].end();
                    ++nodeIter)
            {
                layerAverages[currentLayer] += (*nodeIter)->val;

                if((*nodeIter)->left != NULL)nextLayer.push_back((*nodeIter)->left);

                if((*nodeIter)->right != NULL)nextLayer.push_back((*nodeIter)->right);
            }

            layerAverages[currentLayer] /= layerValues[currentLayer].size();

            layerValues.push_back(nextLayer);

            ++currentLayer;
        }

        return layerAverages;

    }
};

#endif //PROBLEM637_SOLUTION_HPP_H
