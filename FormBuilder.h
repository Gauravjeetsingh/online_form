/**                                                                     
 *       \file       FormBuilder.h
 *                                                                      
 *       \brief      Headerfile that contains the function declaration.
 *                                                                      
 *       \version    1.0
 *       \date       Monday 09 June 2013 18:51:13  IST
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

class makeForm
{
   private:char name[50];
   public :void singleValue();
	   void multiValue();
};

class newForm : public makeForm
{
   public:void choose();
          void fieldType();
          void sameType();
          void differentType();
          void submit();
};

