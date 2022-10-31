/**
 * Removing class.
 * More detailed class description.
 */

#ifndef PA_2_CREMOVE_H
#define PA_2_CREMOVE_H

#include "CAction.h"
#include "CFinder.h"

class CRemove : public CAction{
public:
    /**
    * A  default constructor.
    */
    explicit CRemove();
    /**
    * a member for removing files using regex.
    * @param pInterface pointer to current interface.
    * @return result of action.
    */
    bool Do(CInterface*interface)  override;
    /**
    * a member for secondary action.
    * @param existingPath existing path.
    * @return result of action.
    */
    bool DoSpecial(fs::path &existingPath) override;
};


#endif //PA_2_CREMOVE_H
