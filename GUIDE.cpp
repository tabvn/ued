#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

ifstream fi ("GUIDE.INP");
ofstream fo ("GUIDE.OUT");

struct Hang
{
	int num;
	Hang *parent;
	vector<Hang*> children; 
	bool done;
	bool doneChild;
};

vector<Hang> v;

int findIndex(int num){

	for (int i = 0; i < v.size(); ++i){
		if(v[i].num == num){
			return i;
		}
	}
	return -1;
}



int findChildIndex(Hang *parent, Hang* h){
	for (int i = 0; i < parent->children.size(); ++i){


		if (parent->children[i]->num == h->num){
			return i;
		}

	}
	return -1;
}

void addChild(Hang* parent, Hang* child){
	

	// neu da them vao children roi thi thoi bo qua
	if(findChildIndex(parent, child) == -1){
			parent->children.push_back(child);
	}

	child->parent = parent;
	
}

// test
void displayWay(vector<int> arr){
	for (int i = 0; i < arr.size(); ++i){
				cout << arr[i] << " ";
	}

	cout << endl;

}
bool isExist(int num, vector<int> arr){

	for (int i = 0; i < arr.size(); ++i){
		if(arr[i] == num){
			return true;
		}
	}
	return false;
}

int findWay(Hang* from, Hang* to, vector<int> arr){	
	/*
		Tim duong di, ta lan luot tim phia duoi ben trai truoc, roi ben phai, neu ko tim thay ta quay lai 
	*/
	if(isExist(from->num, arr)){
		int i = arr.size() -1;
		while(arr[i] != from->num){
			arr.pop_back();
			i--;
		}
	}else{
		arr.push_back(from->num);	
	}
	
	if(from-> num == to->num){
		//displayWay(arr);
		return arr[1];
	}

	for (int i = 0; i < from->children.size(); ++i){
			if(from->children[i]->done){
				continue;
			}
			return findWay(from->children[i], to, arr);
	}

	// tim trog phan con ko thay ta tim phia tren
	from->done = true;
	if(from->parent != NULL){
		return findWay(from->parent, to, arr);
	}


	return -1;

}

void resetHangArr(){
	for (int i = 0; i < v.size(); ++i){
		v[i].done = false;
	}
}
int main(){
	int n ,k;
	int a,b;
	fi >> n >> k;
	for (int i = 1; i <= n; ++i){
			Hang h;
			h.num = i;
			h.parent = NULL;
			h.done = false;
			h.children.clear();
			v.push_back(h);
	}
	// ket noi cac hang voi nhau
	for (int i = 0; i < k; ++i){
		fi >> a >> b;
		int parentIndex = findIndex(a);
		int childrenIndex = findIndex(b);
		// vi chac chan la co Hang nen ta ko can kiem tra ton tai hay ko.
		Hang *p = &v[parentIndex];
		Hang *c = &v[childrenIndex];
		// ket noi child, parent 
		addChild(p, c);
	}


	// phan tra cuu

	int m;
	fi >> m;
	vector<int> arr; // luu duong di thu tu toi cac hang


	for (int i = 0; i < m; ++i){

		fi >> a >> b;
		// reset mang
		resetHangArr();
		// gio ta tim hang ke tiep de huong dan khac di tu Hang A -> Hang B
		int fromIndex = findIndex(a);
		int toIndex = findIndex(b);

		Hang *from = &v[fromIndex];
		Hang *to = &v[toIndex];

		arr.clear(); // ta xoá hết mảng chưa các điểm đi qua
		//cout << "tim: "<< from->num << " " << to->num << endl;
		cout << findWay(from, to, arr);
		if(i < m -1){
			cout << endl;
		}

	}


	fi.close();
	fo.close();
	return 0;
}