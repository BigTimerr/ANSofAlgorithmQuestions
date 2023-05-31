//
// Created by ruetrash on 2023/5/31.
//

#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>


using namespace std;


class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        stack<int> st;
        st.push(INT_MAX);
        int ans = 0;

        for (int i = 0; i < arr.size(); ++i) {
            while(arr[i]>=st.top()){
                auto temp = st.top();
                st.pop();
                ans += temp * min(st.top(), arr[i]);
            }
            st.push(arr[i]);
        }

        while(st.size() > 2){
            auto temp = st.top();
            st.pop();
            ans += temp * st.top();
        }

        return ans;
    }
};
