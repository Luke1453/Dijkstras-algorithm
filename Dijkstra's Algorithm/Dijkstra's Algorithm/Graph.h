#pragma once
#include <iostream>
#include <vector>
using namespace std;

// Class for Graph
class a_matrix
{
	int size;
public:
	vector<vector<int> > matrix;

	a_matrix(int size);

	void add(int point, vector<int> lenght);
	void display();
};