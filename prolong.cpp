#include "Header.h"

void prolongation(matrix &first)
{
	first.p.resize(first.n, vector<double>(first.c.size(),8));
	cout << "c size is: " << first.c.size() << endl;
	//this is for p:
	for (int i = 0; i < first.n;i++)
	{
		bool c_check = false;
		for (int z = 0; z < first.c.size(); z++)
		{
			if (first.c[z] == &first.x[i])
			{
				c_check = true;
				for (int z2 = 0; z2 < first.c.size(); z2++)
				{
					first.p[i][z2] = 0;
				}
				first.p[i][z] = 1;

			}
		}
		if (c_check == false)
		{
			double sigma = 0;
			for (int j = 0; j < first.c.size(); j++)
			{
				if (first.a[i][first.c_index[j]] != 0) sigma++;
			}
			for (int j = 0; j < first.c.size(); j++)
			{
				if (first.a[i][first.c_index[j]] != 0) first.p[i][j] = (1 / sigma);
				else first.p[i][j] = 0;
			}
		}
	}
	//this is for p transpose:
	first.p_t.resize(first.p[0].size(), vector<double>(first.p.size()));
	for (int i = 0; i < first.p_t.size(); i++)
	{
		for (int j = 0; j < first.p_t[0].size(); j++)
		{
			first.p_t[i][j] = first.p[j][i];
			cout << "bling   "<< first.p_t[i][j];
		}
		cout<<endl;
	}




	for (int i = 0; i < first.n; i++)
	{
		for (int j = 0; j < int(first.c.size()); j++)
		{
			cout <<"  right in it "<< first.p[i][j] <<" ";
		}
		cout << endl<<"woohooo";
	}

}    