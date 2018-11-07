#include <iostream> 
using namespace std;

int t, t100, t20, t5;

void doiTien(int t){
	t100 = t/100;
	t -= t100* 100;
	t20 = t/20;
	t -= t20 *20;
	t5 = t/5;
	t -= t5*5;
}
int main(){
	
	cin >> t;

	doiTien(t);

	cout << "To 100:" << t100 << endl;
	cout << "To 20:" << t20<< endl;
	cout << "To 5:" << t5<< endl;
	return 0;
}