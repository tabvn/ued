#include <iostream> 
using namespace std;

void lietKeSoChinhPhuong(){

	int maxIndex = 0;

	int num = 1;
	int le = 3;
	while(maxIndex < 20){
		cout << num << " ";
		num = num + le;
		le += 2;
		maxIndex++;
	}

}

void findN3s(long long k, long long m){
	long long inc = 0;
	long long num = 0;
	long long le = 1;
	while(inc <= k-1){ // dem tu 0
		if((num -1) %3 ==0){
			inc++;	

			if(inc == k){
				break;
			}
		}
		num = num +le;
		le+= 2;
	}
	cout << ((num -1) % m);

}
int main(){
	/*
	là số: có căn bậc 2 là một số tự nhiên
	Số m là một số chính phương khi và chỉ khi có thể sắp xếp m điểm thành một hình vuông: 
	Số chính phương không bao giờ tận cùng là 2, 3, 7, 8, chỉ có chữ số tận cùng là 0, 1, 4, 5, 6, 9.
	ố chính phương chia cho 3 không bao giờ có số dư là 2; chia cho 4 không bao giờ dư 2 hoặc 3; số chính phương lẻ khi chia 8 luôn dư 1.
	Công thức để tính hiệu của hai số chính phương: a^2-b^2=(a+b)(a-b)
	Tất cả các số chính phương có thể viết thành dãy tổng của các số lẻ tăng dần từ 1: 1, 1 + 3, 1 + 3 + 5, 1 + 3 + 5 + 7, 1 + 3 + 5 + 7 + 9, ...v.v
	*/

	int t;
	long long k,m;
	cin >> t;
	for (int i = 0; i < t; ++i){
		cin >> k >> m;
		findN3s(k,m);
	}
	return 0;
}