#include <iostream> 
#include <vector>
#include <fstream>
#include <string>

using namespace std;

ifstream fi ("/Users/toan/ued/graph/EULER.INP");
ofstream fo ("/Users/toan/ued/graph/EULER.OUT");


// Kiểu cạnh
struct Edge
{
	string begin; // tên đỉnh đầu
	string end;	// tên đỉnh cuối

	Edge(string begin, string end){
		this->begin = begin;
		this->end = end;
	}

};

// Kiễu dữ liệu Đỉnh 
struct Vertex
{
	string name; // tên đỉnh
	int deg; // bậc
	bool visited; // dùng để kiểm tra thành phần lien thông 
	
	Vertex(string name){
		this->name = name;
		this->deg = 0;
		this->visited = false;
	}
};

// Thành phần Liên thông
struct ConnectedComponent
{
	vector<Vertex*> vertices;	
};


struct Graph
{

	vector<Edge*> edges; // mảng gồm các cạnh của đồ thị
	vector<Vertex*> vertices; // mảng gồm các đỉnh của đồ thị


	/*
	Tìm vị trí của đỉnh trong mảng theo tên
	*/
	int findVertexIndex(string name){

		for (int i = 0; i < this->vertices.size(); ++i){
			if(this->vertices[i]->name == name){
				return i;
			}
		}
		return -1;
	}

	/*
	Hàm thêm cạnh vào đồ thị
	*/
	Edge* addEdge(string a, string b){

		Edge *e = new Edge(a, b);
		this->edges.push_back(e); // thêm cạnh vào mảng

		// ta cần cập nhật bậc của đỉnh khi thêm cạnh
		Vertex *beginVertex = this->addVertex(a);
		beginVertex->deg += 1;

		Vertex *endVertex = this->addVertex(b);
		endVertex->deg += 1;


		return e;

	}

	

	/*
	hàm tìm đỉnh của đồ thị theo tên
	*/
	Vertex* findVertex(string name){
		for (int i = 0; i < this->vertices.size(); ++i){
			if(this->vertices[i]->name == name){
				return this->vertices[i];
			}
		}
		return NULL;
	}

	/*
	Hàm Thêm đỉnh vào đồ thị
	*/
	Vertex* addVertex(string name){

		Vertex *v = this->findVertex(name);
		if(v != NULL){
			return v; // trả về đỉnh nếu đã tồn tại và không làm thêm gì
		}

		Vertex *newVertex = new Vertex(name);
		this->vertices.push_back(newVertex); // Thêm đỉnh mới vào mảng

		return newVertex;

	}



	/*
	Đếm thành phần liên thông
	*/

	void findConnectedComponents(){

		int visitedVertices = 0;

		vector<ConnectedComponent> components;

		ConnectedComponent component;
	
		int vertextIndex = 0;
		while(true){

			cout << visitedVertices;

			if(visitedVertices == this->vertices.size()){
				break;
			}

			Vertex *v = this->vertices[vertextIndex];
			component.vertices.push_back(v);
			v->visited = true;
			visitedVertices++;

			int nextVertexIndex = -1;
			for (int i = 0; i < this->edges.size(); ++i){
				if(i == vertextIndex){
					continue;
				}

				if(this->edges[i]->begin == v->name){
					Vertex *vertex = findVertex(this->edges[i]->end);
					if(vertex->visited == false && vertex->name != v->name){
						nextVertexIndex = this->findVertexIndex(vertex->name);
						break;
					}

				}

				if(this->edges[i]->end == v->name){
					Vertex *vertex = findVertex(this->edges[i]->begin);
					if(vertex->visited == false && vertex->name != v->name){
						nextVertexIndex = this->findVertexIndex(vertex->name);
						break;
					}
				}

			}

			if(nextVertexIndex == -1){
				// khong con dinh lien ke nao nua
				components.push_back(component);
				component.vertices.clear();

				for (int i = 0; i < this->vertices.size(); ++i){
					if(this->vertices[i]->visited == false){
						vertextIndex = i;
					}

				}
			}else{
				vertextIndex = nextVertexIndex;
			}

		}
		

		cout << "Components:" << components.size() << endl;
		for (int i = 0; i < components.size(); ++i){
			for (int j = 0; j < components[i].vertices.size(); ++j){
				cout << components[i].vertices[j]->name << " ";
			}
			cout << endl;
		}

	}

	bool hasEuler(){
		// theo định lý điều kiện cần và đủ thì tất cả các bậc của đồ thị là chẳn > 0 và đồ thị phải liên thông

		for (int i = 0; i < this->vertices.size(); ++i){
			
			if(this->vertices[i]->deg % 2 != 0){
				// tồn tại bậc lẻ 
				return false;
			}
		}

		return true;
	}
	void findEuler(){
		if(!this->hasEuler()){
			// kêt luận là không tồn tại chu trình Euler 
			fo << "NO";
		}else{

			this->findConnectedComponents();
			// tiền hành tìm chu trình Euler
			fo << "YES";

		}
	}



	void print(){
		cout << "Edges:" << endl;
		for (int i = 0; i < this->edges.size(); ++i){
			cout << this->edges[i]->begin << "-" << this->edges[i]->end << endl;
		}
		cout << endl;

		cout << "Vertices:" << endl;
		for (int i = 0; i < this->vertices.size(); ++i){
			cout << this->vertices[i]->name << " Deg:" << this->vertices[i]->deg << endl;
		}

	}




};

Graph g; // khởi tạo đồ thị

int main(){
	
	int n,m; // n số đỉnh, m số cạnh
	string a, b; // tên đỉnh đầu, tên đỉnh cuối của cung (cạnh)
	fi >> n >> m;

	for (int i = 0; i < m; ++i){
		fi >> a >> b; 
		g.addEdge(a, b); // thêm cạnh vào đồ thị
	}

	g.findEuler();
	//g.print();

	fi.close();
	fo.close();

	return 0;
}