//
// Created by ruetrash on 2023/6/26.
//
# include "TreeNode.h"


class Solution {
public:

    unordered_map<int,int> index;
    TreeNode* buildTreeHelper(vector<int>& preorder, vector<int>& inorder, int preorder_left, int preorder_right, int inorder_left, int inorder_right){
        if (preorder_left > preorder_right){
            return nullptr;
        }

        int preorder_root = preorder_left;
        int inorder_root = index[preorder[preorder_root]];

        TreeNode* root = new TreeNode(preorder[preorder_root]);

        int size_left = inorder_root - inorder_left;

        root->left = buildTreeHelper(preorder, inorder, preorder_left+1, preorder_left+size_left, inorder_left, inorder_root-1);
        root->right = buildTreeHelper(preorder, inorder, preorder_left+size_left+1, preorder_right, inorder_root+1, inorder_right);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();

        for (int i = 0; i < n; ++i) {
            index[inorder[i]] = i;
        }
        return buildTreeHelper(preorder, inorder, 0, n-1, 0 ,n-1);
    }
};