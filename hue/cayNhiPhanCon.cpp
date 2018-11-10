#include <iostream> 
#include <vector>
#include <math.h>
#include <iomanip>
using namespace std;

const int isDebug = true;

struct Node{
	Node *left;
	Node *right;
	int value;
	bool root;

	Node(int n){
		this->left = nullptr;
		this->right = nullptr;
		this->value = n;
		this->root = false;
	}

	void addNode(Node *node){

		
		if(node->value <= this->value){
			// cho sang phai
			
			if(this->right != nullptr && node->value <= this->right->value){
				this->right->addNode(node);
			}else{
				this->right = node;
				if(isDebug){
					cout << "add node: "<<node->value << " to right: " << this->value << endl;
				}

			}
		}else{
			if(this->left != nullptr && node->value <= this->left->value){
				this->left->addNode(node);
			}else{
				this->left = node;
				if(isDebug){
					cout << "add node: "<<node->value << " to left: " << this->value << endl;
				}
			}
			
		}
	}
};

vector<Node*> nodes;
Node *rootNode = nullptr;

int paseInt(char c){
	switch(c){
		case '0': return 0;
		case '1': return 1;
		case '2': return 2;
		case '3': return 3;
		case '4': return 4;
		case '5': return 5;
		case '6': return 6;
		case '7': return 7;
		case '8': return 8;
		case '9': return 9;
		default: return 0;
	}
}

int getNum(vector<int> arr){
	int n = 0;

	for (int i = 0; i < arr.size(); ++i){
		n += arr[i] * pow(10, (int) arr.size() - i -1);
	}

	return n;
}

void addNewNode(int n){

	if(n == 0){
		return;
	}
	Node *node = new Node(n);
	if(rootNode == nullptr){
		node->root = true;
		rootNode = node;
	}else{
		rootNode->addNode(node);
	}
	nodes.push_back(node);

}

void displayNode(Node *node){
	
	cout << "left:" << node->value << endl;
	if(node->left != nullptr){
		cout << node->left->value << endl;
		displayNode(node->left);
	}
	cout << "right: " << node->value << endl;
	if(node->right != nullptr){
		cout << node->right->value << endl;
		displayNode(node->right);
	}
}	
void display(){

	displayNode(rootNode);
}
int main(){
	cout << fixed << (pow(10, 9) +7);
	string s;
	getline(cin, s);
	vector<int> arr;
	int n;


	for (int i = 0; i < s.size(); ++i){
		if(s[i] == ' '){
			if(arr.size() > 0){
				n = getNum(arr);
				addNewNode(n);
				
			}
			arr.clear();
		}
		else{
			arr.push_back(paseInt(s[i]));
		}
		

	}

	if(isDebug){
		display();
	}


	return 0;
}