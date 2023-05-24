//
// Created by ruetrash on 2023/5/18.
//
#include <iostream>
# include <vector>
#include <cmath>
#include <queue>
using namespace std;

struct Node{
    int x;
    int y;
};

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int ans = 0;
        queue<Node> q;
        int n = grid.size();

        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        vector<vector<int>> visited(n, vector<int>(n,0));
        q.push({0,0});
        visited[0][0] = 1;
        while (!q.empty()){
            int counts = q.size();
            for (int i = 0; i < counts; ++i) {
                Node currentNode = q.front();
                q.pop();
                int x = currentNode.x;
                int y = currentNode.y;
                if(x == n-1 && y == n-1){
                    return ans+1;
                }

                vector<Node> nextNode = {{x + 1, y}, {x - 1, y}, {x + 1, y - 1}, {x + 1, y + 1},
                                         {x, y + 1}, {x, y - 1}, {x - 1, y - 1}, {x - 1, y + 1}};

                for (auto node: nextNode) {
                    if(node.x<0 || node.y<0 || node.x>=n || node.y>=n || visited[node.x][node.y] == 1 || grid[node.x][node.y] == 1){
                        continue;
                    }
                    visited[node.x][node.y] = 1;
                    q.push(node);
                }

            }
            ans++;
        }
        return -1;
    }
};