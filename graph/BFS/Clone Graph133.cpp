//
// Created by ruetrash on 2023/5/16.
//
#include <vector>
#include <unordered_set>
#include <queue>
#include <unordered_map>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};



class Solution {
public:
    Node* cloneGraph(Node* node) {

        if(!node) return nullptr;

        queue<Node*> q;
        unordered_map<Node*, Node*> visited;
        q.push(node);
        visited[node] = new Node(node->val);

        while(!q.empty()){
            Node* p = q.front();
            q.pop();
            for (Node* neighbor:p->neighbors) {
                if (visited.find(neighbor) == visited.end()){
                    visited[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }
                visited[p]->neighbors.emplace_back(visited[neighbor]);

            }
        }
        return visited[node];
    }
};