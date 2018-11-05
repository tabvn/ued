#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int CHIKAPU = 0; // BASH IS 1; we have only two players.
const int DEBUGMODE = 0;

struct Node
{
	char c;
	int index;
	bool selected;
	Node *left;
	Node *right;

	Node(char c, Node *left){
		this->c = c;
		this->left = left;
		this->selected = false;
		if(left != nullptr){
			left->right = this;
		}		
		
	}

};

struct Priority
{
	char c;
	bool selected;
	int duplicates;
	vector<Node*> nodes;
	Priority(Node *node){
		this->c = node->c;
		this->selected = false;
		this->duplicates = 0;
		this->nodes.push_back(node);
	}
	
};

vector<Node*> nodes;
vector<Priority*> priorities; 

void clear(){
	for (int i = 0; i < nodes.size(); ++i){
		delete nodes[i];
		nodes[i] = nullptr;
	}
	for (int i = 0; i < priorities.size(); ++i){
		delete priorities[i];
		priorities[i] = nullptr;
	}

	nodes.clear();
	priorities.clear();
}

bool sortPriorityDesc(Priority *p1, Priority *p2){
	return p1->duplicates > p2->duplicates;
}

void addPriority(Node *node){
	bool isExist = false;

	for (int i = 0; i < priorities.size(); ++i){
		if(priorities[i]->c == node->c){
			isExist = true;
			priorities[i]->duplicates += 1;
			priorities[i]->nodes.push_back(node);
			break;
		}
	}
	if(!isExist){
		Priority *p = new Priority(node);
		priorities.push_back(p);
	}
}

void winner(int player){
	if(DEBUGMODE == 1){
		cout << endl << "Winer: ";
	}
	if(player==0){
		cout << "Chikapu";
	}else{
		cout << "Bash";
	}
}
int findNodeIndex(){

	if(priorities.size() == 1 || priorities.size() == 2){
		// string contain same characters, or only two characters
		return -1;
	}

	for (int i = 0; i < priorities.size(); ++i){
		
		if(priorities[i]->selected || priorities[i]->nodes.size() == 0){
			continue;
		}

		for (int j = 0; j < priorities[i]->nodes.size(); ++j){
			Node *node = priorities[i]->nodes[j];
			// selected first and last we  can not select this is rule of the play,
			if(node->selected || node->index == 0 || (node->index == (int) (nodes.size() -1))){
				continue;

			}

			if(node->left != nullptr && node->right != nullptr && node->left->c != node->right->c && node->right->right != nullptr && node->left->c == node->right->right->c){
				priorities[i]->selected = true;
				
				node->left->right = node->right;
				node->right->left = node->left;

				node->left = nullptr;
				node->right = nullptr;

				return node->index;
			}

			if(node->left == nullptr || node->right == nullptr || (node->left != nullptr && node->left->selected) || (node->right != nullptr && node->right->selected)){
				priorities[i]->selected = true;

				if(node->left != nullptr && node->right != nullptr){
						node->left->right = node->right;
						node->right->left = node->left;

						node->left = nullptr;
						node->right = nullptr;
				}
				if(node->left != nullptr && node->right == nullptr){
					node->left->right = nullptr;
					node->left = nullptr;

				}

			}
			if(node->left != nullptr && node->right != nullptr && node->left->c != node->right->c){
				priorities[i]->selected = true;

				node->left->right = node->right;
				node->right->left = node->left;

				node->left = nullptr;
				node->right = nullptr;

				return node->index;
			}

		}

	}

	return -1;
}
void play(int player){
	// we find a charactor has max number duplicates in given string and then folow the rules.
	int index = findNodeIndex();

	if(DEBUGMODE){
		if(player ==0){
			cout << "Chikapu: ";
		}else{
			cout << "Bash: ";
		}
		cout << "index:" << index;

		if(index != -1){
			cout << " " << nodes[index]->c;
		}
		cout << endl;

		
	}
	

	if(index == -1){
		// can not play anymore so message output winner
		winner(!player);
	}else{

		Node *node = nodes[index];
		node->selected = true;

		if(DEBUGMODE){
			for (int i = 0; i < nodes.size(); ++i){
				if(nodes[i]->selected){
					cout << "*";
				}else{
					cout << nodes[i]->c;
				}
			}

			cout << endl;
		}
		



		play(!player);
	}
	
}

void playGame(string s){
	
	clear();

	int index = 0;
	for (int i = 0; i < s.size(); ++i){
		if(index == 0){
			Node *node = new Node(s[i], nullptr);
			node->index = index;
			nodes.push_back(node);
			addPriority(node);
		}else{
			Node *node = new Node(s[i], nodes[index-1]);
			node->index = index;
			nodes.push_back(node);
			addPriority(node);
		}
		
		index++;
	}
	// sort priorities descesding 
	sort(priorities.begin(), priorities.end(), sortPriorityDesc);
	play(CHIKAPU);// chikapu go first

}


int main(int argc, char const *argv[]){

	int t;
	cin >> t;
	string s;

	for (int i = 0; i < t; ++i){
		cin >> s;
		playGame(s);	
	}
	
	

	return 0;
}