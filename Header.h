#pragma once
#include<iostream>
#include<vector>
using namespace std;

struct CRSeq
{
	unsigned long int rows;
	unsigned long int nonzeros;
	vector<double> vals;
	vector<unsigned long int> col_index;
	vector<unsigned long int> row_ptr;
	vector<double> b;
	vector<double> x;
};

struct CRSCourse
{
	unsigned long int rows_c;
	vector<double> vals_c;
	vector<unsigned long int> col_index_c;
	vector<unsigned long int> row_ptr_c;
	vector<double> b_c;
	vector<double> x_c;
};

struct prolong
{
	vector<double> val;
	vector<unsigned long int> col;
	vector<unsigned long int> row;
};

struct matrix
{
	int n;
	vector<double*> c;
	vector<double*> f;
	vector<int> c_index;
	vector<vector<double> >  p;
	vector<vector<double> >  p_t;
	vector<vector<double> >  a_c;
	vector<vector<double> > a;
	vector<double> b;
	vector<double> x;//x is actually u(or v) our approximate answer
	vector<double> res;
	vector<double> res_c;
	vector<double> e;
	vector<double> au;

};
vector<vector<double> > matrixmaker(int);
vector<double> matrixmakerb(int);
vector<double> linearsolver(vector<vector<double>>, vector<double>, int);
void amgsolver(matrix& a);
void prolongation(matrix& a);
vector<vector<double>> mult(vector<vector<double>> a, vector<vector<double>> b);
vector<vector<double>> mult(vector<vector<double>> a, vector<vector<double>> b, vector<vector<double>> c);
vector<double> mulp(vector<vector<double>> a, vector<double> b);
vector<double> residual(vector<vector<double>> a, vector<double> x, vector<double> b);
void  ReadCRSDrSani(CRSeq&);
vector<double> linearsolverCRS(vector<double> vals, vector<unsigned long int> col_index, vector<unsigned long int> row_ptr, unsigned long int rows, vector<double> b);
void amgsolverCRS(CRSeq& crsmat, CRSCourse& crsmat_c);




