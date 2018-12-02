#include <iostream> 
#include <vector>
using namespace std;

struct Flat
{
	int isLightOn;
	int index;
	Flat *left;
	Flat *right;
	Flat(int _index, int isOn){
		this->isLightOn = isOn;
		this->index = _index;
	}
	void addRight(Flat *flat){
		this->right = flat;
		flat->left = this;
	}
};

vector<Flat*> flats;
vector<Flat*> disturbedFlats;

void addFlat(Flat *flat){
	if(flats.size() > 0){
		flats[(int) flats.size() -1]->addRight(flat);
	}

	flats.push_back(flat);
}

void clearFlats(){
	for (int i = 0; i < flats.size(); ++i){
		delete flats[i];
	}

	flats.clear();
	disturbedFlats.clear();

}

int findDisturbedFlats(){

	for (int i = 1; i < flats.size() -1; ++i){
		// minh di ngu roi, kiem tra 2 ong hang xom xem sao 
		if(!flats[i]->isLightOn && flats[i-1]->isLightOn && flats[i+1]->isLightOn){
				// phien qua
			disturbedFlats.push_back(flats[i]);
		}
	}
	
	int i = 0;
	int total =0;

	while(i < disturbedFlats.size()){

		if(disturbedFlats[i]->right->index == disturbedFlats[i+1]->left->index){
			total++;
			i+= 2;
			if(i == disturbedFlats.size() - 1){
				total++;
				break;
			}
			continue;
		}else{
			total++;
			i++;

			if(i == disturbedFlats.size() -1){
				total++;
				break;
			}
		}
		
	}

//cout << disturbedFlats.size() << " nb:" << sameNeigbors<< endl;
	
	return total;

}
int main(){
	int n,a;
	cin >> n;

	for (int i = 0; i < n; ++i){
		cin >> a;
		Flat *flat = new Flat(i,a);
		addFlat(flat);
	}

	cout << findDisturbedFlats();

	// xoa bo nho
	clearFlats();

	return 0;
}