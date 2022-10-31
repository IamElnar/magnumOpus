/**
 * Symbolic link class.
 * More detailed class description.
 */

#ifndef PA_2_CSYMLINK_H
#define PA_2_CSYMLINK_H

#include "CFile.h"

class CSymLink : public CFile{
public:
    /**
   * A constructor
   * @param rPath reference to path
   */
    CSymLink(const fs::path &name);
};


#endif //PA_2_CSYMLINK_H
