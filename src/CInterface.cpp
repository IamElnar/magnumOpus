#include "CInterface.h"


CInterface::CInterface() {
    mCurrentPath = fs::current_path();
}

CInterface::~CInterface() {

}

void CInterface::Show() {
    initializeList();
    cout << "=========================================================\n";
    cout << "Current location: " << mCurrentPath << endl;
    cout << "=========================================================\n";
    cout <<left <<setw(40)<< "Name" << setw(10) << "Type" << "Size\n";
    cout << "=========================================================\n";
    for(const auto& f: mFileList){
        cout << *f << '\n' ;
    }
    cout << "=========================================================\n";
    cout << "0:Quit \t1:Change Mode\t2:Change dir \t3:Create file\n"
            "4:Mkdir\t5:Create link\t6:Remove file\t7:Copy file  \n"
            "8:Move \t9:Help\n";
    cout << "Enter command:\n";
}

fs::path CInterface::getCurrentPath() const {
    return mCurrentPath;
}

void CInterface::setCurrentPath(const fs::path &cur_p) {
    CInterface::mCurrentPath = cur_p;
    initializeList();
}

void CInterface::initializeList() {
    mFileList.clear();
    for(const auto & itr : fs::directory_iterator(mCurrentPath)){
        if(fs::is_directory(itr) && !fs::is_symlink(itr))
        {
            CDirectory d(itr.path());
            mFileList.emplace_back(make_shared<CDirectory>(d));
        }
        else if(fs::is_symlink(itr.path()))
        {
            CSymLink l(itr.path());
            mFileList.emplace_back(make_shared<CSymLink>(l));
        }
        else if(fs::is_regular_file(itr))
        {
            CRegularFile r(itr.path());
            mFileList.emplace_back(make_shared<CRegularFile>(r));
        }
    }

}


const vector<shared_ptr<CFile>> &CInterface::getList() const {
    return mFileList;
}

