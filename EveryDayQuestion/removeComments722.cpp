//
// Created by ruetrash on 2023/8/3.
//

#include <string>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string> res;
        bool in_block = false;

        string newline = "";

        for (auto str: source) {
            int n = str.size();
            for (int i = 0; i < n; ++i) {
                if(in_block){
                    if(i+1 < n && str[i] == '*' && str[i+1] == '/'){
                        in_block = false;
                        i++;
                    }
                }else{
                    if (i+1 < n && str[i] == '/' && str[i+1] == '*'){
                        in_block = true;
                        i++;
                    }
                    else if(i+1 < n && str[i] == '/' && str[i+1] == '/'){
                        break;
                    }
                    else{
                        newline += str[i];
                    }
                }
            }
            if(!in_block && newline != ""){
                res.push_back(newline);
                newline = "";
            }

        }
        return res;
    }
};