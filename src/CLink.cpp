#include "CLink.h"

CLink::CLink( ) : CAction() {detector = false;}

bool CLink::Do(CInterface *interface)  {
    bool autoLinks = true;

    cout << "Enter the file and link." << endl;
    string path;
    getline(cin, path);
    if (path.empty())
    {
        return true;
    }

    separateInput(path);
    vector<string> _mTokens = getMTokens();
    if(_mTokens.size() > 2)
    {
        cout << "Command does not have 1 or 2 arguments!";
        return false;
    }

    if(_mTokens.size() == 2)
        autoLinks = false;

    string targetName = _mTokens[0];
    string linkName = _mTokens.size() == 1 ? targetName + "_link" : _mTokens[1];
    fs::path target_p = targetName[0] == '/' ? targetName.c_str() : interface->getCurrentPath()/targetName;
    fs::path dest_p = linkName[0] == '/' ? linkName.c_str() : interface->getCurrentPath()/linkName;
    if(!checkExtinction(target_p.parent_path())) {
        cout << "File doesn't exist or hasn't permissions!" << endl;
        return false;
    }
    if(!checkExtinction(dest_p.parent_path()) || !checkWritable(dest_p.parent_path())) {
        cout << "File doesn't exist or hasn't permissions!" << endl;
        return false;
    }

    CFinder finder;
    int counter = 0;
    for(const auto & file : fs::directory_iterator(target_p.parent_path())){
        if(counter == 1)
            break;
        if(finder.checkMatch(file.path().filename(), target_p.filename()))
        {
            fs::path destination;
            if(autoLinks){
                string autoName(file.path().filename().native() + "_link");
                destination = target_p.parent_path()/autoName;
            }
            else{
                destination = dest_p;
                counter++;
            }
            if (checkExtinction(destination))
            {
                while (!DoSpecial(destination));
                if(detector)                       /**< Flag for skipping existing file.*/
                {
                    detector = false;
                    break;
                }
            }
            if(fs::is_directory(file))
                fs::create_directory_symlink(file,destination);
            else
                fs::create_symlink(file,destination);
        }
    }
    return true;
}

bool CLink::DoSpecial(fs::path &existingPath) {
    cout << "File \"" << existingPath.filename() << "\" exists.\n What do you want to do?\n"
                                                    "0) Skip.\n"
                                                    "1) Rename.\n"
                                                    "2) Replace" << endl;
    int mod;
    string line;
    getline(cin,line);
    if(line.empty())
    {
        return true;
    }
    if((sscanf(line.c_str()," %d",&mod) != 1) || mod < 0 || mod > 2 || line.size() != 1)
    {
        cout << "Choose the right number!" << endl;
        return false;
    }
    if(mod == 0)
    {
        detector = true;
        return true;
    }
    else if(mod == 1){
        while(true){
            cout << "Enter new name:" << endl;
            string newName;
            getline(cin,newName);
            if(newName.empty())
            {
                return true;
            }
            fs:: path p = existingPath.parent_path() / newName;
            if (checkExtinction(p)){
                cout << "Wrong name!" << endl;
            }
            else{
                return true;
            }
        }
    }
    else
    {
        const fs::path& p (existingPath);
        remove(p);
        return true;
    }

}

