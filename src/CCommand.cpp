#include "CCommand.h"

CCommand::CCommand(CInterface *firstInt, CInterface *secondInt) {
    pInterface = firstInt;
    pExtInterface = secondInt;
    CMoving mv(pInterface, pExtInterface);
    mCommandList.emplace_back(make_shared<CMoving>(mv));
    mCommandList.emplace_back(make_shared<CTouch>());
    mCommandList.emplace_back(make_shared<CMakeDir>());
    mCommandList.emplace_back(make_shared<CLink>());
    mCommandList.emplace_back(make_shared<CRemove>());
    mCommandList.emplace_back(make_shared<CCopy>());
    mCommandList.emplace_back(make_shared<CMove>());
}

void CCommand::Do(States & rState) {
    string command;
    int num = 0;

    while (true) {
        getline(cin, command);
        if(cin.eof()) {
            rState = QUIT;
            return;
        }

        if(sscanf(command.c_str(), " %d", &num) != 1
            || ((rState == EXTENDED
            || rState == REGULAR) && (num < 0 || num > 9))
            || ((rState == HELP) && (num < 0 || num > 2))
            || command.size() != 1) {
            cout << "Choose the right number!" << endl;
            continue;
        }
        switch (num) {
            case 0 :
                rState = QUIT;
                break;
            case 1 :
                if(rState == REGULAR) {
                    rState = EXTENDED;
                    break;
                }
                else if(rState == EXTENDED) {
                    rState = REGULAR;
                    break;
                }
                else {
                    rState = REGULAR;
                    break;
                }
            case 2 :
                if(rState == HELP) {
                    rState = EXTENDED;
                    break;
                }
            default:
                if(rState == REGULAR) {
                    while (!mCommandList[num - 2]->Do(pInterface));    /**< Waiting for correct input.*/
                }
                else {
                    while (!mCommandList[num - 2]->Do(pExtInterface));   /**< Waiting for correct input.*/
                }
                break;
            case 9 :
                rState = HELP;
                break;
        }
        break;
    }
}
