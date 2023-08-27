#include "date.h"
#include <iostream>
#include <string.h>
#include <fstream>
#include <iomanip>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void date::dat() 
{
        cout<<"day: ";
        cin.ignore();
        cin>>day;
                
        cout<<"month: ";
        cin.ignore();
        cin>>month;
                
        cout<<"year: ";
        cin.ignore();
        cin>>year;
}

void date::printDoB(void) 
{
        cout<<"day: "<<day<<endl;
        cout<<"month: "<<month<<endl;
        cout<<"year: "<<year<<endl;
}