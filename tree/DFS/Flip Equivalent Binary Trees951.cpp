//
// Created by ruetrash on 2023/5/30.
//

#include "TreeNode.h"

class Solution {
public:

    bool dfs(TreeNode* root1, TreeNode* root2){
        if(root1 == nullptr && root2 == nullptr){
            return true;
        }
        if (root1 == nullptr || root2 == nullptr){
            return false;
        }

        if (root1->val == root2->val ){
            if((dfs(root1->left, root2->right) && dfs(root1->right, root2->left)) || (dfs(root1->left, root2->left) && dfs(root1->right, root2->right)))
                return true;
        }
        return false;


    }


    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        bool res =  dfs(root1, root2);
        return res;
    }
};

//int main(){
//    TreeNode *root = new TreeNode(1);
//    TreeNode *node1 = new TreeNode(2);
//    TreeNode *node2 = new TreeNode(3);
//    TreeNode *node3 = new TreeNode(4);
//    TreeNode *node4 = new TreeNode(5);
//    TreeNode *node5 = new TreeNode(6);
//    TreeNode *node6 = nullptr;
//    TreeNode *node7 = nullptr;
//    TreeNode *node8 = nullptr;
//    TreeNode *node9 = new TreeNode(7);
//    TreeNode *node10 = new TreeNode(8);
//
//    root->left = node1;
//    root->right = node2;
//    node1->left = node3;
//    node1->right = node4;
//    node2->left = node5;
//    node2->right = node6;
//    node3->left = node7;
//    node3->right = node8;
//    node4->left = node9;
//    node4->right = node10;
//
//    TreeNode *troot = new TreeNode(1);
//    TreeNode *tnode1 = new TreeNode(3);
//    TreeNode *tnode2 = new TreeNode(2);
//    TreeNode *tnode3 = nullptr;
//    TreeNode *tnode4 = new TreeNode(6);
//    TreeNode *tnode5 = new TreeNode(4);
//    TreeNode *tnode6 = new TreeNode(5);
//    TreeNode *tnode7 = nullptr;
//    TreeNode *tnode8 = nullptr;
//    TreeNode *tnode9 = nullptr;
//    TreeNode *tnode10 = nullptr;
//    TreeNode *tnode11 = new TreeNode(8);
//    TreeNode *tnode12 = new TreeNode(7);
//
//    troot->left = tnode1;
//    troot->right = tnode2;
//    tnode1->left = tnode3;
//    tnode1->right = tnode4;
//    tnode2->left = tnode5;
//    tnode2->right = tnode6;
//    tnode4->left = tnode7;
//    tnode4->right = tnode8;
//    tnode5->left = tnode9;
//    tnode5->right = tnode10;
//    tnode6->left = tnode11;
//    tnode6->right = tnode12;
//
//    Solution solu = Solution();
//    auto res = solu.flipEquiv(root, troot);
//    cout<< res<<endl;
//
//}