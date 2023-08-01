//
// Created by ruetrash on 2023/7/28.
//

# include <vector>
# include <iostream>
# include <algorithm>
# include <queue>
using namespace std;



class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> g(n);
        vector<int> indegree(n,0);

        for (auto relation : relations) {
            int a = relation[0] - 1, b = relation[1] - 1;
            g[a].push_back(b);
            indegree[b] ++;
        }

        queue<int> q;
        vector<int> f(n);
        int ans = 0;
        for(int i=0; i < n; i++){
            if (indegree[i] == 0){
                q.push(i);
                f[i] = time[i];
                ans = max(f[i], ans);
            }
        }

        while(!q.empty()){
            int x = q.front();
            q.pop();
            for (auto y: g[x]) {
                indegree[y]-- ;
                if (indegree[y] == 0){
                    q.push(y);
                }
                f[y] = max(f[y], f[x] + time[y]);
//                如果任务 y 之前已经有一个更晚的最早完成时间 f[y]，那么更新后的 f[y] 保持不变，因为不需要更新为更早的时间。
//                如果 f[x] + time[y] 的值更大（即更晚），那么任务 y 的最早完成时间将被更新为这个较大值，以确保它能在所有依赖任务完成后得到执行。
                ans = max(f[y], ans);
            }
        }

    return ans;
    }
};