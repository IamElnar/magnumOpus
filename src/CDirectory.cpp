#include "CDirectory.h"

CDirectory::CDirectory(const fs::path &name) : CFile( name, "DIR") { mCountOfFiles = 0; countFiles(name); }

void CDirectory::Print(ostream &os) const {
    string count = to_string(getCountOfFiles()) + " " + "items";
    os   <<"/"<< setw(40)<< left<<getName() << setw(9) <<left << getType()<< setw(17) << left << count;
}

void CDirectory::countFiles(const fs::path &name)  {
    access(name.c_str(),R_OK);      /**< check if directory is readable.*/
    if(errno == EACCES) {
        return;
    }
    for(auto p: fs::directory_iterator(name)) {
        mCountOfFiles++;
    }
}

int CDirectory::getCountOfFiles() const {
    return mCountOfFiles;
}
