/**
 * Make directory class.
 * More detailed class description.
 */

#ifndef PA_2_CMAKEDIR_H
#define PA_2_CMAKEDIR_H

#include "CAction.h"

class CMakeDir : public CAction{
public:
    /**
    * A  default constructor.
    */
    explicit CMakeDir();
    /**
    * a member for creating directories with brace expansion.
    * @param pInterface pointer to current interface.
    * @return result of action.
    */
    bool Do(CInterface *interface)  override;
    /**
    * a member for choosing action if file exists.
    * @param existingPath existing path.
    * @return result of action.
    */
    bool DoSpecial(fs::path &existingPath) override;
};


#endif //PA_2_CMAKEDIR_H
