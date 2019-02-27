#include <iostream> 
using namespace std;

/*
Đảo các chữ số của số đầu vào. Nếu giá trị của số trước và sau khi đảo bằng nhau thì đó là số đối xứng.
*/

bool dx(int n){
	int reverse = 0,temp;
	temp = n;
	while(temp > 0){
		reverse = reverse*10 + temp%10;
		temp /= 10;
	}
	
	return reverse == n;

}
int main(){
	int n;
	cin >> n;
	cout << dx(n);
	return 0;
}