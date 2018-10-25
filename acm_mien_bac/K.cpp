#include <iostream>
#include <vector>
#include <math.h>
//#include <fstream>

using namespace std;

//ifstream fi ("/Users/toan/ued/acm_mien_bac/K.INP");

#define input cin



long long M;


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

		while (n%2 == 0) 
    { 
       	tmp.push_back(2);
        n = n/2; 
    } 


    for (int i = 3; i <= sqrt(n); i = i+2) 
    { 
        // While i divides n, print i and divide n 
        while (n%i == 0) 
        { 
            //printf("%d ", i); 

        			tmp.push_back(i);
            n = n/i; 
        } 
    } 

    if(n > 2){
    	tmp.push_back(n);
    }


		/*for (long long i = 2; i <=n; i++) {


	


	        while(n % i == 0) {
	          
	         cout << "Phan tich tu:" << n << ":" << i << endl;


	          	//tmp.push_back(i);

	          


	            if(i != 1){
	            
	            	tmp.push_back(i);
	            }
	            

	     

	            n /= i;


	        }
    	}*/
 	
        
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

		
		/*for (long long i = 2; i <=n; i++) {


	        while(n % i ==0) {
	            //printf("%d.", i);
	            
	            //cout << "tich:" << i << " ";

							//cout << "Phan tich mau:" << n << ":" << i << endl;


	            if(i != 1){
	            	//phong.v.push_back(i);
	            	tmp.push_back(i);
	            }
	            

	 
	            n /= i;


	        }
    	}
    	*/

		while (n%2 == 0) 
    { 
       	tmp.push_back(2);
        n = n/2; 
    } 


    for (int i = 3; i <= sqrt(n); i = i+2) 
    { 
        // While i divides n, print i and divide n 
        while (n%i == 0) 
        { 
            //printf("%d ", i); 

        			tmp.push_back(i);
            n = n/i; 
        } 
    } 

    if(n > 2){
    	tmp.push_back(n);
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



long long tinhTu(vector<long long> vt){

	long long value = 1;

	for (int i = 0; i < vt.size(); ++i)
	{

	
		if(vt[i] != -1){
			
			value *= vt[i] % M;
		}
	}

	return value % M;

}


long long tinhMau(vector<long long> vt){

	long long value = 1;

	for (int i = 0; i < vt.size(); ++i)
	{
		if(vt[i] != -1){
			
			value *= vt[i] % M;
		}
	}

	return value % M;

}

int main(){

	vector<int> vCanOpen;

	long long m,n, totalCanOpen, tu,mau;
	long long ki,xi;

	input >> m >> n >> M;

	totalCanOpen = 0;
	// input day so bi mat
	for (int i = 0; i < m; ++i){
		input >> ki;
		vk.push_back(ki);
	}
	// input day so cac phong


		phong.v.clear();
		phong.canOpen = false;

		for (int j = 0; j < n; ++j){

				input >> xi;
				
				phong.v.push_back(xi);

		}
		vp.push_back(phong);



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
			tu = tinhTu(vkTmp);

			mau = 1;
			

		}else{
			if(!kiemTraDaXoaHet(vkTmp)){
			
				// ta tiep tuc phan tic ra thua so nguyen to
				phantichPhong(phong);
				phantichKey(vkTmp);
				

				// ta dem chia lai

				demChia(phong);
				// sau do kiem tra lai 1 lan nua
				if(kiemTraDaXoaHet(phong.v)){
					vp[i].canOpen = true;
					totalCanOpen++;
					vCanOpen.push_back(i);
					//cout << "mo duoc 2" << endl;

					tu = tinhTu(vkTmp);
					mau = 1;

				}else{
					// lan nay thi chac chan la ko con cach nao mo dc 
					tu = tinhTu(vkTmp);
					mau = tinhMau(phong.v);
				}

			}else{
				// khong chia het, tuc la ko mo duoc phong nay
				tu = 1;
				mau = tinhMau(phong.v);
			}
		}

		

		
	}

	cout << tu << endl << mau;

	return 0;
}