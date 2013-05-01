/**                                                                     
 *       \file       onlineForm.cpp
 *                                                                      
 *       \brief      A cpp program that is to used to make HTML forms.
 *                                                                      
 *       \version    1.01
 *       \date       Wednesday 01 May 2013 16:52:13  IST
 *       Compiler    g++
 *                                                                      
 *       \author     Gauravjeet Singh, Gaurav.ishwerdas@gmail.com                             
 */

#include<iostream>
#include<fstream>

using namespace std;

ofstream file;
char type[20];
/*Types to choose from*/
string metaType[10] = { "text","password","email","number","file","color"
                        ,"date","time","radio","checkbox" };

class form
{
   private:char name[50];
   public :void singleValue();
	   void multiValue();
};

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
      file<<"\n<input type=\""<<type<<"\" value=\""<<optionName<<"\" name=\""<<name<<"\">"<<endl;
      file<<optionName<<endl;
    }
   file<<"<br><br>";
}

class choice : public form
{
   public:void choose();
          void typeFunc();
          void Method1();
          void Method2();
          void submit();
};

void choice :: typeFunc()
{
   cout<<"\nAvailable types:text,password,email,number,file,color,date,time,radio,checkbox\n\n";
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

void choice :: Method1()
{
   typeFunc();
   choose();
}

void choice :: Method2()
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

main()
{
   char fname[20],ch,MethodChoice;
   int n;
   choice form1;
   cout<<"Enter the file name with extension:";
   cin>>fname;
   file.open(fname);
   cout<<"############### "<<fname<<" ###############"<<endl;
   file<<"<html><body>\n";
   file<<"<form action=\" \" method=\"GET\">\n";
   cout<<"All fields are of same type y/n:";
   cin>>MethodChoice;
   
   if(MethodChoice == 'n' || MethodChoice == 'N')
   {
     cout<<"Enter total number of fields:";
     cin>>n;
     for(int i=0; i<n; i++)
       form1.Method1();
   }
   
   else if(MethodChoice == 'y' || MethodChoice == 'Y')
   {
       form1.Method2();
   }
   
   form1.submit();
   file<<"</form>\n";
   file<<"</body></html>";
   file.close();
   cout<<"\n";
   cout<<"Create another form y/n:";
   cin>>ch;
   if(ch == 'y' || ch == 'Y')
   {
   cout<<"\n";
   main();
   }
}
