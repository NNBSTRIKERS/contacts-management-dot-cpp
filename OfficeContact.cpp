#include "OfficeContact.h"

#include <iostream>
#include <string.h>
#include <fstream>
#include <iomanip>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

// Include other necessary headers

using namespace std;

void OfficeContact::addOfficeContact() 
{
    cout<<"Design: ";
    cin.ignore();
    cin>>Design;

    cout<<"OffName: ";
    cin.ignore();
    cin>>OfficeName;
    
    cout<<"OffAddress:-"<<endl;
    cin.ignore();
    ofcadd.add2();
}

void OfficeContact::ViewOfficeContact() 
{
    cout<<endl<<"Design: "<<Design<<endl;
    cout<<endl<<"OfficeName: "<<OfficeName<<endl;
    ofcadd.printadd();
}
