#include <iostream> 
using namespace std;

int a, b,c,d;


int getN(int index){
	if(index == 0){
		return a;
	}else if(index == 1){
		return b;
	}
	else if(index == 2){
		return c;
	}
	else{
		return d;
	}
}
int main(){
	int n;
	int maxNumber, minNumber, secondMinNumber;

	cin >> a >> b >> c >> d;


	// gia su minNumber = a; maxNumber = a;
	minNumber = a;
	maxNumber = a;

	// buoc 1 ta di tim gia tri lon nhat va nho nhat trong day so
	for (int i = 0; i < 4; ++i){
		n = getN(i);
		if(n > maxNumber){
			maxNumber = n;
		}
		if(n < minNumber ){
			minNumber = n;
		}

	}

	// sau khi co gia tri lon nhat va nho nhat ta tiep tuc lap 1 lan nua
	// gia su gia tri nho nhi la MaxNumber
	secondMinNumber = maxNumber;
	for (int i = 0; i < 4; ++i){
		n = getN(i);
		if(n < secondMinNumber && n > minNumber){
			secondMinNumber = n;
		}
	}

	cout << secondMinNumber;


	return 0;
}