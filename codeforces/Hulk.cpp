#include <iostream> 
using namespace std;

void MrKhungSays(int n){

	string s = "it";
	for (int i = 1; i <= n; ++i){
		if(i == n){
			s = "it";
		}else{
			s = "that";
		}
		if(i > 1){
			cout << " ";
		}
		if(i % 2==0){
			cout << "I love " << s;
			
		}else{
			cout << "I hate " << s;
			
		}
	}

}
int main(){

	int mrKhungNumber;

	cin >> mrKhungNumber;
	MrKhungSays(mrKhungNumber);

	return 0;
}