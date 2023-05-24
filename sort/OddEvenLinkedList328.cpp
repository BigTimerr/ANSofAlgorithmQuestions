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
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr){
            return head;
        }

        ListNode* evenHead = head->next;
        ListNode* even = evenHead;
        ListNode* odd = head;
        while(even != nullptr && even->next != nullptr){
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenHead;
        return head;
    }

};


//int main() {
//
//    auto* head = new ListNode(1);
//    auto* node1 = new ListNode(2);
//    auto* node2 = new ListNode(3);
//    auto* node3 = new ListNode(4);
//    auto* node4 = new ListNode(5);
//    auto* node5 = new ListNode(6);
//
//    head->next = node1;
//    node1->next = node2;
//    node2->next = node3;
//    node3->next = node4;
//    node4->next = node5;
//
//    Solution solu = Solution();
//    auto* temp = solu.oddEvenList(head);
//    for (int i = 0; i < 5; ++i) {
//        cout<<temp->val;
//        temp = temp->next;
//
//    }
//
//}