#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <queue>
#include "Graph.h"

using namespace std;

//wtf 10 is still before 4

struct compare {
	bool operator()(vector<int> a, vector<int> b) {
		return a[0] > b[0];
	}
};

int main() {

	string s_filename;
	cout << "Dijkstra's algorithm, please enter filename of file containing graph: ";
	cin >> s_filename;

	ifstream file;
	file.open(s_filename, fstream::in);

	int nr_of_points;

	file >> nr_of_points;

	a_matrix c_am(nr_of_points); //c_am class_adjencency_matrix

	//adding info to matrix

	vector<int> iv_lenghtholder;	//placeholder
	string stringholder;	//placeholder
	int intholder;	//placeholder


	for (int i = 0; i <nr_of_points; i++) {

		for (int j = 0; j <nr_of_points; j++) {

			file >> stringholder;
			intholder = stoi(stringholder);
			iv_lenghtholder.push_back(intholder);
		}

		c_am.add(i, iv_lenghtholder);
		iv_lenghtholder.clear();
	}

	int start, end;

	c_am.display();
	cout << endl << "Please enter start point 0-" << nr_of_points - 1 << " : " << endl;
	cin >> start;
	cout << endl << "Please enter end point 0-" << nr_of_points - 1 << " : " << endl;
	cin >> end;

	priority_queue<vector<int>, vector<vector<int>>, compare > short_route;	//priority queue (short first), 1 elem distance, 2 elem start, else path

	vector<int> v_route, v_route_update;

	for (int i = 0; i < c_am.matrix[start].size(); i++) {
		
		if (c_am.matrix[start][i] == 0)continue;
		
		v_route.push_back(c_am.matrix[start][i]);
		v_route.push_back(start);
		v_route.push_back(i);
		
		short_route.push(v_route);
		v_route.clear();
	}



	while (!short_route.empty()) {

		v_route = short_route.top();
		short_route.pop();

		if (v_route.back() == end)break;


		for (int i = 0; i < c_am.matrix[v_route.back()].size(); i++) {

			v_route_update = v_route;

			if (c_am.matrix[v_route_update.back()][i] == 0)continue;	//no path, continue
			
			v_route_update.push_back(i);

			v_route_update.front() += c_am.matrix[v_route.back()][i];

			short_route.push(v_route_update);
		}

		v_route.clear();
	}

	cout << endl << "Path form " << start << " to " << end << " is: ";
	for (int i = 1; i < v_route.size() ; i++) {
		
		if (v_route[i] == end) {
			
			cout << v_route[i] << endl;
			break;
		}
		cout << v_route[i] << " - ";
	}
	cout << "Path lenght: " << v_route.front() << endl << end;

	system("pause");
	return 0;
}