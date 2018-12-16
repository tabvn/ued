#include <iostream> 
#include <vector>
#include <algorithm>

using namespace std;

struct Company
{
	int employees;
	vector<long int> salaries;

};

vector<Company*> companies;
vector<long int> v;
long long total = 0;

void addCompany(Company *company){
	companies.push_back(company);
}

void mergeCompany(Company *c, long int inc){

	total += inc * (int)c->salaries.size();

	for (int i = 0; i < c->salaries.size(); ++i){
		v.push_back(c->salaries[i] + inc);
	}
}

bool ascSort(Company *a , Company *b){

	if(a->salaries[0] > b->salaries[0]){
		return true;
	}
	if(a->salaries[0] == b->salaries[0]){
		return a->salaries.size() > b->salaries.size();
	}else{

		return false;
	}

	//return a->salaries[0] > b->salaries[0];
}

bool sortSalaryDesc(long int a, long int b){

	return a > b;
}

void solve(){

	long int inc = 0;

	mergeCompany(companies[0], inc);
	long int max = companies[0]->salaries[0];

	for (int i = 1; i < companies.size(); ++i){
		inc = max - companies[i]->salaries[0];

		mergeCompany(companies[i], inc);
	}

	cout << total;
}

int main(int argc, char const *argv[]){
	
	int n,m;
	long int salary;

	cin >> n;

	for (int i = 0; i < n; ++i){
		cin >> m;

		Company *c = new Company();
		c->employees = m;

		for (int j = 0; j < m; ++j){
			cin >> salary;
			c->salaries.push_back(salary);
		}

		sort(c->salaries.begin(), c->salaries.end(), sortSalaryDesc);
		addCompany(c);
	}

	sort(companies.begin(), companies.end(), ascSort);



	solve();
	return 0;
}