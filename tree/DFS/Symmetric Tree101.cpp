//
// Created by ruetrash on 2023/5/29.
//
# include "TreeNode.h"

class Solution {
public:

    bool check(TreeNode* p, TreeNode* q){
        if(q == nullptr && p == nullptr){
            return true;
        }
        if(q == nullptr || p == nullptr){
            return false;
        }
        if(p->val == q->val && check(p->left, q->right) && check(p->right, q->left)){
            return true;
        }
        return false;
    }


    bool isSymmetric(TreeNode* root) {
        bool ans = check(root ,root);
        return ans;
    }
};