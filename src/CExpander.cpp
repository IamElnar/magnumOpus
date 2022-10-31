#include "CExpander.h"


vector<string> &CExpander::expand(string &rPattern) {
    vector <string> list(100);
    mCounter = 0;
    int flag = false;
    for(char i : rPattern) {
        if(i == ',') {
            continue;
        }else if(i == '{') {
            flag = true;
        }else if(i == '}') {
            flag = false;
            mCounter++;
        }else{
            list[mCounter] += i;
            if(!flag) mCounter++;
        }
    }
    solve(0, list, "");
    sort(mCombinations.begin(), mCombinations.end());
    return mCombinations;
}

void CExpander::solve(int idx, vector<string> list, const string& curr) {
    if(idx == mCounter) {
        mCombinations.push_back(curr);
        return;
    }
    for(unsigned long i = 0; i < list[idx].size(); i++) {
        solve(idx + 1, list, curr + list[idx][i]);
    }
}



