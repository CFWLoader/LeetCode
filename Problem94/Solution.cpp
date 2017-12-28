/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int> resultSet;
        
        if(root == NULL)
        {
            return resultSet;
        }
        
        stack<TreeNode*> treeStack;
        
        TreeNode* ptr = root;
        
        while(ptr || !treeStack.empty())
        {
            if(ptr != NULL)
            {
                treeStack.push(ptr);
                ptr = ptr->left;
            }
            else
            {
                ptr = treeStack.top();
                treeStack.pop();
                
                resultSet.push_back(ptr->val);
                
                ptr = ptr->right;
            }
        }
        
        return resultSet;
    }
};