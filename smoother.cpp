#include "Header.h"

vector<double> linearsolver(vector<vector<double>> a, vector<double> b, int n)
{
	vector<double> x(n);
	double* x_old = new double[n];
	int iterations = 3;
	for (int i = 0; i <= n - 1; i++)
	{
		x_old[i] = 0;
	}
	for (int k = 1; k <= iterations; k++)
	{
		for (int i = 0; i <= n - 1; i++)
		{
			x[i] = b[i] * (1 / a[i][i]);
			for (int j = 0; j <= n - 1; j++)
			{
				if (i != j)
				{
					x[i] = x[i] - (a[i][j] * x_old[j] / a[i][i]);
				}

			}
		}
		for (int i = 0; i <= n - 1; i++)
		{
			x_old[i] = x[i];
		}
	}
	return x;
}
//crs smoother here vVvVvVv       
vector<double> linearsolverCRS(vector<double> vals, vector<unsigned long int> col_index, vector<unsigned long int> row_ptr, unsigned long int rows, vector<double> b)
{   
	unsigned long int beg, end;
	double sum;
	vector<double> x_old(rows),x(rows);
	for (int i = 0; i < rows; i++)
		x_old[i] = b[i] / vals[row_ptr[i]];
	cout << "in solver first old is:  " << x_old[0] << "last is" << x_old[3];
	unsigned int iterations = 3;
	for (int k = 0; k < iterations; k++)
	{
		for (int i = 0; i < rows; i++)
		{
			beg = row_ptr[i];
			end = row_ptr[i + 1];																	
			sum = 0.;
			for (int j = beg+1; j < end; j++)
			{
				sum = sum - vals[j] * x_old[col_index[j]];
			}
			x[i] = (b[i] + sum) * 1 / vals[beg];
		}
		for (int i = 0; i < rows; i++)
		{
			x_old[i] = x[i];
		}
	}
	
	for (int i = 0; i < rows; i++) cout << "the answer:" << x[i] << "\n";
	return x;
}