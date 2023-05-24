//
// Created by ruetrash on 2023/5/22.
//
# include <vector>
# include <queue>
# include <cstddef>
# include <iostream>
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
    TreeNode* sufficientSubset(TreeNode* root, int limit){
        if(root == nullptr) return root;

        limit = limit - root->val;
        if(root->left == root->right){
            return limit > 0 ? nullptr : root;
        }

        root->left = sufficientSubset(root->left, limit);
        root->right = sufficientSubset(root->right, limit);

        return root->left || root->right ? root: nullptr;
    }

};


TreeNode* createBinaryTree(const vector<int>& values) {
    if (values.empty())
        return nullptr;

    TreeNode* root = new TreeNode(values[0]);
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    int i = 1;
    while (i < values.size()) {
        TreeNode* currNode = nodeQueue.front();
        nodeQueue.pop();

        int leftVal = values[i++];

        currNode->left = new TreeNode(leftVal);
        nodeQueue.push(currNode->left);


        if (i >= values.size())
            break;

        int rightVal = values[i++];
        currNode->right = new TreeNode(rightVal);
        nodeQueue.push(currNode->right);

    }

    return root;
}

void printBinaryTree(TreeNode* root) {
    if (root == nullptr)
        return;

    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    while (!nodeQueue.empty()) {
        TreeNode* currNode = nodeQueue.front();
        nodeQueue.pop();

        cout << currNode->val << " ";

        if (currNode->left != nullptr)
            nodeQueue.push(currNode->left);

        if (currNode->right != nullptr)
            nodeQueue.push(currNode->right);
    }

    cout << endl;
}


//int main(){
//    vector<int> values = {1, 2, 3, 4, -99, -99, 7, 8, 9, -99, -99, 12, 13, -99, 14};
//    vector<int> values1 = {1, 2, -3, -5, NULL, 4, NULL};
//
//    TreeNode* root = createBinaryTree(values);
//
//    Solution solution = Solution();
//    root = solution.sufficientSubset(root, -1);
//
//
//    printBinaryTree(root);
//
//}