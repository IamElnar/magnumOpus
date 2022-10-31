#include "CExtendedInterface.h"

CExtendedInterface::CExtendedInterface() : CInterface(){}

void CExtendedInterface::Show()  {
    initializeList();
    fs::path _currentPath = getCurrentPath();

    cout << "===========================================================================================\n";
    cout << "Current location: " << _currentPath  << endl;
    cout << "===========================================================================================\n";
    cout <<left <<setw(40)<< "Name" << setw(10) << "Type" << setw(20)<< "Size"  << "Modify time\n";
    cout << "===========================================================================================\n";
    for(const auto& f: getList()){
        stat(f->getActualPath().c_str(), &fileInfo);
        cout << *f << ctime(&fileInfo.st_ctime) ;
    }
    cout << "===========================================================================================\n";
    cout << "0:Quit \t1:Change Mode\t2:Change dir \t3:Create file\n"
            "4:Mkdir\t5:Create link\t6:Remove file\t7:Copy file  \n"
            "8:Move \t9:Help\n";
    cout << "Enter command:\n";
}




