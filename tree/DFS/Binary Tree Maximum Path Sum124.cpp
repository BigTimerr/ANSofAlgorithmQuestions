//
// Created by ruetrash on 2023/5/29.
//

#include "TreeNode.h"

class Solution {
public:
    int ans = 0;

    int dfs(TreeNode *root){
        if(root == NULL){
            return 0;
        }

        int L = dfs(root->left);
        int R = dfs(root->right);
        ans = max(ans, L+R+root->val);
        ans = max(ans, L+root->val);
        ans = max(ans, R+root->val);
        ans = max(ans, root->val);

        return max(max(L, R) ,0)+ root->val;

    }


    int maxPathSum(TreeNode* root) {
        ans = root->val;
        dfs(root);
        return ans;
    }

};