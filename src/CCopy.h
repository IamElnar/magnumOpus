/**
 * Copy class.
 * More detailed class description.
 */

#ifndef PA_2_CCOPY_H
#define PA_2_CCOPY_H

#include "CAction.h"

class CCopy : public  CAction{
private:
    fs::path pathFromCopy;
public:
    /**
    * A  default constructor.
    */
    explicit CCopy();
    /**
    * a member for copy using regex.
    * @param pInterface pointer to current interface.
    */
    bool Do(CInterface *interface)  override;
    /**
   * a member for choosing action if target file exists.
   * @param existingPath existing path.
   * @return result of action.
   */
    bool DoSpecial(fs::path &existingPath) override;
};


#endif //PA_2_CCOPY_H
