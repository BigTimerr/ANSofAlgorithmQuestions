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
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> reverseGraph(n);
        vector<int> inDegree(n);

        for (int i = 0; i < n; ++i) {
            for(auto y : graph[i]){
                reverseGraph[y].push_back(i);
                inDegree[i]++;
            }
        }

        queue<int> queue1;
        for (int i = 0; i < n; ++i) {
            if (inDegree[i] == 0){
                queue1.push(i);
            }
        }

        while(!queue1.empty()){
            int x = queue1.front();
            queue1.pop();
            for(auto v:reverseGraph[x]){
                inDegree[v]--;
                if (inDegree[v] == 0){
                    queue1.push(v);
                }
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (inDegree[i] == 0){
                ans.push_back(i);
            }
        }

        return ans;
    }

};


//int main(){
//
//    vector<vector<int>> graph = {{1,2},{2,3},{5},{0},{5},{},{}};
////    vector<vector<int>> graph = {{1,2,3,4},{1,2},{3,4},{0,4},{}};
//
//    Solution solution = Solution();
//    auto res = solution.eventualSafeNodes(graph);
//    for (auto x: res) {
//        cout<<x<<" ";
//    }
//}