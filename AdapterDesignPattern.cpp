#include <iostream>
#include<list>
#include<vector>
using namespace std;
class Employee
{int Eid;
int Salary;
	public: 
	void SetDetails( int Id, int Sal ){ Eid= Id; Salary = Sal;}
	int GetId() { return Eid;}
	int GetSal() { return Salary;}
	
};
class Company
{
	public:
	list<Employee> GetEmpList()
	{
		list<Employee> EmpList;
		for ( int i = 0; i<10;i++)
		{
			Employee obj;
			obj.SetDetails(i, 100);
			EmpList.push_back(obj);
		}
		return EmpList;
	}
	
};


class Consultency
{
	public:
	void ProcessSalary(vector<Employee> VecEmp)
	{
		vector<Employee>::iterator it = VecEmp.begin();
		while( it != VecEmp.end())
		{
			Employee obj = *it;
			cout<<"salary for Employee :"<<obj.GetId()<<" processed and the amount is : "<<obj.GetSal()<<endl;
			++it;
		}
		
	}
	
	
};


class AdaptorClass
{
	public:
	vector<Employee> ListToVector;
	vector<Employee> ConvertData(Company& obj)
	{
		list<Employee> list1 =  obj.GetEmpList();
		list<Employee>::iterator it = list1.begin();
		while( it != list1.end())
		{
			//Employee obj = *it;
			ListToVector.push_back(*it);
			//cout<<"salary for Employee :"<<obj.GetId()<<" processed and the amount is : "<<obj.GetSal()<<endl;
			++it;
		}
		return ListToVector;
	}
};
int main() {
	Company Hcl;
	AdaptorClass Adaptor;
	vector<Employee> ListToVectorAdaptor;
	ListToVectorAdaptor = Adaptor.ConvertData(Hcl);
	Consultency ConsultencyObj;
	ConsultencyObj.ProcessSalary(ListToVectorAdaptor);
	
	return 0;
}