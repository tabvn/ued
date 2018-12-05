#include <iostream> 
#include <fstream>
#include <vector>

using namespace std;

ifstream fi ("/Users/toan/ued/graph/DSCANH.INP");
ofstream fo ("/Users/toan/ued/graph/DSCANH.OUT");

// Kiểu cạnh
struct Edge
{
	int begin; // tên đỉnh đầu
	int end;	// tên đỉnh cuối

	Edge(int begin, int end){
		this->begin = begin;
		this->end = end;
	}

};

// Kiễu dữ liệu Đỉnh 
struct Vertex
{
	int name; // tên đỉnh
	int deg; // bậc
	
	Vertex(int name){
		this->name = name;
		this->deg = 0;
	}
};

struct Graph
{

	vector<Edge*> edges; // mảng gồm các cạnh của đồ thị
	vector<Vertex*> vertices; // mảng gồm các đỉnh của đồ thị


	/*
	Tìm vị trí của đỉnh trong mảng theo tên
	*/
	int findVertexIndex(int name){

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
	Edge* addEdge(int a, int b){

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
	Vertex* findVertex(int name){
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
	Vertex* addVertex(int name){

		Vertex *v = this->findVertex(name);
		if(v != NULL){
			return v; // trả về đỉnh nếu đã tồn tại và không làm thêm gì
		}

		Vertex *newVertex = new Vertex(name);
		this->vertices.push_back(newVertex); // Thêm đỉnh mới vào mảng

		return newVertex;

	}


};


Graph g;


int main(){
	
	int n, m; // dinh, canh

	int a,b;

	fi >> n >> m;

	for (int i = 0; i < m; ++i){
		fi >> a >> b;
		g.addEdge(a, b);

	}

	fo << "Dinh  " << "Bac" << endl;
	for (int i = 1; i <= n; ++i){
		Vertex *v = g.findVertex(i);
		fo <<i << "     " << v->deg << endl;
	}


	fi.close();
	fo.close();


	return 0;
}