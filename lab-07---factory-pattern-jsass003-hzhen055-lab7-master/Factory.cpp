#include "Factory.hpp"
#include "base.hpp"
#include "Add.hpp"
#include "Div.hpp"
#include "Mult.hpp"
#include "Pow.hpp"
#include "op.hpp"
#include "Sub.hpp"

#include "VectorContainer.hpp"

#include <string>

using namespace std;

class Container; 

Base* Factory::parse(char **input, int length){

  /*the root of the tree*/
  Base* root; 
  string exprsn = ""; /* expression*/
  bool validExp = true;
  
  for(unsigned int i = 1; i < length; ++i)
  {
     exprsn += input[i];
     exprsn += " ";
  }
  /*validation*/
  for(unsigned int i = 0; i < exprsn.length(); ++i)
  {
    /*-2 to account for space added to the end of the string*/ 
    
    if(exprsn.length() > 4)
    {
      
      if(!isspace(exprsn.at(i)))
      {
        if(exprsn.at(i) == '*' || exprsn.at(i) == '+' ||exprsn.at(i) == '/' || exprsn.at(i) == '-' || exprsn.substr(i,2) == "**")
        {
          /*if the first input is an operator*/
          if(i == 0)
          {
            cout << "Invalid starting char" << endl;
            validExp = false; 
            return nullptr; 
          }
          else if(i == exprsn.length()-2)
          {
            cout << "Invalid ending char" << endl;
            validExp = false; 
            return nullptr; 
          }
          else if(i < exprsn.length() -2 && (exprsn.at(i+2) == '*' || exprsn.at(i+2) == '+' ||exprsn.at(i+2) == '/' || exprsn.at(i+2) == '-' || exprsn.substr(i+2,2) == "**"))
          {
            cout << "Invalid double operators" << endl;
            validExp = false; 
            return nullptr; 
          }
          
        }
        if( isdigit(exprsn.at(i)) == 0 && !(exprsn.at(i) == '*' || exprsn.at(i) == '+' ||exprsn.at(i) == '/' || exprsn.at(i) == '-' || exprsn.substr(i,2) == "**"))
        {
          cout << "Invalid character: non-digit operand" << endl;
          validExp = false; 
          return nullptr; 
        }
      }
    }
    else
    {
      validExp = false;
      cout << "Not a full expression" << endl; 
      return nullptr; 
    }
  }
  if (validExp == false)
  {
    cout << "\nInvalid expression!\n" << endl; 
    return nullptr; 
  }

  /*Container for*/ 
  VectorContainer tree; 
  for(unsigned int i = 0; i < exprsn.length(); ++i)
  { 
    if(!(isspace(exprsn.at(i))))
    {
      if(isdigit(exprsn.at(i))) // 10 + 10 
      {
        /*check later*/
        /*double new_op = 0; */
        vector<double> new_op; 
        double op = exprsn.at(i) - 48; 
       /*every iteration have to add by i by 10*/ 
        ++i;
        int place_count = 0; 
        while(!(isspace(exprsn.at(i))) && i < exprsn.length())
        {
            new_op.push_back(exprsn.at(i)- 48); 
            /*op += new_op;*/ 
            ++i;
            place_count++; 
        }
        for(unsigned int i = 0; i < place_count; ++i){
          op = op * 10; 
        }
        for(unsigned int i = 0; i < place_count; ++i){
          new_op.at(i) = new_op.at(i) * 10;
          place_count--;
        }
        for(unsigned int i = 0; i < new_op.size(); ++i){
          op += new_op.at(i);
        }
        Base* temp = new Op(op);
        tree.add_element(temp);

        /*double op = exprsn.at(i)- 48; 
 *             Base* temp = new Op(op); 
 *                         tree.add_element(temp);*/
      }
      if(ispunct(exprsn.at(i)))
      {
        if(exprsn.at(i) == '+')
        {
          Base* t1 = tree.at(tree.size()-1); /*check later*/
          double op = exprsn.at(i+2) - 48;
          Base* t2 = new Op(op);/*account for space*/
          Base* temp = new Add(t1, t2);

          tree.add_element(temp);
          i = i + 2; 
        }
        else if(exprsn.at(i) == '-')
        {
          Base* t1 = tree.at(tree.size()-1); /*check later*/
          double op = exprsn.at(i+2)- 48;
          Base* t2 = new Op(op);/*account for space*/
          Base* temp = new Sub(t1, t2);

          tree.add_element(temp);
          i = i + 2; 
        }
        else if(exprsn.substr(i, 2) == "**") /*1 ** 1*/
        {
          Base* t1 = tree.at(tree.size()-1);
          double op = exprsn.at(i+3)- 48;
          Base* t2 = new Op(op);/*this may cause an eror*/
          Base* temp = new Pow(t1, t2);

          tree.add_element(temp);
          i = i + 3; 
        }
        else if(exprsn.at(i) == '*')
        {
          Base* t1 = tree.at(tree.size()- 1); /*check later*/
          double op = exprsn.at(i+2)- 48;
          Base* t2 = new Op(op);/*account for space*/
          Base* temp = new Mult(t1, t2);

          tree.add_element(temp);
          i = i + 2; 
        }
        else if(exprsn.at(i) == '/')
        {
          Base* t1 = tree.at(tree.size()-1); /*check later*/
          double op = exprsn.at(i+2)- 48;
          Base* t2 = new Op(op);/*account for space*/
          Base* temp = new Div(t1, t2);

          tree.add_element(temp);
          i = i + 2; 
        }
        
      }
    }
  }
  return tree.at(tree.size()-1);
  /*return nullptr; */
}


