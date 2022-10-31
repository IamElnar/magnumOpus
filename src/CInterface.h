/**
 * Interface class.
 * More detailed class description.
 */

#ifndef PA_2_CINTERFACE_H
#define PA_2_CINTERFACE_H

#include "CFile.h"
#include "CDirectory.h"
#include "CRegularFile.h"
#include "CSymLink.h"
#include "CStates.h"

class CInterface {
private:
    fs::path mCurrentPath;
    vector<shared_ptr<CFile>> mFileList;
public:
    /**
    * A  default constructor.
    */
    CInterface();
    /**
    * A  virtual destructor.
    */
    virtual ~CInterface();
    /**
    * a member for showing files.
    */
    virtual void Show();
    /**
    * a member for update vector of files.
    */
    virtual void initializeList();
    /**
    * a getter of current Path
     * @return current path.
    */
    fs::path getCurrentPath()const;
    /**
    * a setter of current Path
     * @param currentPath new path.
     */
    void setCurrentPath(const fs::path &currentPath);
    /**
     * a getter of reference of vector.
    * @return reference of vector.
     */
    const vector<shared_ptr<CFile>> & getList() const ;
};



#endif //PA_2_CINTERFACE_H
