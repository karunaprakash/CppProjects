#include <iostream>
using namespace std;

// Added comment as part of branch1
class IEquipment
{ public:
	virtual void Start()=0;
	virtual void Stop()=0;
};

class Refregerator : public IEquipment
{
	public:
	void Start() { cout<<"Refregerator Started"<<endl;}
	void Stop() { cout<<"Refregerator Stopped"<<endl;}
};

class Fan : public IEquipment
{
	public:
	void Start() { cout<<"Fan Started"<<endl;}
	void Stop() { cout<<"Fan Stopped"<<endl;}
};

class ISwitch
{
	public:
	virtual void ON()=0;
	virtual void OFF()=0;
	virtual void CreateConnection(IEquipment *NewEquipmentPtr){};
};

class ClsSwitch : public ISwitch
{
	IEquipment *EtPtr;
	public:
	void CreateConnection(IEquipment *NewEquipmentPtr)
	{
		EtPtr = NewEquipmentPtr;
	}
	void ON()
	{
		EtPtr->Start();
	}
	void OFF()
	{
		EtPtr->Stop();
	}
};


int main() {
	ISwitch* SwitchObj =  new ClsSwitch();
	SwitchObj->CreateConnection(new Refregerator());
	SwitchObj->ON();
	SwitchObj->OFF();
	
	SwitchObj->CreateConnection(new Fan());
	SwitchObj->ON();
	SwitchObj->OFF();
	return 0;
}