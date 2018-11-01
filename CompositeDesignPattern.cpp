/*
The composite design pattern allows you to set up a tree structure and ask each element in the tree structure to perform a task. A typical tree structure would be a company organization chart, where the CEO is at the top and other employees at the bottom. After the tree structure is established, you can then ask each element, or employee, to perform a common operations.
*/

#include <iostream>
#include<list>
using namespace std;
class IResponsibility
{
	public:
	virtual void DoWork() = 0;
};

class Employee : public IResponsibility
{
	public:
	void DoWork() {cout<<"Do Work"<<endl;}
};

class Supervisior : public IResponsibility
{
	list<Employee> EmpList;
	
	public:
	void AddSubOrdinate(Employee obj)
	{
		EmpList.push_back(obj);
	}
	
	void DoWork()
	{
		list<Employee>::iterator it = EmpList.begin();
		while( it != EmpList.end())
		{
			(*it).DoWork();
		}
	}
};

int main() {
	Employee a;
	Employee b;
	Employee c;
	Supervisior d;
	d.AddSubOrdinate(a);
	Supervisior e;
	e.AddSubOrdinate(b);
	e.AddSubOrdinate(c);
	d.DoWork();
	e.DoWork();
	return 0;
}