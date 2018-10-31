#include <iostream> 
#include <vector>

using namespace std;

struct Bao
{
	int kg,price;
	
};

Bao bao;
vector<Bao> v;

int findIndexToBuy(int maxKg){

	int _index = -1;
	int _maxKg = 0;
	float avg = 0;
	float _avg;

	for (int i = 0; i < v.size(); ++i){
		if(v[i].kg <= maxKg){
			if(_index == -1){
				// ko co cai nao thi chon 
				_index = i;
				avg = float((float) v[i].kg / (float) v[i].price);
				_maxKg = v[i].kg;

			}else{
				// uu tien avg lon hon
				_avg = float((float) v[i].kg / (float) v[i].price);


				if(_avg > avg){
						_maxKg = v[i].kg;
						avg = _avg;
						_index = i;
				}

				if(_avg == avg){
					// uu tien cai nhieu kg hon
					if(v[i].kg >= _maxKg){
							_maxKg = v[i].kg;
							avg = _avg;
							_index = i;

					}
				}


			}
			
		}
	}



	return _index;

}
long long calculatePrice(int x){

	int totalKgBought = 0;
	long long spendMoney = 0;

	while(totalKgBought <= x){
		int _index = findIndexToBuy(x - totalKgBought);
		if(totalKgBought == x){
			return spendMoney;
		}
		//cout << _index << " kg:" << totalKgBought << " money: "<<spendMoney << endl; 
		if(_index > -1){
			Bao b = v[_index];
			spendMoney += b.price;
			totalKgBought += b.kg;
		}
	}

	return spendMoney;
}

int main(){
	int n;
	long int x; // so thu tu n, va x la số kg cần phải mua
	int p,c;//  là dòng giá trị kg và giá

	// input
	cin >> n >> x;
	for (int i = 0; i < n; ++i){
		cin >> p >> c;
		bao.kg = p;
		bao.price = c;

		v.push_back(bao);
	}

	cout << calculatePrice(x);

	return 0;
}