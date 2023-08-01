//
// Created by ruetrash on 2023/7/31.
//

# include <iostream>
# include <map>
# include <algorithm>

struct ListNode{
    int val;
    ListNode* next;
    ListNode(): val(0), next(nullptr){}
    ListNode(int val):val(val),next(nullptr){}
    ListNode(int val, ListNode* next):val(val),next(next){}

};


using namespace std;

class Solution {
public:
    void reorderList(ListNode* head) {
        map<int, ListNode*> nodes;
        ListNode* ptr = head;
        if (!ptr) return;
        int n = 0;
        while(ptr){
            nodes[n++] = ptr;
            ptr = ptr->next;
        }

        int i = 0, j = n-1;

        while(i < j){
            nodes[i]->next = nodes[j];
            i++;
            if(i == j){
                break;
            }
            nodes[j]->next = nodes[i];
            j--;
        }
        nodes[i]->next = nullptr;
    }
};

//int main(){
//    ListNode* node0 = new ListNode(1);
//    ListNode* node1 = new ListNode(2);
//    ListNode* node2 = new ListNode(3);
//    ListNode* node3 = new ListNode(4);
//
//    node0->next = node1;
//    node1->next = node2;
//    node2->next = node3;
//
//    Solution solu = Solution();
//    solu.reorderList(node0);
//}
