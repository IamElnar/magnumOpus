#include "CRemove.h"

CRemove::CRemove() : CAction() {}

bool CRemove::Do(CInterface* interface)  {
    CFinder finder;

    cout << "Choose files" << endl;
    string path;
    getline(cin, path);
    if (path.empty())
    {
        return true;
    }
    separateInput(path);
    vector<string> _mTokens = getMTokens();

    for(const auto& word : _mTokens) {
        fs::path pathToDelete = word[0] == '/' ? word.c_str() : interface->getCurrentPath()/word;
        if (!checkExtinction(pathToDelete.parent_path())
        || !checkReadable(pathToDelete.parent_path())
        || !checkWritable(pathToDelete.parent_path())
        ||(fs::is_directory(pathToDelete.parent_path()) && !checkExecutable(pathToDelete.parent_path()))) {
            cout << "File doesn't exist or hasn't permissions!" << endl;
            return false;
        }
        for(const auto&f: fs:: directory_iterator(pathToDelete.parent_path())) {
            if(finder.checkMatch(f.path().filename(),pathToDelete.filename().c_str())) {
                remove_all(f.path());
            }
        }
    }
    return true;
}

bool CRemove::DoSpecial(fs::path &existingPath) {
    return false;
}
