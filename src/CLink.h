/**
 * Link class.
 * More detailed class description.
 */

#ifndef PA_2_CLINK_H
#define PA_2_CLINK_H

#include "CAction.h"

class CLink : public CAction{
private:
    bool detector;
public:
    /**
    * A  default constructor.
    */
    explicit CLink();
    /**
    * a member for creating symlinks.
    * for 1 argument member creates links automatically. Can be used with regex.
    * for 2 arguments source -> link name.
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


#endif //PA_2_CLINK_H
