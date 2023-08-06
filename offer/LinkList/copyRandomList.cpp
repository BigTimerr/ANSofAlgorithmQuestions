//
// Created by ruetrash on 2023/8/6.
//

# include <iostream>
# include <algorithm>
# include <vector>
# include <unordered_map>

using namespace std;

class Node{
public:
    int val;
    Node* next;
    Node* random;

    Node(int val){
        val = val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution {
public:



    Node* copyRandomList(Node* head) {
        if (!head){
            return nullptr;
        }
        Node *headptr = head;
        unordered_map<Node*, Node*> nodeList;

        while (headptr){
            nodeList[headptr] = new Node(headptr->val);
            headptr = headptr->next;
        }
        headptr = head;
        while(headptr){
            nodeList[headptr]->next = nodeList[headptr->next];
            nodeList[headptr]->random = nodeList[headptr->random];
            headptr = headptr->next;
        }

        return nodeList[head];

    }


};
