#include <iostream>


using namespace std;

struct Employee
{

	int employee_number;
	float compensation;

	void print(){
			cout << "Number:" << this->employee_number << " Compensation:" << this->compensation << endl;
	}
	
};


void printE(Employee *e){

}

int main(int argc, char const *argv[]){
	

	Employee e1,e2,e3;

  //employee 1
	e1.employee_number = 10;
	e1.compensation = 5.1;

	//employee 2
  e2.employee_number = 11;
	e2.compensation = 6.1;

	//3 
	e3.employee_number = 10;
	e3.compensation = 5.1;

	e1.print();
	e2.print();
	e3.print();


//cout << e1.employee_number  << ":" << e1.compensation;





	return 0;
}