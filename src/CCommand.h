/**
 * Copy class.
 * More detailed class description.
 */

#ifndef PA_2_CCOMMAND_H
#define PA_2_CCOMMAND_H

#include "CInterface.h"
#include "CExtendedInterface.h"
#include "CAction.h"
#include "CMoving.h"
#include "CRemove.h"
#include "CMakeDir.h"
#include "CLink.h"
#include "CCopy.h"
#include "CTouch.h"
#include "CMove.h"

class CCommand {
private:
    CInterface* pInterface;
    CInterface* pExtInterface;
    vector<shared_ptr<CAction>> mCommandList;
public:
    /**
    * A  default constructor.
    */
    CCommand(CInterface *firstInt, CInterface *secondInt);
    /**
     * a member for input reading.
     * @param pInter pointer to current interface.
     * @param pExtInterInter pointer to another interface.
     * @param rState reference to current state.
     */
    void Do(States & rState);
};


#endif //PA_2_CCOMMAND_H
