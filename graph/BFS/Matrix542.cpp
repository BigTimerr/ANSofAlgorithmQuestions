//
// Created by ruetrash on 2023/5/22.
//

# include <vector>
# include <queue>
using namespace std;

struct Node{
    int x;
    int y;
};


class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<Node> q;
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> visited(n, vector<int>(m));
        vector<vector<int>> dist(n, vector<int>(m));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (mat[i][j] == 0) {
                    visited[i][j] = 1;
                    q.push({i,j});
                }
            }
        }


        while(!q.empty()){
            Node p = q.front();
            q.pop();
            int x = p.x;
            int y = p.y;
            vector<Node> nextNode = {{x + 1, y}, {x - 1, y}, {x, y + 1}, {x, y - 1}};
            for (auto node : nextNode) {
                if(node.x>=0 && node.x<n && node.y>=0 && node.y<m && visited[node.x][node.y] == 0){
                    visited[node.x][node.y] = 1;
                    dist[node.x][node.y] = dist[x][y] + 1;
                    q.push(node);
                }
            }
        }
        return dist;

    }
};