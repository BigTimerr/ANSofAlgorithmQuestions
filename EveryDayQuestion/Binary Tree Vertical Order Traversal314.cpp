//
// Created by ruetrash on 2023/5/14.
//

/// 没会员做不了


#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <list>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
//class Solution {
//public:
//    list<list<int>> verticalOrder(TreeNode* root){
//        int pos = 0;
//        list<list<int>> list;
//        if (!root) {return list;}
//
//
//
//}
//}


//int main() {
//
//
//    TreeNode *root = new TreeNode(1);
//    TreeNode *node2 = new TreeNode(2);
//    TreeNode *node3 = new TreeNode(3);
//    TreeNode *node4 = new TreeNode(4);
//    TreeNode *node5 = new TreeNode(5);
//    TreeNode *node6 = new TreeNode(6);
//    TreeNode *node7 = new TreeNode(7);
//
//    root->left = node2;
//    root->right = node3;
//    node2->left = node4;
//    node2->right = node5;
//    node3->left = node6;
//    node3->right = node7;
//
//    // 对二叉树进行一些操作...
//
//    Solution solu = Solution();
//    auto res = solu.zigzagLevelOrder(root);
//
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