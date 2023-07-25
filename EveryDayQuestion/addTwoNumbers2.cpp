//
// Created by ruetrash on 2023/7/25.
//

# include <iostream>

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l3 = new ListNode(-1);
        ListNode* head = l3;
        int t = 0;
        while(l1 != nullptr || l2 != nullptr || t != 0){
            if(l1 != nullptr){
                t += l1->val;
                l1 = l1 -> next;
            }
            if (l2 != nullptr ){
                t += l2->val;
                l2 = l2 -> next;
            }
            head->next = new ListNode(t%10);
            t = t/10;
            head = head->next;
        }
        return l3->next;
        }

};

