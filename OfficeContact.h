#ifndef OFFICECONTACT_H
#define OFFICECONTACT_H

#include "address.h"

class OfficeContact 
{
    private:
        address ofcadd; 
        char Design[100], OfficeName[10], OfficeAddr[30];

    public:
        // Member functions declarations
        void addOfficeContact();
        void ViewOfficeContact();
};

#endif // OFFICECONTACT_H
