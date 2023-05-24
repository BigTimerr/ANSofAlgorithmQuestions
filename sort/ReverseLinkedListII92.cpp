//
// Created by ruetrash on 2023/5/11.
//
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummyNode = new ListNode(-1);
        dummyNode->next = head;
        ListNode* pre = dummyNode;
        for(int i = 0; i < left-1; i++){
            pre = pre->next;
        }
        ListNode* curr = pre->next;
        ListNode* next;

        for(int i =0 ; i<right-left;i++){
            next = curr->next;
            curr->next = next->next;
            next->next = pre->next;
            pre->next = next;

        }
        return dummyNode->next;

    }
};



//int main() {
//
//    auto* head = new ListNode(1);
//    auto* node1 = new ListNode(2);
//    auto* node2 = new ListNode(3);
//    auto* node3 = new ListNode(4);
//    auto* node4 = new ListNode(5);
//
//    head->next = node1;
//    node1->next = node2;
//    node2->next = node3;
//    node3->next = node4;
//    int left = 1;
//    int right = 2;
//    Solution solu = Solution();
//    auto* temp = solu.reverseBetween(head,left,right);
//    for (int i = 0; i < 5; ++i) {
//        cout<<temp->val;
//        temp = temp->next;
//
//    }
//
//}