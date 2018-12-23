#include <iostream> 
using namespace std;

int daoNguoc(int n){

	int s = 0;

	while(n > 0){
		s = s*10+(n%10);
		n/=10;
	}
	return s;
}
bool laSoDoiXung(int n){

	if(daoNguoc(n) == n){
		return true;
	}

	return false;

}
int main(int argc, char const *argv[]){
	int n;

	cin >> n;

	if(laSoDoiXung(n)){
		cout << "La So doi xung";
	}else{
		cout << "So khong doi xung";
	}


	return 0;
}