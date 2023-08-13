//
// Created by ruetrash on 2023/8/12.
//

# include <vector>
# include <iostream>
# include <algorithm>
# include <queue>

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){
        auto dummy = new ListNode();
        auto cur = dummy;

        while (list1 && list2){
            if(list1 -> val <= list2->val){
                cur -> next = list1;
                list1 = list1->next;
            }else{
                cur -> next = list2;
                list2 = list2 -> next;
            }
            cur = cur->next;
        }
        cur->next = list1 ? list1 : list2; // 拼接剩余链表
        return dummy->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists, int begin, int end){
        int n = end - begin;
        if (n == 0) return nullptr;
        if (n == 1) return lists[begin];

        auto left = mergeKLists(lists, begin, begin + n/2);
        auto right = mergeKLists(lists, begin + n/2, end);

        return mergeTwoLists(left, right);

    }


    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return mergeKLists(lists, 0, lists.size());

    }
};
