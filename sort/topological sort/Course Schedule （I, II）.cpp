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
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> edges(numCourses);
        vector<int> inDegree(numCourses);
        queue<int> que;
        for (auto info: prerequisites) {
            edges[info[1]].push_back(info[0]);
            inDegree[info[0]]++;
        }

        for (int i = 0; i < numCourses; ++i) {
            if(inDegree[i] == 0){
                que.push(i);
            }
        }

        int visited = 0;

        while(!que.empty()){
            int node = que.front();
            que.pop();
            visited++;
            for (auto nextNode: edges[node]) {
                --inDegree[nextNode];
                if(inDegree[nextNode] == 0){
                    que.push(nextNode);
                }
            }
        }

        return visited == numCourses;

    }
};
//
//int main(){
//    int numCourses = 2;
//    vector<vector<int>> prerequisites = {{1, 0}, {0,1}};
//
//    Solution solution = Solution();
//    bool res = solution.canFinish(numCourses, prerequisites);
//    cout<<res<<endl;
//}