#include "CApplication.h"

CApplication::CApplication() {
    mInterfaces.emplace_back((make_shared<CInterface>()));                                    /**< Adding to vector of smart pointers. */
    mInterfaces.emplace_back((make_shared<CHelpingInterface>()));
    mInterfaces.emplace_back((make_shared<CExtendedInterface>()));
    pCommander =  new CCommand(mInterfaces[0].get(), mInterfaces[2].get());
    mState = REGULAR;                                                                         /**< Initial State.*/
}

CApplication::~CApplication() {
    delete pCommander;
}

void CApplication::run() {
    while(true) {
        mInterfaces.at(mState)->Show();
        pCommander->Do(mState);
        if(mState == QUIT) {
            break;
        }
    }
}


