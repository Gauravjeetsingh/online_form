/**                                                                     
 *       \file       FormBuilder.cpp
 *                                                                      
 *       \brief      Main cpp program that is used to make HTML forms.
 *                                                                      
 *       \version    1.0
 *       \date       Monday 09 June 2013 18:56:13  IST
 *       Compiler    g++
 *                                                                      
 *       \author     Gauravjeet Singh, Gaurav.ishwerdas@gmail.com                             
 */

#include<iostream>
#include<fstream>
#include"FormBuilder.cc"
using namespace std;
main()
{
   char fileName[20],ch,methodChoice;
   int n;
   newForm form1;
   cout<<"Enter the file name with extension:";
   cin>>fileName;
   file.open(fileName);
   cout<<"############### "<<fileName<<" ###############"<<endl;
   file<<"<html><body>\n";
   file<<"<form action=\" \" method=\"GET\">\n";
   cout<<"All fields are of same type y/n:";
   cin>>methodChoice;
   
   if(methodChoice == 'n' || methodChoice == 'N')
   {
     cout<<"Enter total number of fields:";
     cin>>n;
     for(int i=0; i<n; i++)
       form1.differentType();
   }
   
   else if(methodChoice == 'y' || methodChoice == 'Y')
   {
       form1.sameType();
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
