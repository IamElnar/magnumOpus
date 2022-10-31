/**
 * Regular expression class.
 * More detailed class description.
 */

#ifndef PA_2_CFINDER_H
#define PA_2_CFINDER_H

#include <regex>
#include <iostream>
#include <experimental/filesystem>

using namespace std;
namespace fs = experimental::filesystem;

class CFinder {
public:
    /**
    * A  default constructor.
    */
    CFinder();
    /**
    * a member for checking match between rPattern and rRegular rule.
    * @param rPattern a string argument.
    * @param rRegular a string argument.
    * @return The test results.
     */
    bool checkMatch(const string& rPattern , const string& rRegular)const;
};


#endif //PA_2_CFINDER_H
