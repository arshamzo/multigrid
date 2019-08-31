#include "Header.h"

vector<vector<double>> mult(vector<vector<double>> a,vector<vector<double>> b)
{
	vector <vector<double>> result(a.size(),vector<double>(b[0].size(),0));
	for (int i = 0; i < result.size(); i++)
	{
		for (int j = 0; j < result[0].size(); j++)
		{
			int m = 0;
			int n = 0;
			for (int z = 0; z < b.size() ; z++)
			{
				
				result[i][j] += (a[i][m] * b[n][j]);
				m++;
				n++;

			}
		}cout << endl;
	}
	return result;
}
vector<vector<double>> mult(vector<vector<double>> a, vector<vector<double>> b, vector<vector<double>> c)
{
	vector <vector<double> > initial = mult(a, b);
	vector <vector<double> > final = mult(initial, c);
	return final;
}

vector<double> mulp(vector<vector<double>> a, vector<double> b)
{
	vector<double> result(a.size());
	for (int i = 0; i < result.size(); i++)
	{

		int m = 0;
		int n = 0;
		for (int z = 0; z < a.size(); z++)
		{

			result[i] += (a[i][m] * b[n]);
			m++;
			n++;

		}
	}
	return result;
}

///////////////////////////CRS CALCULATIONS//////////////////////////////
