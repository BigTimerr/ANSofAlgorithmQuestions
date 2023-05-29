//
// Created by ruetrash on 2023/5/29.
//
# include "TreeNode.h"

class Solution {
public:

    void dfs(TreeNode* root){
        if(root == nullptr) return;
        dfs(root->left);
        dfs(root->right);

        TreeNode* temp = root->left;
        root->left= root->right;
        root->right = temp;
        delete(temp);
    }

    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr){
            return root;
        }
        dfs(root);
        return root;
    }
};