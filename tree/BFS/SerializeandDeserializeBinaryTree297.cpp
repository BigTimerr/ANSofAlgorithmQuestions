//
// Created by ruetrash on 2023/5/13.
//
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


class Codec {
public:

    void reserialize(TreeNode* node, string &s){
        if(node == nullptr){s += "NULL,";}
        else{
            s += to_string(node->val) + ",";
            reserialize(node->left,s);
            reserialize(node->right,s);
        }

    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        reserialize(root, s);
        return s;

    }
    TreeNode* redeserialize(list<string>& dataArray){
        if(dataArray.front() == "NULL"){
            dataArray.erase(dataArray.begin());
            return nullptr;
        }

        TreeNode * root = new TreeNode(stoi(dataArray.front()));
        dataArray.erase(dataArray.begin());
        root->left = redeserialize(dataArray);
        root->right = redeserialize(dataArray);
        return root;

    }


    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        list<string> dataArray;
        string str;
        for(auto& ch:data){
            if(ch == ','){
                dataArray.push_back(str);
                str.clear();
            }else{
                str.push_back(ch);
            }
        }
        if(!str.empty()){
            dataArray.push_back(str);
            str.clear();
        }
        return redeserialize(dataArray);
    }
};



//
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
//    Codec codec = Codec();
//    string str = codec.serialize(root);
//    cout<<str<<endl;
//
//    auto* temp = codec.deserialize(str);
//    str.clear();
//    str = codec.serialize(temp);
//    cout<<str;
//
//}