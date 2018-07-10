#include <iostream>
using namespace std;

class abc
{
	char* CrntUser;
  public:
  abc(){      cout<<"Constructor"<<endl;  }
  ~abc(){      cout<<"Destructor"<<endl;  }
  abc(const abc& temp){cout<<"Copy Constructor"<<endl;}
  abc& operator=(abc& temp){
      if ( &temp != this){
      cout<<"Objects are not same"<<endl;
      }
      return *this;
      
  }
  
  void SetUser1(char* strUserDtls)
  {
	  CrntUser = strUserDtls;
  }
};
int main() {
abc obj1;
abc obj2 = obj1;
abc obj3(obj2);

obj3 = obj2;
obj3 = obj3;
    return 0;
}