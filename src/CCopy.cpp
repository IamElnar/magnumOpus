#include "CCopy.h"

CCopy::CCopy() : CAction( ) {}

bool CCopy::Do(CInterface *interface) {
    CFinder finder;
    cout << "Choose the file and final destination:" << endl;

    string path;
    getline(cin, path);
    if (path.empty()) {
        return true;
    }

    separateInput(path);
    vector<string> _mTokens = getMTokens();
    if (_mTokens.size() != 2) {
        cout << "Command does not have 2 arguments!";
        return false;
    }

    string from = _mTokens[0];
    string to = _mTokens[1];
    fs::path source_p = from[0] == '/' ? from.c_str() : interface->getCurrentPath() / from;
    fs::path dest_p = to[0] == '/' ? to.c_str() : interface->getCurrentPath() / to;

    if (!checkExtinction(source_p.parent_path()) || !checkReadable(source_p.parent_path())) {
        cout << "File doesn't exist or hasn't permissions!" << endl;
        return false;
    }
    if (!checkExtinction(dest_p) || !checkWritable(dest_p)) {
        cout << "File doesn't exist or hasn't permissions!" << endl;
        return false;
    }
    if(!fs::is_directory(dest_p)){
        cout << "Target is not a directory!" << endl;
        return false;
    }

    for (const auto &f: fs::directory_iterator(source_p.parent_path())) {
        if (finder.checkMatch(f.path().filename().c_str(),
                              source_p.filename().c_str())) {     /**< Going through directory to find pattern for regular rule.*/
            if (checkExtinction(dest_p/f.path().filename())) {
                pathFromCopy = f;
                auto tmp = dest_p/f.path().filename();
                while (!DoSpecial(tmp));
            }
            else{
                const auto copyOptions = fs::copy_options::recursive
                                         | fs::copy_options::copy_symlinks;
                auto tmp = dest_p/f.path().filename();
                fs::copy(f, tmp, copyOptions);
            }
        }
    }
    return true;
}
bool CCopy::DoSpecial(fs::path &existingPath) {
    cout << "File \"" << existingPath.filename() << "\" exists.\n What do you want to do?\n"
                                                    "0) Skip.\n"
                                                    "1) Rename.\n"
                                                    "2) Replace." << endl;
    int mod;
    string line;
    getline(cin,line);
    if(line.empty()) {
        return true;
    }
    if((sscanf(line.c_str()," %d",&mod) != 1) || mod < 0 || mod > 2 || line.size() != 1) {
        cout << "Choose the right number!" << endl;
        return false;
    }
    if(mod == 0) {
        return true;
    }
    else if(mod == 1) {
        while(true) {
            cout << "Enter new name." << endl;
            string newName;
            getline(cin,newName);
            if(newName.empty()) {
                return true;
            }
            fs:: path p = existingPath.parent_path() / newName;
            if (checkExtinction(p)) {
                cout << "Wrong name!" << endl;
            }
            else{
                const auto copyOptions =   fs::copy_options::recursive
                                         | fs::copy_options::copy_symlinks;
                fs::copy(pathFromCopy, p,copyOptions);
                return true;
            }
        }
    }
    else {
        const auto copyOptions = fs::copy_options::overwrite_existing
                               | fs::copy_options::recursive
                               | fs::copy_options::copy_symlinks;
        fs::copy(pathFromCopy, existingPath,copyOptions);
        return true;
    }
}
