//
// Created by ruetrash on 2023/5/25.
//
# include <vector>
# include <queue>
# include <numeric>
# include <algorithm>
# include <iostream>
# include <unordered_map>

using namespace std;


class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<vector<int>> edges(n);
        vector<int> inDegree(n);


        for (auto node: richer) {
            edges[node[0]].push_back(node[1]);
            inDegree[node[1]]++;
        }

        queue<int> que;
        for (int i = 0; i < n; ++i) {
            if(inDegree[i] == 0){
                que.emplace(i);
            }
        }

        vector<int> ans(n, 0);
        iota(ans.begin(), ans.end(), 0);

        while(!que.empty()){
            auto x = que.front();
            que.pop();
            for(auto y: edges[x]){
                if (quiet[ans[x]]<quiet[ans[y]]){
                    ans[y] = ans[x];
                }
                if (--inDegree[y] == 0){
                    que.push(y);
                }
            }
        }
        return ans;
    }
};

int main(){

    vector<vector<int>> richer = {{1,0},{2,1},{3,1},{3,7},{4,3},{5,3},{6,3}};
    vector<int> quiet = {3,2,5,4,6,1,7,0};
//    vector<vector<int>> graph = {{1,2,3,4},{1,2},{3,4},{0,4},{}};

    Solution solution = Solution();
    auto res = solution.loudAndRich(richer, quiet);
    for (auto x: res) {
        cout<<x<<" ";
    }
}