//
// Created by ruetrash on 2023/5/17.
//
#include <iostream>
# include <vector>
#include <cmath>
using namespace std;

class Solution {
public:

    void dfs(vector<vector<char>>& board, int x, int y){
        int n = board.size();
        int m = board[0].size();
        if(x < 0 || x >= n || y < 0 || y >= m || board[x][y] != 'O'){
            return;
        }
        board[x][y] = '*';
        dfs(board, x-1, y);
        dfs(board, x+1, y);
        dfs(board, x, y-1);
        dfs(board, x, y+1);

    }


    void solve(vector<vector<char>>& board) {
        int n = board.size();
        if (n==0) return;

        int m = board[0].size();

        for(int i = 0; i < n;i++){
            dfs(board, i , 0);
            dfs(board, i , m-1);
        }

        for(int i = 0; i < m; i++){
            dfs(board, 0, i);
            dfs(board, n-1, i);
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <m; ++j) {
                if(board[i][j] == '*'){
                    board[i][j]='O';
                }
                else if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }

    }
};

//int main(){
////    vector<vector<char>> board = {{'X','X','X','X'}, {'X','O','O','X'},{'X','X','O','X'}, {'X','O','X','X'}};
//    vector<vector<char>> board = {{'X'}};
//
//    Solution solution = Solution();
//    solution.solve(board);
//    for (int i = 0; i < board.size(); ++i) {
//        for (int j = 0; j < board[0].size(); ++j) {
//            cout << board[i][j] << " ";
//        }
//        cout<<endl;
//    }
//}