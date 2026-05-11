/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int maxpath(TreeNode* root,int& cost){
        if(root==nullptr) return 0;
        int lh=maxpath(root->left,cost);
        int rh=maxpath(root->right,cost);
        if(lh<0) lh=0;
        if(rh<0) rh=0;
        cost=max(cost,root->val+lh+rh);
        return root->val+max(lh,rh);
    }
    int maxPathSum(TreeNode* root) {
        int cost=root->val;
        int pathsum=maxpath(root,cost);
        return cost;
    }
};
