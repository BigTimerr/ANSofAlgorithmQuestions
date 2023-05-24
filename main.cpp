#include <iostream>
#include <set>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(k % 2 == 0 || k % 5 == 0){
            return -1;
        }
        else{
            int resid = 1 % k;
            int len = 1;

            unordered_set<int> st;
            st.insert(resid);
            while(resid != 0){
                resid = (resid*10 + 1) % k;
                len ++;
                if(st.find(resid) != st.end()){
                    return -1;
                }
                st.insert(resid);
            }

            return len;
        }


    }
};



