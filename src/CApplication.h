/**
 * Application class.
 * More detailed class description.
 */

#ifndef PA_2_CAPPLICATION_H
#define PA_2_CAPPLICATION_H

#include "CInterface.h"
#include "CHelpingInterface.h"
#include "CExtendedInterface.h"
#include "CCommand.h"

class CApplication {
private:
    CHelpingInterface mMenu;                         /**< mMenu mInterface. */
    CInterface mInterface;                           /**< main mInterface. */
    CExtendedInterface mExtendedInterface;           /**< extended mInterface. */
    vector<shared_ptr<CInterface>> mInterfaces;
    CCommand *pCommander;
    States mState;
public:
    /**
     * A  default constructor.
    */
    CApplication();
    /**
     * A  default destructor.
    */
    virtual ~CApplication();
    /**
     * A member which run the app.
    */
    void run();
};


#endif //PA_2_CAPPLICATION_H
