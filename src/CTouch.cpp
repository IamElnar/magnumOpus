#include "CTouch.h"

CTouch::CTouch() : CAction( ) {}

bool CTouch::Do(CInterface* interface) {
    int mod;
    string line;
    CExpander expander;
    cout << "Choose mod:\n"
            "0) One file with spaces in name.\n"
            "1) Multiple files without spaces in name." << endl;

    getline(cin, line);
    if (line.empty()) {
        return true;
    }
    if ((sscanf(line.c_str(), " %d", &mod) != 1) || mod < 0 || mod > 1 || line.size() != 1) {
        cout << "Choose the right number!" << endl;
        return false;
    }

    cout << "Enter the name(s):" << endl;
    string path;
    getline(cin, path);
    if (path.empty()) {
        return true;
    }

    vector<string> _mTokens;
    if (mod == 1) {
        separateInput(path);
        _mTokens = getMTokens();
    }
    else {
        _mTokens.push_back(path);
    }

    auto count = _mTokens.size();
    for (unsigned long i = 0; i < count; i++) {
        fs::path tmp(_mTokens[i]);
        fs::path par_p = _mTokens[i][0]== '/' ? tmp.parent_path() : interface->getCurrentPath();
        if (!checkExtinction(par_p) || !checkWritable(par_p)) {
            cout << "File doesn't exist or hasn't permissions!" << endl;
            return false;
        }

        string fileName = _mTokens[i][0] == '/' ? tmp.filename().c_str() : _mTokens[i];
        vector<string> names = expander.expand(fileName);

        for (const auto &name: names) {
            fs::path cur_p = par_p / name;
            if (checkExtinction(cur_p)) {
                while (!DoSpecial(cur_p));
                break;
            }
            ofstream newFile(cur_p.c_str());
            newFile.close();
        }
    }
    return true;
}

bool CTouch::DoSpecial(fs::path &existingPath) {
    cout << "File \"" << existingPath.filename() << "\" exists.\n What do you want to do?\n"
                                                    "0) Skip.\n"
                                                    "1) Rename.\n"
                                                    "2) Replace" << endl;
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
            cout << "Enter new name:" << endl;
            string newName;
            getline(cin,newName);
            if(newName.empty()) {
                return true;
            }
            fs:: path p = existingPath.parent_path() / newName;
            if (checkExtinction(p)) {
                cout << "Wrong name!" << endl;
            }
            else {
                ofstream newFile(p.c_str());
                newFile.close();
                return true;
            }
        }
    }
    else {
        const fs::path& p (existingPath);
        remove(p);
        ofstream newFile(existingPath.c_str());
        newFile.close();
        return true;
    }

}

