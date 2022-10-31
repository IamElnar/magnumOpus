#include "CHelpingInterface.h"




void CHelpingInterface::Show()  {
    cout << "======================================================================================================\n";
    cout <<setw(20) << left << "Name" << setw(40) << left << "Description" << setw(30) <<left << "Synopsis" << "\n";
    cout << "======================================================================================================\n";
    cout <<setw(20) << left<< "Quit" <<setw(40) << left << "Exit from the program" <<"\n"
         <<setw(20) << left<< "Change mode" << setw(40) << left << "Change regular/extended mode" <<"\n"
         <<setw(20) << left<< "Change dir" << setw(40) << left << "Change directory" <<setw(30) <<left<< "[destination] | [..] - go back" <<"\n"
         <<setw(20) << left<< "Create file" << setw(40) << left << "Creation of regular file" <<setw(30) <<left<< "[files]" <<"\n"
         <<setw(20) << left<< "Mkdir" << setw(40) << left << "Make a directory" <<setw(30) <<left<< "[directory]" <<"\n"
         <<setw(20) << left<< "Create link" << setw(40) << left << "Creation of symlink" <<setw(30) <<left<< "[target] [link name]" <<"\n"
         <<setw(20) << left<< "Remove" << setw(40) << left << "Remove file" <<setw(30) <<left<< "[target]" <<"\n"
         <<setw(20) << left<< "Copy file" << setw(40) << left << "Copy file to destination" <<setw(30) <<left<< "[target] [destination]" <<"\n"
         <<setw(20) << left<< "Move" << setw(40) << left << "Move file to destination" <<setw(30) <<left<< "[from] [to]" <<"\n"
         <<setw(20) << left<< "Help" << setw(40) << left << "Call help" <<"\n";
    cout << "======================================================================================================\n";
    cout <<"0:Quit\t1:Regular\t2:Extended\n"
           "Enter command:\n";
}

CHelpingInterface::CHelpingInterface() :CInterface(){}





