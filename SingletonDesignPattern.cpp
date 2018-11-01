#include <iostream>
using namespace std;
class Singleton
{
	static Singleton* SingletonPtr;
	Singleton(){};
	
	public:
	static Singleton* CreateObject();
};

Singleton* Singleton::SingletonPtr = NULL;
Singleton* Singleton::CreateObject()
{
	if ( SingletonPtr == NULL)
	{
		SingletonPtr = new Singleton(); // Constructor
	}
	return SingletonPtr;
}

int main() {
	Singleton* P = Singleton::CreateObject();
	if ( P != NULL )
	{
		cout<<"Pointer created"<<endl;
	}
	return 0;
}