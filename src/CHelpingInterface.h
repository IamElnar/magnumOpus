/**
 * Helping interface class.
 * More detailed class description.
 */

#ifndef PA_2_CHELPINGINTERFACE_H
#define PA_2_CHELPINGINTERFACE_H

#include "CInterface.h"

class CHelpingInterface : public CInterface{
public:
    /**
    * A  default constructor.
    */
    CHelpingInterface();
    /**
    * a member for showing files.
    */
    void Show()  override;
};


#endif //PA_2_CHELPINGINTERFACE_H
