/**
 * Creating files class.
 * More detailed class description.
 */

#ifndef PA_2_CTOUCH_H
#define PA_2_CTOUCH_H

#include "CAction.h"

class CTouch : public  CAction{
public:
    /**
    * A  default constructor.
    */
    explicit CTouch();
    /**
    * a member for creating files with simple brace expansion.
    * @param pInterface pointer to current interface.
    * @return result of action.
    */
    bool Do(CInterface* inter)  override;
    /**
    * a member for choosing action if file exists.
    * @param existingPath existing path.
    * @return result of action.
    */
    bool DoSpecial(fs::path &existingPath) override;
};


#endif //PA_2_CTOUCH_H
