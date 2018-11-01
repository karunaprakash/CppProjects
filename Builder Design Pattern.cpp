#include <iostream>
using namespace std;

class IPhone
{
	public:
	virtual void AddScreen()=0;
	virtual void AddBoard() = 0;
	virtual void AddBattery() = 0;
virtual	void display() {};
};

class Windows: public IPhone
{
	public:

	void AddScreen(){cout<<"Windows Screen"<<endl;}
	void AddBoard() {cout<<"Windows Board Screen"<<endl;}
	void AddBattery() {cout<<"Windows Battery"<<endl;}
	void display() {cout<<"Windows phone is now ready to dispatch"<<endl;}
};

class Android : public IPhone
{
 public:
 void AddScreen(){cout<<"Android Screen"<<endl;}
	void AddBoard() {cout<<"Android Board Screen"<<endl;}
	void AddBattery() {cout<<"Android Battery"<<endl;}
		void display() {cout<<"Android phone is now ready to dispatch"<<endl;}
};

class Manufacturer
{
  	public:
  	IPhone* CreatePhone(IPhone* p)
  	{
  		p->AddScreen();
  		p->AddBoard();
  		p->AddBattery();
  		return p;
  	}
};
int main() {
	Manufacturer* obj = new Manufacturer();
	IPhone *p = obj->CreatePhone(new Windows());
	p->display();
	return 0;
}
