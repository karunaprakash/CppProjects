#include <iostream>
#include <typeinfo>
using namespace std;
class Pro;
class ShoppingMallVisitor
{
public:
virtual void visit(Pro* p)=0;
};

class Pro
{
public:
virtual void accept(ShoppingMallVisitor& SMV)=0;
virtual int GetPrice() = 0;
};


class Cashier: public ShoppingMallVisitor
{
public:
void visit(Pro* p)
{
  cout<<p->GetPrice();	
}
};


class Book : public Pro
{
	public:
	void accept(ShoppingMallVisitor& SMV)
	{
		//cout<<"this = "<<typeid(this).name();;
		SMV.visit(this);
	}
	int GetPrice()
	{
		return 123;
	}
};





class ShopingMallProducts
{
  public:
  void GetTotalAmount( Pro* p)
  {
     Cashier csh ;
     p->accept(csh);
  }
};

int main() {
 Pro* p1 = new Book();// Bobj;
 ShopingMallProducts* SMP = new ShopingMallProducts();
 SMP->GetTotalAmount(p1);
	return 0;
}