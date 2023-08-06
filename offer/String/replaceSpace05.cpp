//
// Created by ruetrash on 2023/8/1.
//
# include <string>

using namespace std;


class Solution {
public:
    string replaceSpace(string s) {
        string new_str = "";
        for (auto c:s) {
            if (c == ' '){
                new_str += "%20";
            }else{
                new_str += c;
            }

        }
        return new_str;
    }
};