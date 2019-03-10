#include <iostream>
using namespace std;

class Employee{

private:

	int comprise,compensation;

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
};

int main(){
	
	int comprise,compensation;
	Employee e;

	cin >> comprise >> compensation;

	e.setComprise(comprise);
	e.setCompensation(compensation);

	cout << "Comprise:" << e.getComprise() << endl;
	cout << "Compensation: " << e.getCompensation();


	return 0;
}