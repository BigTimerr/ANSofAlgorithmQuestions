//
// Created by ruetrash on 2023/7/29.
//
# include <iostream>
# include <algorithm>
# include <cmath>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    bool hasCycle(ListNode *head) {

        if (head == nullptr || head->next == nullptr){
            return false;
        }

        ListNode * ptr = head;
        ListNode * nextptr = head;

        while(ptr!= nullptr && nextptr != nullptr && nextptr->next != nullptr){
            ptr = ptr->next;
            nextptr = nextptr->next->next;
            if (nextptr == ptr){
                return true;
            }
        }
        return false;
    }
};
