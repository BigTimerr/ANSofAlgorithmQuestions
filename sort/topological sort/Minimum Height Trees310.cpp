//
// Created by ruetrash on 2023/5/24.
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
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {

        if(n==1) return {0};   //如果树只有一个节点就直接返回

        vector<vector<int>> doubleEdges(n);   //保存边的信息，双向保存
        vector<int> inDegree(n);               //保存每个节点的度（包含出度和入度）

        for (auto edge: edges) {
            doubleEdges[edge[0]].push_back(edge[1]);
            doubleEdges[edge[1]].push_back(edge[0]);
            ++inDegree[edge[0]];
            ++inDegree[edge[1]];
        }

        queue<int> que;
        vector<int> ans;

        for (int i = 0; i < n; ++i) {
            if (inDegree[i] == 1){
                que.emplace(i);
            }
        }
        int remain = n;
        while (remain > 2){
            int size = que.size();
            remain -= size;
            for (int i = 0; i < size; ++i) {
                int x = que.front();
                que.pop();
                for (auto &v: doubleEdges[x]) {
                    inDegree[v]--;
                    if (inDegree[v] == 1){
                        que.emplace(v);
                    }
                }

            }

        }
        while(!que.empty()){
            ans.emplace_back(que.front());
            que.pop();
        }
        return ans;
    }
};

//int main(){
//    int n = 6;
//    vector<vector<int>> edges = {{3,0},{3,1},{3,2},{3,4},{5,4}};
////    vector<vector<int>> edges = {{1,0},{1,2},{1,3}};
//    Solution solu = Solution();
//    auto res = solu.findMinHeightTrees(n, edges);
//    std::cout << "Vector elements: ";
//    for (int i = 0; i < res.size(); i++) {
//        std::cout << res[i] << " ";
//    }
//    std::cout << std::endl;
//}
