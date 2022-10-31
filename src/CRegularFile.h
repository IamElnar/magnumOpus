/**
 * Regular file class.
 * More detailed class description.
 */

#ifndef PA_2_CREGULARFILE_H
#define PA_2_CREGULARFILE_H

#include "CFile.h"

class CRegularFile : public CFile{
public:
    /**
    * A constructor
    * @param rPath reference to path
    */
    CRegularFile( const fs::path &rPath);
};


#endif //PA_2_CREGULARFILE_H
