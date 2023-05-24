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
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> edges(numCourses);
        vector<int> inDegree(numCourses);

        for (auto info: prerequisites) {
            edges[info[1]].emplace_back(info[0]);
            inDegree[info[0]]++;
        }

        queue<int> que;

        for (int i = 0; i < numCourses; ++i) {
            if(inDegree[i] == 0){
                que.push(i);
            }
        }

        vector<int> visited;
        while(!que.empty()){
            int node = que.front();
            que.pop();
            visited.push_back(node);

            for (auto v: edges[node]) {
                inDegree[v]--;
                if (inDegree[v] == 0){
                    que.emplace(v);
                }
            }
        }

        if(visited.size() == numCourses) return visited;
        else return {};

    }
};


int main(){
    int numCourses = 4;
    vector<vector<int>> prerequisites = {{1, 0}, {2,0}};

    Solution solution = Solution();
    auto res = solution.findOrder(numCourses, prerequisites);
    for (int i = 0; i < res.size(); i++) {
        std::cout << res[i] << " ";
    }
    std::cout << std::endl;
}