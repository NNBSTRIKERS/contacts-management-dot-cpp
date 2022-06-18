#include<fstream>
#include<conio.h>
#include<string.h>
#include<iomanip>
#include<iostream>
 
using namespace std;


 class address 
 {
 	private:
 	int PIN;
 	char BldgNum[10], StreetName[30],city[20];
	
		public:
	 
 	void add2(void)
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
        
        void printadd(void)
		{
			cout<<"BldgNum: "<<BldgNum<<endl;
			cout<<"StreetName: "<<StreetName<<endl;
			cout<<"city: "<<city<<endl;
			cout<<"PIN: "<<PIN<<endl;
		}
        
    
};

 
 class date{
 	private:
	 int day, year;
 	 char  month[10];
 	
public:
	
 	void dat()
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
    
      void printDoB(void)
		{
			cout<<"day: "<<day<<endl;
			cout<<"month: "<<month<<endl;
			cout<<"year: "<<year<<endl;
		}
 };
 

 
//NORMAL DETAILS RELATED CLASS&FUNC 
class contact 
{
	private:
      address add; 
      date dd;
      char FName[20],LName[20],mobile[10];
      
    
	
	public:
      int conID=0;
      char *getname(){ return FName; }
      char *getphno(){ return mobile; }

	
   void addcontact()
	{
            		
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
	
	
	void Viewcontact()
	{
		cout<<endl<<"ID #: "<<conID;
		cout<<endl<<"Phone #: "<<mobile;
		cout<<endl<<"FName: "<<FName;
		cout<<endl<<"LName: "<<LName;
		add.printadd();
		dd.printDoB();
		
	
	}
	
    
   void update(char *nm,char *telno)
   {
      strcpy(FName,nm);
      strcpy(mobile,telno);
   }
    
   char* getPhone()
	{
		return mobile;
	}

	int getid()
	{
		return conID;
	}
};
 

//OFFICE RELATED CLASS&FUNC 
class Offcontact
{
	address ofcadd; 
	char Design[100], OfficeName[10], OfficeAddr[30];
	
	public:
		
	void addOffContact()
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

void ViewOffcontact()
	{
		cout<<endl<<"Design: "<<Design<<endl;
		cout<<endl<<"OfficeName: "<<OfficeName<<endl;
    	ofcadd.printadd();
	
	}



};
	
 


 
int main()
{
   system("cls");
   
   contact gh;
   
   Offcontact bn;
 
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
    			
       
       //NORMAL DETAILS CORRECTION
       
       
    	case 1: 
    	//ADDIND OF NORMAL_CONCT_DETAILS
    		file.open("D:\\address.txt", ios::ate | ios::in | ios::out );
			gh.addcontact();
    	    cin.get(ch);
        	file.write((char *) &gh, sizeof(gh));
        	file.close();
        
    		break;
    		
    	case 2:
    		 
    		 file.open("D:\\address.txt", ios::ate | ios::in | ios::out );
			 file.seekg(0,ios::beg);
                 cout<<"\n\nRecords in Book\n";
                 while(file){
                    file.read((char *) &gh, sizeof(gh));
                    if(!file.eof())
                        gh.Viewcontact();
                 }
                 file.clear();
                 getch();
                 file.close();
    		break;
   	case 3:
		    //Search Tel. no. when person name is known.
		    	 file.open("D:\\address.txt", ios::ate | ios::in | ios::out );
                 cout<<"\n\nEnter Name : ";
                 cin>>nm;
                 file.seekg(0,ios::beg);
                 found=0;
                 while(file.read((char *) &gh, sizeof(gh)))
                 {
                    if(strcmp(nm,gh.getname())==0)
                    {
                        found=1;
                        gh.Viewcontact();
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
		
    			file.open("D:\\address.txt", ios::ate | ios::in | ios::out );
                 cout<<"\n\nEnter mobile no : ";
                 cin>>nm;
                 file.seekg(0,ios::beg);
                 found=0;
                 int cnt=0;
                 while(file.read((char *) &gh, sizeof(gh)))
                 {
                    cnt++;
                    if(strcmp(nm,gh.getPhone())==0)
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
                    gh.update(nm,telno);
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
				file.open("D:\\address.txt", ios::in | ios::out );
				//fstream fp2;
				fp2.open("D:\\temp.txt",ios::out);
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
					remove("D:\\address.txt");
					//rename("D:\\temp.txt","D:\\address.txt");
					if(rename("D:\\temp.txt","D:\\address.txt") != 0)
						perror("Error renaming file");
					else
						cout << "File renamed successfully";
					cout<<endl<<endl<<"\tContact Deleted...";
    		}
    		break;
    	
    	//OFFICE DETAILS CORRECTIONS
    	
    	
		case 6:		
			//ADDIND OF OFFICE_CONCT_DETAILS	
					file.open("D:\\address.txt", ios::ate | ios::in | ios::out );
					bn.addOffContact();
    	    		cin.get(ch);
        			file.write((char *) &bn, sizeof(bn));
        			file.close();
      		break;
				
		case 7:
    		 
    		 file.open("D:\\address.txt", ios::ate | ios::in | ios::out );
			 file.seekg(0,ios::beg);
                 cout<<"\n\nRecords in Book\n";
                 while(file){
                    file.read((char *) &bn, sizeof(bn));
                    if(!file.eof())
                        bn.ViewOffcontact();
                 }
                 file.clear();
                 getch();
                 file.close();
    		break;
    		
   	case 8:
		    //Search Tel. no. when person name is known.
		    	 file.open("D:\\address.txt", ios::ate | ios::in | ios::out );
                 cout<<"\n\nEnter Name : ";
                 cin>>nm;
                 file.seekg(0,ios::beg);
                 found=0;
                 while(file.read((char *) &bn, sizeof(bn)))
                 {
                    if(strcmp(nm,bn.getname())==0)
                    {
                        found=1;
                        bn.ViewOffcontact();
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
    	{
		
    			file.open("C:\Users\LENOVO\Desktop\contact management\contacts-management-dot-cpp\address.txt", ios::ate | ios::in | ios::out );
            cout<<"\n\nEnter mobile no : ";
                 cin>>nm;
                 file.seekg(0,ios::beg);
                 found=0;
                 int cnt=0;
                 while(file.read((char *) &bn, sizeof(bn)))
                 {
                    cnt++;
                    if(strcmp(nm,bn.getPhone())==0)
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
                    bn.update(nm,telno);
                    file.write((char *) &bn, sizeof(bn));
                    file.flush();
                 }
                 file.close();
                 break;
             
      }
    		
    		
    	case 10:
    		{
			   
    			fstream fp2;
    			int num;
				system("cls");
				cout<<endl<<endl<<"Please Enter The contact #: ";
				cin>>num;
				//fp.open("contactBook.dat",ios::in|ios::out);
				file.open("D:\\address.txt", ios::in | ios::out );
				//fstream fp2;
				fp2.open("D:\\temp.txt",ios::out);
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
					remove("D:\\address.txt");
					//rename("D:\\temp.txt","D:\\address.txt");
					if(rename("D:\\temp.txt","D:\\address.txt") != 0)
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
 
