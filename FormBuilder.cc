/**                                                                     
 *       \file       FormBuilder.cc                                                                     
 *       \brief      File containg definations of functions declared 
                     in FormBuilder.h.
 *                                                                      
 *       \version    1.0
 *       \date       Sunday 08 June 2013 09:30:13  IST
 *       Compiler    g++
 *                                                                      
 *       \author     Gauravjeet Singh, Gaurav.ishwerdas@gmail.com                             
 */

#include<iostream>
#include<fstream>
#include"FormBuilder.h"
using namespace std;
/*For text,password,date,color,email,number,and many such fields*/
void form :: singleValue()
{
   cout<<"Enter the name of field:";
   cin>>name;
   file<<name<<":";
   file<<"\n<input type=\""<<type<<"\" name=\""<<name<<"\" ><br><br>"<<endl;
}

/*For radio and checkbox fields*/
void form :: multiValue()
{
   char optionName[20];
   int optionValue;
   cout<<"Enter the name of field:";
   cin>>name;
   file<<name<<":"<<endl;
   cout<<"How many options:";
   cin>>optionValue;
   for(int i=0; i<optionValue; i++)
    { 
      cout<<"Enter the name of option:";
      cin>>optionName;
      file<<"\n<input type=\""<<type<<"\" value=\""<<optionName<<"\" name=\""
          <<name<<"\">"<<endl;
      file<<optionName<<endl;
    }
   file<<"<br><br>";
}

void choice :: typeFunc()
{
   cout<<"\nAvailable types:text,password,email,number,file,color,date"
       <<",time,radio,checkbox\n\n";
   cout<<"Enter the type of the field:";
   cin>>type;
} 

void choice :: choose()
{
    if((type == metaType[0]) || (type == metaType[1]) || 
       (type == metaType[2]) || (type == metaType[3]) ||
       (type == metaType[4]) || (type == metaType[5]) ||
       (type == metaType[6]) || (type == metaType[7])   )
   {
     singleValue();
   }
   else if( (type == metaType[8]) || (type == metaType[9]) )
   {
     multiValue();
   }
   else
   {
     cout<<"\nWrong value\n";
   }
}

void choice :: method1()
{
   typeFunc();
   choose();
}

void choice :: method2()
{
   int no;
   typeFunc();
   cout<<"Enter the total number of feilds:";
   cin>>no;
   for(int i=0; i<no; i++)
   {  
    choose();
   }
}

void choice :: submit()
{
   char sname[20];
   cout<<"Enter the name of submit button:";
   cin>>sname;
   file<<"\n<input type = \"submit\" value=\""<<sname<<"\">";
}


