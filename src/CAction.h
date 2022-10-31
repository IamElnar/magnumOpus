/**
 * Action class.
 * More detailed class description.
 */

#ifndef PA_2_CACTION_H
#define PA_2_CACTION_H

#include "CInterface.h"
#include "CExtendedInterface.h"
#include "CFinder.h"
#include "CExpander.h"
#include <unistd.h>
#include <fstream>
#include <map>

class CAction {
private:
    vector<string> mTokens;
    map<fs::path,int> mCounterFiles;
public:
    /**
    * A  default constructor.
    */
    explicit CAction();
    /**
    * A  default destructor.
    */
    virtual ~CAction();
    /**
    * a member for checking path extinction, taking 1 argument and returning bool value.
    * @param rCurrentPath a path argument.
    * @return The test results.
    */
     bool checkExtinction(const fs::path & rCurrentPath) const;
    /**
    * a member for checking read permission, taking 1 argument and returning bool value.
    * @param rCurrentPath a path argument.
    * @return The test results.
    */
     bool checkReadable(const fs::path & rCurrentPath) const;
    /**
    * a member for checking write permission, taking 1 argument and returning bool value.
    * @param rCurrentPath a path argument.
    * @return The test results.
    */
     bool checkWritable(const fs::path & rCurrentPath) const;
    /**
    * a member for checking execute permissiion, taking 1 argument and returning bool value.
    * @param rCurrentPath a path argument.
    * @return The test results.
    */
     bool checkExecutable(const fs::path & rCurrentPath) const;
    /**
    * a normal member for splitting string.
    * @param rPath a string argument.
    */
    void separateInput(const string& rPath);
    /**
    * a member for main action.
    * @param pInterface pointer to current interface.
    * @return result of action.
    */
    virtual bool Do(CInterface *pInterface) = 0;
    /**
    * a member for secondary actions.
    * @param pInterface pointer to current path.
    * @return result of action.
    */
    virtual bool DoSpecial(fs :: path &existingPath) = 0;
    /**
    * getter for separated words.
    */
    const vector<string> &getMTokens() const;
};


#endif //PA_2_CACTION_H
