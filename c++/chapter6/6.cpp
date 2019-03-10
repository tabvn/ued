#include <iostream>
using namespace std;

enum EType
{
	Laborer,
	Secretary,
	Manager
};


class Employee{

private:

	int comprise,compensation;
	EType eType;

public:

	void setComprise(int comprise){
		this->comprise = comprise;
	}
	int getComprise(){
		return this->comprise;
	}

	void setCompensation(int compensation){
		this->compensation = compensation;
	}

	int getCompensation(){
		return this->compensation;
	}

	void setEType(EType t){
		this->eType = t;
	}

	EType getEType(){
		return this->eType;
	}

	void print(){

		cout << endl;
		if(this->eType == Manager){
			cout << "You are Manager";
		}
	}


};

int main(){
	
	int comprise,compensation;
	Employee e;

	cin >> comprise >> compensation;

	e.setComprise(comprise);
	e.setCompensation(compensation);
	e.setEType(Manager);



	cout << "Comprise:" << e.getComprise() << endl;
	cout << "Compensation: " << e.getCompensation() << endl;
	cout << "Type: " << e.getEType(); 


	e.print();






	return 0;
}