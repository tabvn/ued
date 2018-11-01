#include <iostream> 
using namespace std;

double a,b; // hai so thuc a,b
int main(){
	long long x, y;
	cin >> a >> b;
	// ta gán 2 số thực cho so nguyên
	x = a;
	y = b;
	// kiem tra ta tang x len 1
	if(x < a){
		x++;
	}
	// ta tinh tong tu 1 -> x -1;
	// ta tinh tong tu 1 - >y;
	// lay tong tu 1->y - (1->x-1)
	// 1 -> n => n(n+1)/2

	long long result = (y*(y+1))/2 - (x*(x-1+1)/2);

	cout << result;
	return 0;
}