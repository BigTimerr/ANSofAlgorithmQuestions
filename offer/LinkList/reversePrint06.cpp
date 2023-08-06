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

    vector<int> reversePrint(ListNode* head) {
        stack<int> temp;
        vector<int> res;
        while(head != nullptr){
            temp.emplace(head->val);
            head = head->next;
        }
        while (!temp.empty()){
            res.emplace_back(temp.top());
            temp.pop();
        }
        return res;
    }
};