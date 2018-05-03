/*
C++ Program to check whether the given string contains balanced parentheses or not
*/
#include <iostream>
#include<stack>
using namespace std;

bool ArePair(char LastStackEle, char newEle){
   if (LastStackEle == '(' &&  newEle == ')') return true;
   else if (LastStackEle == '{' &&  newEle == '}') return true;
   else if (LastStackEle == '[' &&  newEle == ']') return true;
   else
   return false;
}

bool AreParanthesBalanced(string str){
       stack<char> s;
       for (int i=0;str[i]!= '\0'; i++)
       {
           
           if (str[i] == '(' || str[i] == '[' || str[i] == '{' )
              s.push(str[i]);
              
           else if (str[i] == ')' || str[i] == ']' || str[i] == '}' )
           {
               if ( s.empty() )
		       return false;
		else if (!ArePair(s.top(),str[i]))
	       {
                   return false;
               }
               else
               {
                   s.pop();
               }
               
           }
    }
    return true;
    
}
int main() {
    string str ="(){}(){}{}";
    if ( AreParanthesBalanced(str))
        cout<<"Balanced"<<endl;
    else
    cout<<"Not Balanced"<<endl;
    return 0;
}
