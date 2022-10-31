/**
 * Move class.
 * More detailed class description.
 */

#ifndef PA_2_CMOVE_H
#define PA_2_CMOVE_H

#include "CAction.h"

class CMove : public CAction{
private:
    fs::path pathFromMove;
public:
    /**
    * A  default constructor.
    */
    explicit CMove();
    /**
    * a member for move files using regex.
    * @param pInterface pointer to current interface.
    * @return result of action.
    */
    bool Do(CInterface *interface) override;
    /**
    * a member for choosing action if file exists.
    * @param existingPath existing path.
    * @return result of action.
    */
    bool DoSpecial(fs::path &existingPath) override;
};


#endif //PA_2_CMOVE_H
