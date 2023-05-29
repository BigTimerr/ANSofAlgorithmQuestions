//
// Created by ruetrash on 2023/5/29.
//

#include <iostream>
#include <algorithm>

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
    int ans = 0;
    int depth(TreeNode* root){
        if (root == NULL){
            return 0;
        }
        int L = depth(root->left);
        int R = depth(root->right);

        ans = max(ans, L+R);        // 这个节点的长度是否大于最大值，
        return max(L, R)+1;         // 返回这个节点的最长的一条边，+1是因为返回的是节点的个数，需要+1 表示边的个数
    }

    int diameterOfBinaryTree(TreeNode* root) {
        depth(root);
        return ans;
    }
};