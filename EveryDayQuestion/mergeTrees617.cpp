//
// Created by ruetrash on 2023/8/14.
//
# include <algorithm>
# include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode():val(0),left(nullptr), right(nullptr){}
    TreeNode(int val):val(val),left(nullptr),right(nullptr){}
    TreeNode(int val, TreeNode* left, TreeNode* right):val(val),left(left),right(right){}
};

class Solution {
public:
    TreeNode* mergeTreeNodes(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2) return nullptr;
        TreeNode* newNode = new TreeNode();
        if (!root1) return root2;
        if (!root2) return root1;

        newNode->left = mergeTreeNodes(root1->left, root2->left);
        newNode->right = mergeTreeNodes(root1->right, root2->right);

        newNode->val = root1->val + root2->val;

        return newNode;


    }


    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2) return nullptr;
        return mergeTreeNodes(root1, root2);
    }
};
