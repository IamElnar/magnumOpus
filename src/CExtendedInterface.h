/**
 * Extended interface class.
 * More detailed class description.
 */

#ifndef PA_2_CEXTENDEDINTERFACE_H
#define PA_2_CEXTENDEDINTERFACE_H

#include "CInterface.h"
#include <ctime>
#include <sys/types.h>
#include <sys/stat.h>
#include <cerrno>
#include <cstring>
#include <chrono>
#include <iomanip>

class CExtendedInterface : public CInterface {
private:
    struct stat fileInfo;
public:
    /**
   * A  default constructor.
   */
    CExtendedInterface();
    /**
   * a member for showing files.
   */
    void Show()  override;
};


#endif //PA_2_CEXTENDEDINTERFACE_H
