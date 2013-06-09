/**                                                                     
 *       \file       FormBuilder.h
 *                                                                      
 *       \brief      Headerfile that contains the function declaration.
 *                                                                      
 *       \version    1.0
 *       \date       Sunday 08 June 2013 09:30:13  IST
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

class choice : public form
{
   public:void choose();
          void typeFunc();
          void method1();
          void method2();
          void submit();
};


