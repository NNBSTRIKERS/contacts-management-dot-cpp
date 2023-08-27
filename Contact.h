#ifndef CONTACT_H
#define CONTACT_H

#include "address.h"
#include "date.h"

class Contact 
{
    private:
        address add; 
        date dd;
        char FName[20],LName[20],mobile[10];

    public:
        // Member functions declarations
        int conID=0;
        char *getname(){ return FName; }
        char *getphno(){ return mobile; }

        void addContact();
        void ViewContact();
        void ConcUpdate(char *nm,char *telno);
        int getid();
};

#endif // CONTACT_H
