#include <iostream> 
#include <vector>

using namespace std;

struct Node
{
	int value;
	vector<Node*> parent;
	vector<Node*> children;
};

Node node;

vector<Node> v;

void addNode(int from, int to){

	int fromIndex = -1;
	int toIndex = -1;

	Node* a;
	Node* b;


	for (int i = 0; i < v.size(); ++i){
			if(v[i].value == from){
				fromIndex = i;
			}
			if(v[i].value == to){
				toIndex = i;
			}
	}
	if(fromIndex > -1){
		a = &v[fromIndex];
	}else{
		a->value = from;
		
	}
	if(toIndex > -1){
		b = &v[toIndex];

	}else{
		b->value = to;
		
	}

	a->children.push_back(b);
	b->parent.push_back(a);


}
int main(){
	
	int n;
	int from,to;

	cin >> n;

	for (int i = 0; i < n; ++i){
		cin >> from >> to;
		addNode(from, to);
	}

	for (int i = 0; i < v.size(); ++i){
			cout << v[i].value << endl;
	}

	return 0;
}