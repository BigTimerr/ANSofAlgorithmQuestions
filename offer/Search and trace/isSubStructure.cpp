//
// Created by ruetrash on 2023/8/21.
//

# include <vector>
# include <queue>
# include <iostream>
# include <algorithm>

using namespace std;


struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val):val(val),left(nullptr),right(nullptr){}
};



class Solution {
public:
    bool isSameNode(TreeNode* A, TreeNode* B) {

        if (A == nullptr && B != nullptr) return false;
        else if (A == nullptr && B== nullptr) return true;
        else if ( A != nullptr && B == nullptr) return true;

        return isSameNode(A->left, B->left) && isSameNode(A->right, B->right) && A->val == B->val;


    }




    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (!A || !B) return false;
        queue<TreeNode *> q;
        q.emplace(A);

        bool ans = false;

        while (!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if (node->val == B->val){
                ans = isSameNode(node, B);
            }

            if (ans){
                return ans;
            }else{
                if (node->left)
                    q.emplace(node->left);
                if (node->right)
                    q.emplace(node->right);
            }
        }

        return ans;

    }
};