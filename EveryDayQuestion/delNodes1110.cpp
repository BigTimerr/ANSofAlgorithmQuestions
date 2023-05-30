//
// Created by ruetrash on 2023/5/30.
//


#include <iostream>
#include <queue>
#include <algorithm>
#include <unordered_set>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:

    unordered_set<int> toDelete;
    vector<TreeNode *> forest;

    bool dfs(TreeNode* root){
        if(root == nullptr) return false;
        bool keepLeft = dfs(root->left);
        bool keepRight = dfs(root->right);

        if (toDelete.count(root->val)){
            if(keepLeft){
                forest.push_back(root->left);
            }
            if(keepRight){
                forest.push_back(root->right);
            }
            return false;
        }
        else{
            root->left = keepLeft? root->left : nullptr;
            root->right = keepRight ? root->right : nullptr;
            return true;
        }
    }


    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {

        for (int i : to_delete) {
            toDelete.insert(i);
        }
        if(dfs(root)) forest.push_back(root);
        return forest;
    }
};