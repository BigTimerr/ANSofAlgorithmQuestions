//
// Created by ruetrash on 2023/8/6.
//


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next){
            return head;
        }

        ListNode *pre = new ListNode(-1);
        pre->next = head;
        ListNode *temp = pre;


        while(temp->next && temp->next->next){
            ListNode *node1 = temp->next;
            ListNode *node2 = temp->next->next;
            temp->next = node2;
            node1 ->next = node2->next;
            node2->next = node1;
            temp = node1;
        }
        return pre->next;
    }
};