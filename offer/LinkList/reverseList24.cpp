//
// Created by ruetrash on 2023/8/3.
//
# include <vector>
# include <string>
# include <algorithm>
# include <stack>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(val), next(NULL) {}
};



class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = nullptr;
        ListNode *curr = head;

        while (curr){
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};