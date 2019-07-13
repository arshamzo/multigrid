#include "Header.h"

void prolongation(matrix &first)
{
	first.p.resize(first.n, vector<double>(first.c.size(),1.0));
	cout << "c size is: " << first.c.size() << endl;
	for (int i = 0; i < first.n; i++)
	{
		for (int j = 0; j < int(first.c.size()); j++)
		{
			cout <<"  right in it "<< first.p[i][j] <<" ";
		}
		cout << endl<<"woohooo";
	}
}