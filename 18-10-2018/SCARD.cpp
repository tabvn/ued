#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>

using namespace std;

/*
ifstream fi ("/Users/toan/ued/18-10-2018/SCARD.INP");
ofstream fo ("/Users/toan/ued/18-10-2018/SCARD.OUT");
*/


ifstream fi ("SCARD.INP");
ofstream fo ("SCARD.OUT");


struct Phong{	
	vector<long long> v;
	bool canOpen;
};

vector<long long> vk; // chua cac so cua k
vector<Phong> vp;
vector<long long> vkTmp;

Phong phong;

void vkTmpPrepare(){
	vkTmp.clear();
	for (int i = 0; i < vk.size(); ++i){
		vkTmp.push_back(vk[i]);
	}
}

bool kiemTraDaXoaHet(vector<long long> vt){
	bool isDeletedAll = true;

	for (int i = 0; i < vt.size(); ++i)
	{
		if(vt[i] != -1){
			isDeletedAll = false;
			break;
		}
	}

	return isDeletedAll;
}


void phantichKey(vector<long long> &vt){


	long long n;

	vector<long long> tmp;

	for (int a = 0; a < vt.size(); ++a){
		n = vt[a];
		vt[a] = -1;
		if(n < 2){
			continue;
		}

		//

		for (long long i = 2; i <=n; i++) {


	        while(n % i == 0) {
	          

	            if(i == n){
	            	
	            	tmp.push_back(i);

	            	break;
	            
	            }


	            if(i != 1){
	            
	            	tmp.push_back(i);
	            }
	            

	     

	            n /= i;


	        }
    	}
 	
        
	}


	for (int i = 0; i < tmp.size(); ++i){
		vt.push_back(tmp[i]);
	}

	tmp.clear();


}

void phantichPhong(Phong &phong){
	
	long long n;

	vector<long long> tmp;



	for (int a = 0; a < phong.v.size(); ++a){
		n = phong.v[a];

		//cout << "Phan tich:" << n<< endl;

		phong.v[a] = -1;
		if(n < 2){
			continue;
		}

		
		for (long long i = 2; i <=n; i++) {


	        while(n % i == 0) {
	            //printf("%d.", i);
	            
	            //cout << "tich:" << i << " ";


	            if(i == n){
	            	//phong.v.push_back(i);
	            	tmp.push_back(i);

	            	break;
	            
	            }


	            if(i != 1){
	            	//phong.v.push_back(i);
	            	tmp.push_back(i);
	            }
	            

	     

	            n /= i;


	        }
    	}
 	
        
	}


	for (int i = 0; i < tmp.size(); ++i){
		phong.v.push_back(tmp[i]);
	}

	tmp.clear();

}

void demChia(Phong &phong){

	for (int ii = 0; ii < vkTmp.size(); ++ii){
			
		if(vkTmp[ii] == -1){
			continue;
		}
		for (int jj = 0; jj < phong.v.size(); ++jj)
		{
			if(phong.v[jj] == -1){
				continue;
			}

			//cout << "dem chia:" << vkTmp[ii] << " " << phong.v[jj] <<  " kq:" << vkTmp[ii] % phong.v[jj] <<endl;
			
			if(vkTmp[ii] % phong.v[jj] == 0){
				vkTmp[ii] = vkTmp[ii]/phong.v[jj];
				if(vkTmp[ii] == 1){
					vkTmp[ii] = -1; // danh dau la xoa 
				}

			

				phong.v[jj] = -1; // danh dau la da xoa va chia het


				

				break;

			}


		}


	}




}

int main(){

	vector<int> vCanOpen;

	int m,n, totalCanOpen;
	long long ki,xi;

	fi >> m >> n;

	totalCanOpen = 0;
	// input day so bi mat
	for (int i = 0; i < m; ++i){
		fi >> ki;
		vk.push_back(ki);
	}
	// input day so cac phong

	for (int i = 0; i < n; ++i){
		
		phong.v.clear();
		phong.canOpen = false;

		for (int j = 0; j < m; ++j){
				fi >> xi;
				
				phong.v.push_back(xi);

		}
		vp.push_back(phong);
	}


	// liet ke cac phong
	for (int i = 0; i < vp.size(); ++i){
		
		phong = vp[i];

		vkTmpPrepare();
		demChia(phong);
		// sau luot  kiem tra thu nhat ta se kiem tra lai
		if(kiemTraDaXoaHet(phong.v)){
			// neu da xoa het thi chung to tich da chia het
			// mo dc phong
			vp[i].canOpen = true;
			totalCanOpen++;
			vCanOpen.push_back(i);
			//cout << "mo duoc 1" << endl;

			

		}else{
			if(!kiemTraDaXoaHet(vkTmp)){
				

				// ta tiep tuc phan tic ra thua so nguyen to
				phantichKey(vkTmp);
				phantichPhong(phong);

				// ta dem chia lai

				demChia(phong);
				// sau do kiem tra lai 1 lan nua
				if(kiemTraDaXoaHet(phong.v)){
					vp[i].canOpen = true;
					totalCanOpen++;
					vCanOpen.push_back(i);
					//cout << "mo duoc 2" << endl;
				}else{
					// lan nay thi chac chan la ko con cach nao mo dc roi :D
				}

			}else{
				// khong chia het, tuc la ko mo duoc phong nay
			}
		}

		

		
	}

	fo << totalCanOpen << endl;

	for (int i = 0; i < vCanOpen.size(); ++i){
		fo << vCanOpen[i] +1;
		if(i < vCanOpen.size() -1){
			fo << " ";
		}
		
	}


	fi.close();
	fo.close();

	return 0;
}