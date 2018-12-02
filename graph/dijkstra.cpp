#include <iostream>
#include <climits>
#include <vector>
#include <fstream>

using namespace std;

ifstream fi ("/Users/toan/ued/graph/DIJKSTRA.INP");
ofstream fo ("/Users/toan/ued/graph/DIJKSTRA.OUT");

// Kieu dinh
struct Dinh
{
	char ten;
	bool xoa;
	Dinh *dinhTruocNo; // dinh truong no 
	int khoangCach; // do dai duong di se dc cap nhat trong khi chay thuat toan

	Dinh(char ten){

		this->ten = ten;
		this->xoa = false;
		this->khoangCach = INT_MAX; // mac dinh se la infinity 
		this->dinhTruocNo = NULL;

	}
};


// Kieu canh
struct Canh
{
	char dau;
	char cuoi;
	int trongSo;

	Canh(char dau, char cuoi, int trongSo){

		this->dau = dau;
		this->cuoi = cuoi;
		this->trongSo = trongSo;

	}

};

// Kieu do thi
struct DoThi
{
	vector<Dinh*> tatCaDinh; 
	vector<Canh*> tatCaCanh;

	int timViTriDinh(char ten){

		for (int i = 0; i < this->tatCaDinh.size(); ++i){
				if(this->tatCaDinh[i]->ten == ten){
					return i;
				}
		}

		return -1;
	}

	Dinh* timDinh(char ten){

		for (int i = 0; i < this->tatCaDinh.size(); ++i){
				if(this->tatCaDinh[i]->ten == ten){
					return this->tatCaDinh[i];
				}
		}

		return NULL; // khong co gi neu khong ton tai dinh
	}

	Dinh* themDinh(char ten){

		int viTri = timViTriDinh(ten);
		if( viTri == -1){
			// khong ton tai dinh thi ta them moi
			Dinh *dinh = new Dinh(ten);
			this->tatCaDinh.push_back(dinh); // them dinh vao mang

			return dinh;
		}

		// mac dinh tra ve dinh da ton tai
		return this->tatCaDinh[viTri];
	}

	void themCanh(char a, char b, int trongSo){

		themDinh(a);
		themDinh(b);

		Canh *canh = new Canh(a,b,trongSo);

		this->tatCaCanh.push_back(canh); // them canh vao mang

	}

	bool tatCaDinhDaXoa(){

		for (int i = 0; i < this->tatCaDinh.size(); ++i){
			if(this->tatCaDinh[i]->xoa == false){
				return false;
			}
		}
		return true;
	}

	vector<Canh*> timTatCaCanhCoDinhDau(Dinh *dinh){

		vector<Canh*> canhs;

		for (int i = 0; i < this->tatCaCanh.size(); ++i){
			if(this->tatCaCanh[i]->dau == dinh->ten){
				canhs.push_back(this->tatCaCanh[i]);
			}
		}

		return canhs;
	}

	void buocLap(Dinh *dinhHienTai){

		dinhHienTai->xoa = true; // tien hanh loai dinh ra (dinh nay da ghe tham)
		// kiem tra neu tat ca dinh da xoa thi dung
		if(this->tatCaDinhDaXoa()){
			return;
		}

		// tien hanh cong va cap nhat trong so
		vector<Canh*> canhs = timTatCaCanhCoDinhDau(dinhHienTai);

		if(canhs.size() == 0){
			// khong co canh noi lien dinh nay 
			return;
		}

		int khoangCach;

		for (int i = 0; i < canhs.size(); ++i){
			Dinh *dinh = timDinh(canhs[i]->cuoi);
			// kiem tra xem co can thiet cap nhat lai khoang cach hay khong

			khoangCach = (dinhHienTai->khoangCach + canhs[i]->trongSo);
			if(dinh->khoangCach > khoangCach){
				dinh->khoangCach = khoangCach;
				// dong thoi cap nhat luon dinh truoc no , dung cho viec liet ke duong di
				dinh->dinhTruocNo = dinhHienTai;
			}
		}

		// sang buoc lap ke tiep ta tim 1 dinh ma chua xoa , va co khoang cach nho nhat

		int khoangCachNhoNhat = INT_MAX; // tam gan cho no la max
		int vitriDinhNhoNhat = 0;


		for (int i = 0; i < this->tatCaDinh.size(); ++i){
			if(this->tatCaDinh[i]->xoa == false && this->tatCaDinh[i]->khoangCach < khoangCachNhoNhat){
				khoangCachNhoNhat = this->tatCaDinh[i]->khoangCach;
				vitriDinhNhoNhat = i;
			}
		}

		// tiep tuc lap lai
		buocLap(this->tatCaDinh[vitriDinhNhoNhat]);


	}

	void lietKeDuongDi(Dinh *dinh, vector<Dinh*> &vec){

		vec.push_back(dinh);
		if(dinh->dinhTruocNo != NULL){
			lietKeDuongDi(dinh->dinhTruocNo, vec);
		}

	}

	int timDuongDiNganNhat(char dau, char cuoi){

			Dinh *dinhBatDau = this->timDinh(dau);

			dinhBatDau->khoangCach = 0;

			buocLap(dinhBatDau);

	

			Dinh *dinhCuoi = this->timDinh(cuoi);

			if(dinhCuoi->khoangCach == INT_MAX){
				fo << "NO";
			}else{
				fo << "Yes" << endl;
				fo << dinhCuoi->khoangCach << endl;

				vector<Dinh*> cacDinhDuongDi;
				lietKeDuongDi(dinhCuoi, cacDinhDuongDi);

				for (int i = cacDinhDuongDi.size() -1; i >= 0; i--){
					fo << cacDinhDuongDi[i]->ten << " ";
				}
			}

			return dinhCuoi->khoangCach;
	}



};


DoThi g; // khoi tao do thi

int main(){
	
	int soDinh, soCung, trongSo;
	char dinhDau, dinhCuoi;
	char a,b; // dinh dau va cuoi khi nhap

	fi >> soDinh >> soCung >> dinhDau >> dinhCuoi;
	// nhap du lieu tu canh va trong so
	for (int i = 0; i < soCung; ++i){
		fi >> a >> b >> trongSo ;
		// them canh moi
		g.themCanh(a, b, trongSo);
	}

	g.timDuongDiNganNhat(dinhDau, dinhCuoi);


	fi.close();
	fo.close();

	return 0;
}