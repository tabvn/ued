#include <iostream>
#include <string>
#include <vector>
using namespace std;
const char LinuxSlash = '/';

struct Folder
{
	string name;
	string path;
	vector<Folder*> childs;
	Folder *parent;
	bool root;
	bool created;
	int level;
	Folder(string name){
		this->name = name;
		this->root = false;
		this->parent = nullptr;
		this->created = false;
	}

	void createPath(){
		string p = "";
		p += LinuxSlash;
		for (int i = 0; i < name.size(); ++i){
			p+= name[i];
		}

		this->path = p;
	}
	void create(){
		this->created = true;
	}
	bool hasChild(string name){
		for (int i = 0; i < this->childs.size(); ++i){
			if(this->childs[i]->name == name){
				return true;
			}
		}
		return false;
	}
	void addChild(Folder *folder){
			if(!this->hasChild(folder->name)){
				folder->level = this->level+1;
				string p = this->path;
				p += LinuxSlash;

				for (int i = 0; i < folder->name.size(); ++i){
					p+= folder->name[i];
				}
				folder->path = p;
				this->childs.push_back(folder);
			}
	}


};


vector<Folder*> folders;
vector<long int> results;

vector<string> _split(string s){
	vector<string> v;
	string p = "";

	for (int i = 0; i < s.size(); ++i){
		if(i == (int)(s.size() -1) && s[i] != LinuxSlash){
			p+= s[i];
			v.push_back(p);
		}
		if(s[i] == LinuxSlash){
			if(p != ""){
				v.push_back(p);
			}
			p = "";
		}else{
			p += s[i];
		}
	}

	return v;
}


Folder *findFolder(string path){
	

	for (int i = 0; i < folders.size(); ++i){
		if(folders[i]->path == path){

			//cout << "folder exist:" << path<<endl;
			return folders[i];
		}
	}
	//cout << "folder does not exist: " << path << endl;
	return nullptr;
}



string getFolderPath(vector<string> v, int _index){
	string s = "";

	for (int i = 0; i <= _index; ++i){
		s += LinuxSlash;
		for (int j = 0; j < v[i].size(); ++j){
			s += v[i][j];
		}
	}
	return s;
}
long int addPath(string s, bool isCreated){
	vector<string> v;
	v = _split(s);
	Folder *parent = nullptr;
	long int totalNeedCreate = 0;

	for (int i = 0; i < v.size(); ++i){
		Folder *f = findFolder(getFolderPath(v, i));
		if(f != nullptr){
			// ton tai
			parent = f;
			
			continue;
		}else{
			if(!isCreated){
				totalNeedCreate ++;
			}
		}
		Folder *newFolder = new Folder(v[i]);
		if(i ==0){
			newFolder->root = true;
			newFolder->level = 0;
			newFolder->parent = nullptr;
			newFolder->createPath();

		}else{
			newFolder->root = false;
		}
		newFolder->created = isCreated;
		if(parent != nullptr){
			parent->addChild(newFolder);
		}

		folders.push_back(newFolder);
		parent = newFolder;

	}

	return totalNeedCreate;
}

void clearFolders(){
	for (int i = 0; i < folders.size(); ++i){
			
		Folder *f = folders[i];
		delete f;
		f = nullptr;
	}
	folders.clear();
}



int main(){
	
	int t, n,m;
	string path;
	cin >> t;


	for (int i = 0; i < t; ++i){
		cin >> n >> m;

		// clear all folders prepare for next test
		clearFolders();

		for (int j = 0; j < n; ++j){
			cin >> path;
			addPath(path, true);
		}
		long int total = 0;

		for (int j = 0; j < m; ++j){
			cin >> path;
		
			total += addPath(path, false);
		
		}
		results.push_back(total);
	}
	for (int i = 0; i < results.size(); ++i){
		cout << "Case #"<< (i+1)<< ": " << results[i] << endl;
	}

	return 0;
}