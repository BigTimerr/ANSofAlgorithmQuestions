//
// Created by ruetrash on 2023/7/25.
//
# include <iostream>
# include <stack>
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
        stack<int> num1;
        stack<int> num2;
        ListNode* head = nullptr;

        while(l1 || l2){
            if (l1){
                num1.push(l1->val);
                l1 = l1->next;
            }
            if (l2){
                num2.push(l2->val);
                l2 = l2->next;
            }
        }
        int t = 0;

        while(!num1.empty() || !num2.empty() || t!=0){
            if (!num1.empty()){
                t += num1.top();
                num1.pop();
            }
            if (!num2.empty()){
                t += num2.top();
                num2.pop();
            }

            auto newnode = new ListNode(t%10);
            t = t / 10;
            newnode->next = head;
            head = newnode;
        }
        return head;
    }
};