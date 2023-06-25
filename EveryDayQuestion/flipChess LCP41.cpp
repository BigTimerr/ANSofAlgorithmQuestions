//
// Created by ruetrash on 2023/6/25.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <queue>

using namespace std;

class Solution {
public:
    int flipChess(vector<string>& chessboard) {
        int n = chessboard.size();
        int m = chessboard[0].size();

        auto bfs = [&](int i, int j)-> int {         //lambda表达式;
            queue<pair<int, int>> q;
            q.emplace(i ,j);
            auto g = chessboard;
            g[i][j] ='X';
            int cnt = 0;
            while(!q.empty()){
                auto p = q.front();
                q.pop();
                i = p.first;
                j = p.second;

                for (int a = -1; a <= 1; ++a) {
                    for (int b = -1; b <= 1; ++b) {
                        if (a==0 && b==0){
                            continue;
                        }
                        int x = i + a, y = j + b;
                        while(x>=0 && x<n && y>=0 && y<m && g[x][y] == 'O'){
                            x += a;
                            y += b;
                        }
                        if (x>=0 && x<n && y>=0 && y<m && g[x][y] == 'X'){
                            x -= a;
                            y -= b;
                            cnt += max(abs(x-i), abs(y-j));
                            while(x != i || y != j){
                                g[x][y] = 'X';
                                q.emplace(x, y);
                                x -= a;
                                y -= b;
                            }
                        }

                    }

                }
            }
            return cnt;
        };



        int res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (chessboard[i][j] == '.'){
                    res = max(res, bfs(i,j));
                }
            }
        }
        return res;

    }
};