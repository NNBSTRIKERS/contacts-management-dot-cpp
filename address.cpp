#include "address.h"
#include <iostream>

using namespace std;

void address::add2(void)
{
    cout<<"BldgNum: ";
    cin>>BldgNum;
    
    cout<<"StreetName: ";
    cin.ignore();
    cin>>StreetName;
    
    cout<<"city: ";
    cin.ignore();
    cin>>city;

    cout<<"PIN: ";
    cin.ignore();
    cin>>PIN;
}
        
void address::printadd(void)
{
    cout<<"BldgNum: "<<BldgNum<<endl;
    cout<<"StreetName: "<<StreetName<<endl;
    cout<<"city: "<<city<<endl;
    cout<<"PIN: "<<PIN<<endl;
}