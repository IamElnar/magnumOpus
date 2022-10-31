/**
 * Expander class.
 * More detailed class description.
 */

#ifndef PA_2_CEXPANDER_H
#define PA_2_CEXPANDER_H

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class CExpander {
private:
    vector<string> mCombinations;
    int mCounter;
    void solve(int idx, vector<string> list, const string& curr);
public:
    /**
   * member for simple brace exception.
   * It works only with 1 char.
   * @param name name of the file.
   */
    vector<string> &expand(string &rPattern);
};


#endif //PA_2_CEXPANDER_H
