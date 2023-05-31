//
// Created by ruetrash on 2023/5/31.
//

# include "TreeNode.h"

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr || root == p || root == q)
            return root;
        auto left = lowestCommonAncestor(root->left, p, q);
        auto right = lowestCommonAncestor(root->right, p , q);
        if (left && right){
            return root;
        }
        if(left){
            return left;
        }
        if(right){
            return right;
        }
        return nullptr;
    }
};