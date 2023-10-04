#include <iostream>
#include <string.h>
#include <fstream>
#include <iomanip>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>


#include "Contact.h"
#include "OfficeContact.h"
#include "date.h"
#include "address.h"


using namespace std;

int main() 
{
    system("cls");
   
   Contact gh;
   
   OfficeContact bn;
 
    fstream file;
  
    char ch,nm[20],telno[6];
    int choice,found=0;
    
    
    for(;;)
    {
		    int nn;
    cout<<"\n\t **** Welcome to Contact Management System ****";
    cout<<"\n\n\n\t\t\tMAIN MENU\n\t\t=====================\n\t\t NORMAIL DETAILS:\n\t\t[1] Add a new Contact\n\t\t[2] List all Contacts\n\t\t[3] Search for contact\n\t\t[4] Edit a Contact\n\t\t[5] Delete a Contact\n\t\t\n\t\t OFFICE DETAILS:\n\t\t[6] Add a new OFFICE Contact\n\t\t[7] List all OFFICE Contacts\n\t\t[8] Search for OFFICE contact\n\t\t[9] Edit an OFFICE Contact\n\t\t[10] Delete an OFFICE Contact\n\t\t\n\t\t\n\t\t[0] Exit\n\t\t=================\n\t\t";
    cout<<"Enter the choice:";
 
    cin>>nn;
 
    switch(nn)
    {
    	case 0: cout<<"\n\n\t\tThank you for using CMS...";
    		exit(0);
    			break;
       
      //ADD NORMAL_CONCT_DETAILS
    	case 1: 
    	
    		file.open("files\address.txt", ios::ate | ios::in | ios::out );
			gh.addContact();
    	   cin.get(ch);
        	file.write((char *) &gh, sizeof(gh));
        	file.close();
        
    		break;
    		
    	case 2:

         file.open("files\address.txt", ios::ate | ios::in | ios::out );
         file.seekg(0,ios::beg);
            cout<<"\n\nRecords in Book\n";
            while(file)
            {
               file.read((char *) &gh, sizeof(gh));
               if(!file.eof())
                  gh.ViewContact();
            }
            file.clear();
            getch();
         file.close();

    		break;

   	case 3:
		    //Search Tel. no. when person name is known.
         file.open("files\address.txt", ios::ate | ios::in | ios::out );
            cout<<"\n\nEnter Name : ";
            cin>>nm;
         file.seekg(0,ios::beg);
            found=0;
            while(file.read((char *) &gh, sizeof(gh)))
            {
               if(strcmp(nm,gh.getname())==0)
               {
                  found=1;
                  gh.ViewContact();
               }
            }
         file.clear();
            if(found==0)
               cout<<"\n\n---Record Not found---\n";
            getch();
         file.close();
            break;
			
    		break;
    	case 4: //Update Telephone No.
    	{
		
         file.open("files\address.txt", ios::ate | ios::in | ios::out );
            cout<<"\n\nEnter mobile no : ";
            cin>>nm;
         file.seekg(0,ios::beg);
            found=0;
            int cnt=0;
            while(file.read((char *) &gh, sizeof(gh)))
            {
               cnt++;
               if(strcmp(nm,gh.getphno())==0)
               {
                  found=1;
                  break;
               }
            }
         file.clear();
            if(found==0)
               cout<<"\n\n---Record Not found---\n";
            else
            {
               int location = (cnt-1) * sizeof(gh);
               cin.get(ch);
               if(file.eof())
                  file.clear();

               cout<<"Enter New Telephone No : ";
               cin>>telno;
               file.seekp(location);
               gh.ConcUpdate(nm,telno);
               file.write((char *) &gh, sizeof(gh));
               file.flush();
            }
         file.close();
            break;
             
      }
    		
    	case 5:
    		{
    			fstream fp2;
    			int num;
				system("cls");
				cout<<endl<<endl<<"Please Enter The contact #: ";
				cin>>num;
				//fp.open("contactBook.dat",ios::in|ios::out);
				file.open("files\address.txt", ios::in | ios::out );
				//fstream fp2;
				fp2.open("files\temp.txt",ios::out);
				file.seekg(0,ios::beg);
				while(file.read((char*)&gh,sizeof(gh)))
					{
						if(gh.getid()!=num)
						{
						fp2.write((char*)&gh,sizeof(gh));
						}
					}
						fp2.close();
						file.close();
					remove("files\address.txt");
					   //rename("\\temp.txt","\\address.txt");
					if(rename("files\temp.txt","files\address.txt") != 0)
						perror("Error renaming file");
					else
						cout << "File renamed successfully";
					cout<<endl<<endl<<"\tContact Deleted...";
    		}
    		break;
    	
      //OFFICE DETAILS CORRECTIONS
   
		case 6:		
			//ADDIND OF OFFICE_CONCT_DETAILS	
					file.open("files\address.txt", ios::ate | ios::in | ios::out );
					bn.addOfficeContact();
    	    		cin.get(ch);
        			file.write((char *) &bn, sizeof(bn));
        			file.close();
      		break;
				
		case 7:
    		 
    		 file.open("files\address.txt", ios::ate | ios::in | ios::out );
			 file.seekg(0,ios::beg);
                 cout<<"\n\nRecords in Book\n";
                 while(file){
                    file.read((char *) &bn, sizeof(bn));
                    if(!file.eof())
                        bn.ViewOfficeContact();
                 }
                 file.clear();
                 getch();
                 file.close();
    		break;
    		
   	case 8:
		    //Search Tel. no. when person name is known.
		    	 file.open("files\address.txt", ios::ate | ios::in | ios::out );
                 cout<<"\n\nEnter Name : ";
                 cin>>nm;
                 file.seekg(0,ios::beg);
                 found=0;
                 while(file.read((char *) &bn, sizeof(bn)))
                 {
                    if(strcmp(nm,bn.getname())==0)
                    {
                        found=1;
                        bn.ViewOfficeContact();
                    }
                 }
                 file.clear();
                 if(found==0)
                    cout<<"\n\n---Record Not found---\n";
                 getch();
                 file.close();
                 break;
			
    		break;
    		
    	case 9: //Update Telephone No.
		
    			file.open("files\address.txt", ios::ate | ios::in | ios::out );
            cout<<"\n\nEnter mobile no : ";
                 cin>>nm;
                 file.seekg(0,ios::beg);
                 found=0;
                 int cnt=0;
                 while(file.read((char *) &bn, sizeof(bn)))
                 {
                    cnt++;
                    if(strcmp(nm,bn.getphno())==0)
                    {
                        found=1;
                        break;
                    }
                 }
                 file.clear();
                 if(found==0)
                    cout<<"\n\n---Record Not found---\n";
                 else
                 {
                    int location = (cnt-1) * sizeof(bn);
                    cin.get(ch);
                    if(file.eof())
                        file.clear();

                    cout<<"Enter New Telephone No : ";
                    cin>>telno;
                    file.seekp(location);
                    bn.ConcUpdate(nm,telno);
                    file.write((char *) &bn, sizeof(bn));
                    file.flush();
                 }
                 file.close();
                 break;
    		
    	case 10:
    		{
			   
    			fstream fp2;
    			int num;
				system("cls");
				cout<<endl<<endl<<"Please Enter The contact #: ";
				cin>>num;
				//fp.open("contactBook.dat",ios::in|ios::out);
				file.open("files\address.txt", ios::in | ios::out );
				//fstream fp2;
				fp2.open("files\temp.txt",ios::out);
				file.seekg(0,ios::beg);
				while(file.read((char*)&bn,sizeof(bn)))
					{
						if(bn.getid()!=num)
						{
						fp2.write((char*)&bn,sizeof(bn));
						}
					}
						fp2.close();
						file.close();
					remove("files\address.txt");
					//rename("D:\\temp.txt","D:\\address.txt");
					if(rename("files\temp.txt","files\address.txt") != 0)
						perror("Error renaming file");
					else
						cout << "File renamed successfully";
					cout<<endl<<endl<<"\tContact Deleted...";
    		}
    		break;
    			
    	default:
    		break;
    }
   
}
 return 0;
}
