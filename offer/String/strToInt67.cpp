//
// Created by ruetrash on 2023/8/1.
//
# include <vector>
# include <string>
# include <unordered_map>
# include <algorithm>
using namespace std;

class Automaton{
    string state = "start";
    unordered_map<string, vector<string>> table = {
            {"start", {"start", "signed", "in_number", "end"}},
            {"signed", {"end", "end", "in_number", "end"}},
            {"in_number", {"end", "end", "in_number", "end"}},
            {"end", {"end", "end", "end", "end"}}
    };

    int get_col(char c){
        if(isspace(c)) return 0;
        if(c == '+' || c == '-') return 1;
        if(isdigit(c)) return 2;
        return 3;
    }

public:
    int sign = 1;
    long long ans = 0;

    void get(char c){
        state = table[state][get_col(c)];
        if(state == "in_number"){
            ans = ans * 10 + c - '0';
            if(sign == 1){
                ans = min(ans, (long long) INT_MAX);
            }else{
                ans = min(ans, -(long long) INT_MAX);
            }
        }
        else if(state == "signed"){
            sign = c=='+'?1:-1;
        }
    }
};

class Solution{
public:
    int strToInt(string str){
        Automaton automaton;
        for(auto c : str){
            automaton.get(c);
        }
        return automaton.sign * automaton.ans;
    }
};