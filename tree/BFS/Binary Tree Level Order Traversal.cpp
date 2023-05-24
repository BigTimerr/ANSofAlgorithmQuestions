//
// Created by ruetrash on 2023/5/13.
//

#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) {return res;}

        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            res.emplace_back();
            for (int i = 0; i < size; ++i) {
                auto node = q.front();
                q.pop();
                res.back().push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);

            }
        }
        return res;
    }


//    vector<vector<int>> levelOrder(TreeNode* root) {
//
//        vector<vector<int>> res;
//        if(root == nullptr){
//            return res;
//        }
//
//        bfs(root, res, 0);
//        return res;
//    }
//
//    void bfs(TreeNode* root, vector<vector<int>>& res, int level){
//        if(!root) return ;
//        if(res.size() < level + 1) res.emplace_back();
//        res[level].push_back(root->val);
//        bfs(root->left, res, level+1);
//        bfs(root->right, res, level+1);
//    }
};

//int main() {
//
//
//    TreeNode *root = new TreeNode(3);
//    TreeNode *node2 = new TreeNode(9);
//    TreeNode *node3 = new TreeNode(20);
//    TreeNode *node4 = new TreeNode(15);
//    TreeNode *node5 = new TreeNode(7);
//
//    root->left = node2;
//    root->right = node3;
//    node3->left = node4;
//    node3->right = node5;
//
//    // 对二叉树进行一些操作...
//
//    Solution solu = Solution();
//    auto res = solu.levelOrder(root);
//    cout<<"[";
//    for(auto xs:res){
//        cout<<"[";
//        for(auto x:xs){
//            cout<<x<<" ";
//        }
//        cout<<"]";
//    }
//    cout<<"]";
//    return 0;
//}