/**
 * File class.
 * More detailed class description.
 */
#ifndef PA_2_CFILE_H
#define PA_2_CFILE_H

#include <string>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <utility>
#include <cmath>
#include <experimental/filesystem>
#include <sys/types.h>
#include <sys/stat.h>

using namespace std;
namespace fs = experimental::filesystem;

class CFile {
private:
    fs::path mActualPath;
    uintmax_t mSize;
    string mName;
    string mType;
public:
    /**
    * A constructor.
    * @param rFilePath reference to path.
    * @param rType reference to type.
    */
    CFile(const fs::path& rFilePath, const string & rType);
    /**
    * A virtual constructor.
    */
    virtual ~CFile();
    /**
    * a getter of path.
    * @return the path.
    */
    fs::path getActualPath() const;
    /**
     * a getter of size.
     * @return the size.
    */
    virtual uintmax_t getSize() const;
    /**
     * a getter of size in human readable form.
     * @return the size in readable form.
    */
    virtual string getSizeHR() const;
    /**
     * a getter of name.
     * @return the name.
    */
    virtual string getName() const;
    /**
     * a getter of type.
     * @return the type.
    */
    virtual string getType() const;
    /**
     * member for printing output.
     * @param os reference to stream.
    */
    virtual void Print(ostream & os) const;
    /**
    * oveloaded operator for output.
    * @param os reference to stream.
    * @param parent reference to base class.
    * @return reference to stream.
   */
    friend ostream &operator<<(ostream &os, const CFile &parent);
};


#endif //PA_2_CFILE_H
