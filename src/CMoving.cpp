#include "CMoving.h"

bool CMoving::Do(CInterface *pInterface) {
    cout << "Choose destination:" << endl;
    string path;
    getline(cin , path);
    if (path.empty()) {
        return true;
    }
    if(path == "..") {
        if(pInterface->getCurrentPath() == pInterface->getCurrentPath().root_path())
        {
            return true;
        }
        auto cur_p = pInterface->getCurrentPath().parent_path();
        pInterface->setCurrentPath(cur_p);
    }
    else if (path == "//") {
        auto cur_p = pInterface->getCurrentPath().root_path();
        pInterface->setCurrentPath(cur_p);
    }
    else {
        if(path[0] == '/') {
            if(!checkExtinction(path)) {
                cout << "File doesn't exist or hasn't permissions!" << endl;
                return false;
            }
            fs::path new_p(path);
            pInterface->setCurrentPath(new_p);
            pFirst->setCurrentPath(new_p);
            pSecond->setCurrentPath(new_p);
        }
        else {
            auto new_p = pInterface->getCurrentPath() / path;
            if(!checkExtinction(new_p) || !checkReadable(new_p)) {
                cout << "File doesn't exist or hasn't permissions!" << endl;
                return false;
            }
            if(!fs::is_directory(new_p)) {
                cout << "It is not a directory!" << endl;
                return false;
            }
            pInterface->setCurrentPath(new_p);
            pFirst->setCurrentPath(new_p);
            pSecond->setCurrentPath(new_p);
        }
    }
    return true;
}

CMoving::CMoving(CInterface *firstInt, CInterface *secondInt) : CAction( ), pFirst(firstInt), pSecond(secondInt) {}

bool CMoving::DoSpecial(fs::path &existingPath) {
    return false;
}






