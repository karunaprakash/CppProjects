#include <iostream>
using namespace std;

class abc{
public:
 void fun1(){     cout<<"fun1"; }
 void fun2(){     cout<<"fun2"; }
  void operator()(void (abc::*fp)());
};
void abc::operator()(void (abc::*fp)()){
    cout << "Hi frnd" << endl;
    (this->*fp)();
}

int main() {
    abc obj;
    obj(&abc::fun1);
    obj(&abc::fun2);
    return 0;
}

/*
In c++, assignment operator overloading function couldn't be friend function. 
Using friend function for operator=, will cause the same compiler error 
"overloading = operator must be a nonstatic member function".
*/