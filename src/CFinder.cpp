#include "CFinder.h"

CFinder::CFinder() = default;


bool CFinder::checkMatch(const string &rPattern, const string &rRegular) const {
    try {
        regex reg(rRegular);
        bool isValid = regex_match(rPattern, reg);
        return isValid;
    }
    catch (const std::regex_error& e) {
        cout << "regex_error caught: " << e.what() << '\n';
        return false;
    }

}

