#include "Contact.h"
#include "address.h"
#include "date.h"

#include <iostream>
#include <string.h>
#include <fstream>
#include <iomanip>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>



using namespace std;

void Contact::addContact() {
   cout<<"conID: ";
   cin>>conID;
   
   cout<<"FName: ";
   cin.ignore();
   cin>>FName;
   
   cout<<"LName: ";
   cin.ignore();
   cin>>LName;
   
   cout<<"Address: ";
   // cin.ignore();
   add.add2();
   
   cout<<"mobile: ";
   cin.ignore();
   cin>>mobile;

   cout<<"DoB: ";
   //cin.ignore();
   dd.dat();
   
   // conID++;
   cout<<"\n";
}

void Contact::ViewContact() 
{
   cout<<endl<<"ID #: "<<conID;
   cout<<endl<<"Phone #: "<<mobile;
   cout<<endl<<"FName: "<<FName;
   cout<<endl<<"LName: "<<LName;
   add.printadd();
   dd.printDoB();
}

void Contact::ConcUpdate(char *nm,char *telno)
{
   strcpy(FName,nm);
   strcpy(mobile,telno);
}
    
char* getPhone()
{
   return mobile;
}

int Contact::getid()
{
   return conID;
}