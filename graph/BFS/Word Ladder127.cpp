//
// Created by ruetrash on 2023/5/16.
//
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <string>
#include <map>
using namespace std;


class Solution {
public:
    unordered_map<string,int> wordID;
    vector<vector<int>> edge;
    int wordNums = 0;

    void addWord(string& word){
        if(!wordID.count(word)){
            wordID[word] = wordNums++;
            edge.emplace_back();
        }
    }

    void addEdge(string& word){
        addWord(word);
        int id1 = wordID[word];
        for (char& it:word) {
            char tmp = it;
            it = '*';
            addWord(word);
            int id2 = wordID[word];
            edge[id1].push_back(id2);
            edge[id2].push_back(id1);
            it=tmp;
        }
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        for (string& word:wordList) {
            addEdge(word);
        }
        addEdge(beginWord);
        if(!wordID.count(endWord)){
            return 0;
        }
        vector<int> dis(wordNums, INT_MAX);
        int beginID = wordID[beginWord], endID = wordID[endWord];
        dis[beginID] = 0;

        queue<int> q;
        q.push(beginID);
        while(!q.empty()){
            int x = q.front();
            q.pop();
            if (x == endID){
                return dis[x]/2 +1;
            }
            for (int & it: edge[x]) {
                if(dis[it] == INT_MAX){
                    dis[it] = dis[x] + 1;
                    q.push(it);
                }
            }
        }
        return 0;
    }
};

//int main(){
//    string beginWord = "hit", endWord = "cog";
//    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
//    Solution solution = Solution();
//    int res = solution.ladderLength(beginWord,endWord,wordList);
//    cout<<res<<endl;
//}
