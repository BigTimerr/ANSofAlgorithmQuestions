//
// Created by ruetrash on 2023/5/23.
//
/**
 * 太牛逼啦，竟然还能对下标排序
 *
 *
 * */

# include <vector>
# include <queue>
# include <numeric>
# include <algorithm>
# include <unordered_map>

using namespace std;

class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        int n = values.size();
        vector<int> id(n);
        iota(id.begin(), id.end(), 0);                          //将从0开始的连续整数序列填充到id向量中，
        sort(id.begin(), id.end(), [&](int i, int j){   //使用value中元素大小对id的下标排序
            return values[i] > values[j];
        });

        int ans = 0, choose = 0;
        unordered_map<int,int>cnt;
        for (int i = 0; i < n && choose<numWanted; ++i) {
            int label = labels[id[i]];
            if(cnt[label]==useLimit){
                continue;
            }
            ++choose;
            ans += values[id[i]];
            cnt[label]++;
        }
        return ans;
    }
};