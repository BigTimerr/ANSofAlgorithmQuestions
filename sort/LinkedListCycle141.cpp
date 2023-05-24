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
    bool hasCycle(ListNode *head) {
        if(head == nullptr || head->next == nullptr){
            return false;
        }
        ListNode* fast = head->next;
        ListNode* slow = head;
        while(fast != slow){
            if(fast == nullptr || fast->next == nullptr){
                return false;
            }
            fast = fast->next->next;
            slow = slow->next;
        }
        return true;
    }
};
