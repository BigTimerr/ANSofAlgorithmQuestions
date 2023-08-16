//
// Created by ruetrash on 2023/8/15.
//

# include <string>
# include <vector>
# include <algorithm>
# include <iostream>
# include <numeric>

using namespace std;

class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {

        vector<int> ops(indices.size());
        iota(ops.begin(), ops.end(), 0);
        sort(ops.begin(), ops.end(), [&](int i, int j){return indices[i]<indices[j];});


        int flag = 0;

        for (int i = 0; i < indices.size(); ++i) {
            if (i == indices.size() - 1) {
                cout << ops[i]<<endl;
                cout << indices[ops[i]]<<endl;
                cout << sources[ops[i]]<<endl;
                cout << targets[ops[i]]<<endl;
                cout << flag <<endl;
                cout << s.find(sources[ops[i]]) <<endl;
                cout << indices[ops[i]] + flag<<endl;
            }
            if (s.compare(indices[ops[i]]+flag, sources[ops[i]].length(), sources[ops[i]]) == 0){

                s.erase(indices[ops[i]] + flag, sources[ops[i]].size());
                s.insert(indices[ops[i]] + flag, targets[ops[i]]);
                flag = flag + targets[ops[i]].size() - sources[ops[i]].size();
            }

        }
        return s;

    }
};

int main(){
    string s = "ehvfwtrvcodllgjctguxeicjoudmxbevzrvravkidnricwsbnxmxvdckzahmqzbrlqugtmjvoqbxarmlgjeqcorhnodvnoqfomdp";
    vector<int> indices = {1,31,44,70,23,73,76,92,90,86,42,4,50,17,53,20,55,15,38,64,25,9,7,68,60,88,96,47,57,34,81,78,28};
    vector<string> sources = {"hvf","vzr","cw","jvo","jo","qb","ar","noqf","dv","rh","ri","wt","mx","gux","dc","eic","kz","ct","kidn","lq","ud","odll","vc","tm","qz","no","om","bn","ahm","vra","jeqco","ml","xb"};
    vector<string> targets = {"ajq","zb","r","fai","e","zs","io","snxd","nw","oi","ofb","quq","gj","nsys","dk","sf","muj","ll","hqx","k","n","ptrya","f","qek","u","dhj","e","kr","waj","rvkr","roaoeq","mci","djw"};

    Solution solution = Solution();
    cout << solution.findReplaceString(s, indices, sources, targets);
}