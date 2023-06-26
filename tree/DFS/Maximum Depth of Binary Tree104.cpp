//
// Created by ruetrash on 2023/6/26.
//

#include "TreeNode.h"


class Solution {
public:


    int maxDepth(TreeNode* root) {
        if(root == nullptr){return 0;}
        int depth_left = maxDepth(root->left);
        int depth_right = maxDepth(root->right);

        int len = max(depth_left, depth_right);
        return len+1;

    }
};