//
// Created by ruetrash on 2023/6/25.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

class Solution {
public:

    void bfs(vector<vector<int>>& land, int x, int y, int& count){
        if (x<0 || x>=land.size() || y<0 || y>=land[0].size() || land[x][y] != 0){
            return ;
        }
        count++;
        land[x][y] = 1;
        bfs(land, x-1, y, count);
        bfs(land, x+1, y, count);
        bfs(land, x, y-1, count);
        bfs(land, x, y+1, count);
        bfs(land, x-1, y-1, count);
        bfs(land, x+1, y-1, count);
        bfs(land, x-1, y+1, count);
        bfs(land, x+1, y+1, count);

    }


    vector<int> pondSizes(vector<vector<int>>& land) {

        vector<int>  res;


        int n = land.size();
        int m = land[0].size();

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int count = 0;
                if(land[i][j] == 0){
                    bfs(land, i ,j ,count);
                }
                if (count!=0){
                    res.push_back(count);
                }
            }

        }
        sort(res.begin(), res.end());
        return res;

    }
};

//int main(){
//    vector<vector<int>> matrix = {
//            {0,2,1,0},
//            {0,1,0,1},
//            {1,1,0,1},
//            {0,1,0,1},
//
//    };
//
//    Solution solu = Solution();
//    vector<int> nums = solu.pondSizes(matrix);
//    for(auto num:nums){
//        cout<<num<<" ";
//    }
//
//}