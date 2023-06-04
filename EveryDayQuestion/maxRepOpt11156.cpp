//
// Created by ruetrash on 2023/6/4.
//

#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <unordered_set>
using namespace std;
class Solution {
public:
    int maxRepOpt1(string text) {
        unordered_map<char,int> count;
        for(auto c : text){
            count[c]++;
        }
        int ans = 0;

        for (int i = 0; i < text.size(); ++i) {
            int j = i;
            while(j<text.size() && text[j] == text[i]){
                j++;
            }
            int k = j+1;
            int l = j-i;
            while(k<text.size() && text[k] == text[i]){
                k++;
            }
            int r = k-j-1;

            ans = max(ans, min(l+r+1, count[text[i]]));

        }
        return ans;
    }
};