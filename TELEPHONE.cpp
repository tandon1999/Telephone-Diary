#include<iostream> 
#include<conio.h> 
#include<fstream> 
#include<stdlib.h> 
#include<iomanip> 
#include<string.h> 
#include<stdio.h> 
#include<regex>
using namespace std;

const char* fileName="phone.txt"; 


class Person{ 
private: 
    int ID; 
    char Name[20],Surname[20], Address[20], Country[25], Email[30], Mobile[10]; 
public:  
    void ReadData(); 
    int GetID(); 
    void DisplayRecord(); 
    char* GetMobile(); 
    char* GetName(); 
}; 


void Person::ReadData() 
    { 
    	int flag=0,count=0;
        while(count==0){
        	try{
        		cout<<endl<<"ID : "; 
        		cin>>ID; 
        		if(isdigit(ID))
					throw 'a';
				count=1;
				}
			catch(...){
				cout<<"\n\n**********Error Please Enter Valid ID**********\n\n";
				break;
				}	
		} 
        cout<<"Name : "; 
        cin>>Name; 
        cout<<"Surname: ";
        cin>>Surname;
        cout<<"Address : "; 
        cin>>Address; 
        while(flag==0){
        	try{
        		cout<<"Mobile : "; 
        		cin>>Mobile;
        		if(strlen(Mobile)!=10){
        			throw 1;
				}
				for(int i=0;i<10;i++){
					if(isdigit(Mobile[i])==0)
					throw 1;
				}
				flag=1;
			}
			catch(int a){
				cout<<"\n\n**********Error Please Enter Valid Mobile Number**********\n\n";
			}	
		}
        cout<<"Country : "; 
        cin>>Country; 
        const regex emailpattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
        while(flag==1){
        	try{
        		cout<<"Email ID : "; 
        		cin>>Email; 
        		if(!regex_match(Email,emailpattern))
					throw 1;
				flag=0; 
			}
			catch(int a){
				cout<<"***Error Please Enter Valid Email***\n";
			}
			
		}
   } 
   
void Person::DisplayRecord() 
    { 
        cout<<endl<<"_________________________________________________________________________________________________________________________________________________________________\n"; 
        cout<<setw(4)<<ID<<setw(20)<<Name<<setw(20)<<Surname<<setw(20)<<Address<<setw(20)<<Mobile<<setw(20)<<Country<<setw(30)<<Email;             
	} 
    
int Person::GetID() 
    { 
        return ID; 
    }
	 
char* Person::GetMobile() 
    { 
        return Mobile; 
    }
	 
char* Person::GetName() 
    { 
        return Name; 
    }
	
	
	 
main() 
{ 
    Person p,p1,temp,prs[100]; 
    char option,ch,Mobile[10],Name[10]; 
    int ID,isFound; 
    system("cls"); 
    fstream file; 
    file.open(fileName,ios::ate|ios::in|ios::out|ios::binary); 

    do{
        cout<<"***********************WELCOME TO TELEPHONE DIARY SYSTEM***********************\n";         
        cout<<"\n**********************************MENU*****************************************"; 
        cout<<endl<<"\n-------------------->>>>>  Enter your option  <<<<<---------------------\n"; 
        cout<<endl<<" 1 => Add a new contact"; 
        cout<<endl<<" 2 => Search contact information from name"; 
        cout<<endl<<" 3 => Search contact information from mobile"; 
        cout<<endl<<" 4 => Display all contact information"; 
        cout<<endl<<" 5 => Update particular contact on the basis of ID:"; 
        cout<<endl<<" 6 => Delete contact on the basis of ID"; 
        cout<<endl<<" 7 => Exit from the program"<<endl; 
        cout<<"********************************************************************************"<<endl; 
        cout<<endl<<"------------>>>>> 'Enter the valid option' <<<<<------------"<<endl;
		cout<<"\t\t->";
		cin>>option;  
        
        switch (option) 
        { 
        
//Mobile Compare if already there will not saved


            case '1': 
                {
	               	p.ReadData(); 
	                file.seekg(0,ios::beg); 
	                isFound=0; 
	                file.read((char*)&p1,sizeof(p1)); 
	                
	                while(!file.eof()) 
	                {
	                    if (strcmp (p1.GetMobile(),p.GetMobile()) ==0)
	                        { 
	                            cout<<"\n**********The contact having this mobile no. already exists.**********\n\n\n\n";  
	                            isFound=1; 
	                            break; 
	                        } 
// 	                    else if(strcmp (p1.GetName(),p.GetName()) ==0)
// 	                    { 
// 	                            cout<<"\nThe contact having this Name already exists.\n\n";  
// //	                            isFound=1; 
// 	                            break; 
// 	                        }
	                    else if(p1.GetID()==p.GetID()){ 
	                            cout<<"\n**********The contact having this ID already exists.**********\n\n\n\n";  
	                            isFound=1; 
	                            break; 
	                        }
							 
	                        file.read((char*)&p1, sizeof(p1)); 
	                }
					 
	                    if(isFound==1)  
	                        break; 
	                    file.clear(); 
	                    file.seekp(0,ios::end); 
	                    file.write((char*) &p, sizeof(p));
	                    cout<<endl<<"\nNew contact has been added successfully....."; 
	                    cout<<"\n\n!!!!!!!!!!!!!!!!!!!!  Thank You For Using Diary !!!!!!!!!!!!!!!!!!!!\n\n\n";
	                    cout<<"********************************************************************************************************\n\n";
	                    break; 
				}
//				break;



//****************************************************************************************************************************************	
//Name search if there then gives name



            case '2': 
                    {
		                isFound=0; 
		                cout<<endl<<"**********Enter name to be searched**********"<<endl;
						cout<<"\t\t->";
		                cin>>Name; 
		                file.seekg(0,ios::beg); 
		                file.read((char*)&p1, sizeof(p1)); 
		        
				        while (!file.eof()) 		
		                {
						 
		                    if (strcmp (p1.GetName(), Name) ==0) 
		                    { 
		                        cout<<setw(4)<<"ID"<<setw(20)<<"Name"<<setw(20)<<"Surname"<<setw(20)<<"Address"<<setw(20)<<"Mobile"<<setw(20)<<"Country"<<setw(25)<<"Email";            
								p1.DisplayRecord(); 		
		                        isFound=1; 		
		                        break; 		
		                    }  		
		                    file.read((char*)&p1, sizeof(p1)); 
		                }  		
		                    file.clear(); 		
		                
						    if(isFound==0) 
		                        cout<<endl<<"\nSorry, Data Not Found!"; 
	                    cout<<"\n\n!!!!!!!!!!!!!!!!!!!!  Thank You For Using Diary !!!!!!!!!!!!!!!!!!!!\n\n\n";	
						cout<<"********************************************************************************************************\n\n";	
		                    break; 		                     	
					 }
//					 break;
					 
					 
					 
//****************************************************************************************************************************************	
//search mobile if there then gives mobile number
 
 
 
            case '3': 
            		{
          				isFound=0; 
		                cout<<endl<<"**********Enter Mobile number to know about this**********"<<endl;
						cout<<"\t\t->"; 	
		                cin>>Mobile; 
		                file.seekg (0,ios::beg); 
		                file.read((char*)&p1, sizeof(p1)); 
		                
		                while (!file.eof()) 
		                {
						 
		                    if (strcmp (p1. GetMobile(),Mobile) ==0) 
		                    { 
		                        cout<<"\nThe contact information for this mobile number is\n"; 
					            cout<<setw(4)<<"ID"<<setw(20)<<"Name"<<setw(20)<<"Surname"<<setw(20)<<"Address"<<setw(20)<<"Mobile"<<setw(20)<<"Country"<<setw(25)<<"Email";               
		                        p1.DisplayRecord(); 
		                        isFound=1; 
		                        break;		
		                    } 
		                    file.read((char*)&p1,sizeof(p1)); 
		                } 
		                    file.clear(); 
		                
						    if(isFound==0) 
		                        cout<<endl<<"\nSorry,Contact Not Found For Mobile Number"<<Mobile; 
	                    cout<<"\n\n!!!!!!!!!!!!!!!!!!!!  Thank You For Using Diary !!!!!!!!!!!!!!!!!!!!\n\n\n";	
	                    cout<<"********************************************************************************************************\n\n";	
		                        break; 
					}
//					break;
					
					
					
//****************************************************************************************************************************************	
//Gives all contact



            case '4': 
					{
						cout<<"\n\t\t\t\t**********ALL CONTACTS**********\n"<<endl; 				
					    file.clear(); 
					    file.seekg(0,ios::beg); 					
					    int counter=0; 
					    file.read((char*)&p1,sizeof(p1)); 
					    
					    while(!file.eof()) 
					    { 
					        prs[counter]=p1;		
					        counter++; 
					        
					        if(counter==1) 
					        	{		 					
					            cout<<setw(4)<<"ID"<<setw(20)<<"Name"<<setw(20)<<"Surname"<<setw(20)<<"Address"<<setw(20)<<"Mobile"<<setw(20)<<"Country"<<setw(25)<<"Email";
					        	} 
					        file.read((char*)&p1,sizeof(p1)); 

					    } 
					    
					    for(int i=0;i<counter;i++) 
					    { 
					        for(int j=1;j<counter;j++) 
					        { 
					            if(strcmp(prs[i].GetName(),prs[j].GetName())>0) 
					            { 
					                temp=prs[i]; 
					                prs[i]=prs[j]; 
					                prs[j]=temp;					
					            } 
					        } 
					    } 
					    
					    for(int i=0;i<counter;i++)
					    prs[i].DisplayRecord(); 
					    cout<<"\n\n\n"<<" "<<counter<<" records found......."<<endl; 
	                    cout<<"\n\n!!!!!!!!!!!!!!!!!!!!  Thank You For Using Diary !!!!!!!!!!!!!!!!!!!!\n\n\n";
	                    cout<<"********************************************************************************************************\n\n";
					    file.clear(); 
					    break;
				}
//				break;
				
				

//****************************************************************************************************************************************				    
//ID to be updated	
		
		
		
			case '5': 
					{
						int recordNo=0; 
						cout<<endl<<"**********Enter ID of person to be updated**********"<<endl;
						cout<<"\t\t->"; 
				        cin>>ID; 
				        isFound=0; 
				        file.seekg(0,ios::beg); 
				        file.read((char*)&p1,sizeof(p1)); 
	
				        while(!file.eof()) 			
				        { 
				            recordNo++; 
				            
				            if(p1.GetID()==ID) 
				            { 
				                cout<<"\nThe old record of a person having ID "<<ID<<" is:\n"<<endl; 
				                cout<<setw(4)<<"ID"<<setw(20)<<"Name"<<setw(20)<<"Surname"<<setw(20)<<"Address"<<setw(20)<<"Mobile"<<setw(20)<<"Country"<<setw(25)<<"Email";           
				                p1.DisplayRecord(); 
				                isFound=1; 
				                break;	                 
				            } 
				            file.read((char*)&p1,sizeof(p1)); 
				        } 

				        if(isFound==0) 
				        {	 
				            cout<<"\nSorry,Contact Not found for that ID "<<ID<<endl; 
				            break; 
				        } 
				        file.clear(); 
				        int location=(recordNo-1)*sizeof(p1); 
				        file.seekp(location,ios::beg); 
				        cout<<"\n\n\nEnter new record for person having ID "<<ID<<endl; 
				        p1.ReadData(); 
				        file.write((char*)&p1,sizeof(p1)); 
	                    cout<<"\n\n!!!!!!!!!!!!!!!!!!!!  Thank You For Using Diary !!!!!!!!!!!!!!!!!!!!\n\n\n";
	                    cout<<"********************************************************************************************************\n\n";
				        break; 
					}
//					break;
					
					
					
//****************************************************************************************************************************************			    
//Deleting the contact	
		
		
		
			case '6': 
				{
					int recordNo=0;
					cout<<endl<<"\n**********Enter ID of person to be deleted**********"<<endl;
					cout<<"\t\t->";  	 
			        cin>>ID; 
			        isFound=0;
			        file.seekg(0,ios::beg); 
			        file.read((char*)&p1,sizeof(p1));
					 
			        while(!file.eof()) 
			        { 
			            recordNo++; 
			            
			            if(p1.GetID()==ID) 
			            { 
			                cout<<"\nThe old contact having ID"<<ID<<" is:\n\n"<<endl; 
			                cout<<setw(4)<<"ID"<<setw(20)<<"Name"<<setw(20)<<"Surname"<<setw(20)<<"Address"<<setw(20)<<"Mobile"<<setw(20)<<"Country"<<setw(25)<<"Email";
			                p1.DisplayRecord();                          
			                isFound=1; 
			                break; 		                 
			            } 
			            file.read((char*)&p1,sizeof(p1)); 
			        } 
			        char tempFile[]="temp.txt"; 
			        fstream temp(tempFile,ios::out|ios::binary); 
			        
			        if(isFound==0) 
			        { 
			            cout<<"\nData not found for a person ID#"<<ID<<endl; 
			            break; 	             
			        } 
	
			        else{ 		
			            file.clear(); 
			            file.seekg(0,ios::beg); 
			            file.read((char*)&p1,sizeof(p1)); 
			            
			            while(!file.eof()) 
			            { 
			                if(p1.GetID()!=ID) 
			                temp.write((char*)&p1,sizeof(p1)); 
			                file.read((char*)&p1,sizeof(p1)); 
			            }
			            file.close(); 
			            temp.close(); 
			            temp.open(tempFile,ios::in|ios::binary); 
			            file.open(fileName,ios::out|ios::binary); 
			            temp.read((char*)&p1,sizeof(p1)); 
			
			            while(!temp.eof()) 			
			            { 
			                file.write((char*)&p1,sizeof(p1)); 
			                temp.read((char*)&p1,sizeof(p1)); 
			            } 
			        }//end of else 
			        temp.close(); 
			        file.close(); 
			        remove(tempFile); 
			        file.open(fileName,ios::ate|ios::in|ios::out|ios::binary);
	                    cout<<"\n\n!!!!!!!!!!!!!!!!!!!!  Thank You For Using Diary !!!!!!!!!!!!!!!!!!!!\n\n\n";
	                    cout<<"********************************************************************************************************\n\n";
			        break; 	
				}
//				break;
				

				
//****************************************************************************************************************************************				         
//Exit			


			case '7': 			
			    {
			    	exit(0); 
			            break; 
			            default: 
			                cout<<"\t\t\tInvalid Options"; 
			            } 
			            cout<<"\n \t\t\nDo You Want To Continue........? Y/N\n"; 
			            cin>>ch; 
				}
//				break;
			            
		}while(ch!='n'); 
	                    cout<<"\n\n!!!!!!!!!!!!!!!!!!!!  Thank You For Using Diary !!!!!!!!!!!!!!!!!!!!\n\n\n";
} 
