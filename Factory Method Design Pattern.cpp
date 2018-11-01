#include <iostream>
using namespace std;



class Toy
{
	public:
	virtual void showProduct() = 0;
};

class CarToy : public Toy 
{
	public:
	void showProduct(){ cout<<"CarToy"<<endl;}
};
class BikeToy : public Toy
{
	public:
	void showProduct(){ cout<<"BikeToy"<<endl;}
};

class ToyFactory
{
  public:
  static Toy* CreateObject(int val)
  {
	  Toy* ToyPtr = NULL;
	  switch(val)
	  {
		  case 1:
		      ToyPtr = new CarToy();
			  break;
		  case 2:
			  ToyPtr = new BikeToy();
		      break;
		  default:
			  return NULL;
	  }
	  return ToyPtr;
  }
	
};

int main() {
	Toy* v = ToyFactory::CreateObject(1);
	if ( v)
	{
		v->showProduct();
	}
	return 0;
}