#include "Graph.h"

using namespace std;

a_matrix::a_matrix(int size) {

	a_matrix::size = size;
}

void a_matrix::add(int point, vector<int> lenght) {
	
	matrix.push_back(lenght);

	//for (int i = 0; i < a_matrix::size; i++) {

	//	matrix[point].push_back()
	//	
	//}
}

void a_matrix::display() {

	for (const auto row : matrix) {

		for (const auto element : row) cout << element<<"\t";
		cout << endl;
	}
}