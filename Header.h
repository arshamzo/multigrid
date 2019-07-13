#pragma once
#include<iostream>
#include<vector>
using namespace std;

struct matrix
{
	int n;
	vector<double*> c;
	vector<double*> f;
	vector<int>c_index;
	vector<vector<double> >  p;
	double** a;
	double* b;
	double* x;

};


