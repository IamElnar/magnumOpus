/**
 * Directory class.
 * More detailed class description.
 */

#ifndef PA_2_CDIRECTORY_H
#define PA_2_CDIRECTORY_H

#include "CFile.h"
#include <dirent.h>
#include <unistd.h>

class CDirectory : public CFile{
private:
    int mCountOfFiles;
public:
    /**
    * A constructor.
    * @param name name of the file.
    */
    CDirectory(const fs::path &name);
    /**
    * member for printing output.
    * @param os reference to stream.
    */
    void Print(ostream&os)const override;
    /**
    * member for counting files in directory..
    * @param name name of the directory.
    */
    void countFiles(const fs::path &name);
    /**
    * A member for return files in directory.
    */
    int getCountOfFiles() const;
};


#endif //PA_2_CDIRECTORY_H
