/**
 * Moving class.
 * More detailed class description.
 */

#ifndef PA_2_CMOVING_H
#define PA_2_CMOVING_H

#include "CAction.h"

class CMoving: public CAction {
private:
    CInterface* pFirst;
    CInterface* pSecond;
public:
    /**
    * a member for black magic updating all interfaces;
    * @param firstInt a current interface for update.
    * @param secondInt an another interface for update.
    */
    CMoving(CInterface *firstInt, CInterface *secondInt);
    /**
    * a member for moving in filesystem and updating regular and extended interfaces.
    * @param pInterface pointer to current interface.
    * @return result of action.
    */
    bool Do(CInterface *pInterface) override;
    /**
    * a member for black magic updating all interfaces;
    * @param pInter a current interface.
    * @param pAnotherInter an another interface.
    * @return result of action.
    */
    bool DoSpecial(fs::path &existingPath) override;

};


#endif //PA_2_CMOVING_H
