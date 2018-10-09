#include <iostream>
using namespace std;

class abc
{
  public:
  abc(){      cout<<"Constructor"<<endl;  } //Constructor again
  ~abc(){      cout<<"Destructor"<<endl;  } //Destructor
  abc(const abc& temp){cout<<"Copy Constructor"<<endl;}
  abc& operator=(abc& temp){
      if ( &temp != this){
      cout<<"Objects are not same"<<endl;
      }
      return *this;
      
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