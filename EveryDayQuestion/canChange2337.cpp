//
// Created by ruetrash on 2023/8/21.
//

# include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canChange(string start, string target) {

        auto s = start, t = target;
        s.erase(remove(s.begin(), s.end(), '_'), s.end());
        t.erase(remove(t.begin(), t.end(), '_'), t.end());

        if (s!=t) return false;

        for(int i = 0, j = 0; i<start.size(); i++){
            if (start[i] == '_') i++;
            while(target[j] == '_') j++;
            if (i!=j && (start[i] == 'L') == (i < j))
                return false;
            ++j;
        }
        return true;

    }
};