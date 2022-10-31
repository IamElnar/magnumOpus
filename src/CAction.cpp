#include "CAction.h"

CAction::CAction() = default;

CAction::~CAction() = default;

bool CAction::checkExtinction(const fs::path& rCurrentPath) const {
    int returnVal;
    returnVal = access(rCurrentPath.c_str(), F_OK);
    if (returnVal == 0) {
        return true;
    }
    else {
        return false;
    }
}

bool CAction::checkReadable(const fs::path &rCurrentPath) const {
    int  returnVal;
    returnVal = access(rCurrentPath.c_str(), R_OK);
    if (returnVal == 0) {
        return true;
    }
    else {
        return false;
    }
}

bool CAction::checkWritable(const fs::path &rCurrentPath) const {
    int returnVal;
    returnVal = access(rCurrentPath.c_str(), W_OK);
    if (returnVal == 0) {
        return true;
    }
    else {
        return false;
    }

}

bool CAction::checkExecutable(const fs::path &rCurrentPath) const {
    int returnVal;
    returnVal = access(rCurrentPath.c_str(), X_OK);
    if (returnVal == 0) {
        return true;
    }
    else {
        return false;
    }

}

void CAction::separateInput(const string & rPath) {
    mTokens.clear();
    stringstream ss(rPath);
    string word;
    while(ss >> word) {
        mTokens.push_back(word);
    }
}

const vector<string> &CAction::getMTokens() const {
    return mTokens;
}








