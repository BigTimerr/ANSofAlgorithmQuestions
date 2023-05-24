//
// Created by ruetrash on 2023/5/11.
//
#include <iostream>
#include <vector>

using namespace std;


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode* curr = head;
        ListNode* next = head->next;
        ListNode* temp = nullptr;
        while(curr){
            curr->next = temp;
            temp = curr;
            curr = next;
            if(next != nullptr){   // 他妈的，搞了我一个小时
                next = next->next;
            }

        }
        return temp;
    }

};

