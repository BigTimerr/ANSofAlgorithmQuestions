//
// Created by ruetrash on 2023/5/31.
//
# include "TreeNode.h"

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val < root->val && q->val < root->val){
            return lowestCommonAncestor(root->left, p, q);
        }
        if (p->val > root->val && q->val > root->val){
            return lowestCommonAncestor(root->right, p, q);
        }
        return root;
    }
};