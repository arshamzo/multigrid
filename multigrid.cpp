#include"Header.h"



int main()
{
	cout << "Choose your matrix entry: 1.CRS 2.manual \n";
	int a;
    cin >>  a;
	if (a == 2)
	{
		/*matrix first;
		cout << "enter matrix A size:";
		cin >> first.n;
		cout << "\n";
		first.a = matrixmaker(first.n);
		first.b = matrixmakerb(first.n);
		cout << "matA [0][0] after main  is:" << first.a[0][0] << "\n";
		first.x = linearsolver(first.a, first.b, first.n);
		for (int i = 0; i <= (first.n) - 1; i++) cout << "the answer:" << first.x[i] << "\n";
		amgsolver(first);
		prolongation(first);
		first.a_c = mult(first.p_t, first.a, first.p);
		cout << "\n \n";
		for (int i = 0; i < first.p_t.size(); i++)
		{
			for (int j = 0; j < first.p[0].size(); j++)
			{
				cout << "a c would be:" << first.a_c[i][j];
			}
			cout << "\n";
		}
		first.res = residual(first.a, first.x, first.b);
		first.res_c = mulp(first.p_t, first.res);
		for (int i = 0; i < first.res_c.size(); i++) cout << "heres the damn thing:" << first.res_c[i] << endl;
		first.e = linearsolver(first.a_c, first.res_c, first.res_c.size());
		for (int i = 0; i < first.e.size(); i++) cout << "the answer is: " << first.e[i];
		//first.au = mulp(first.a, first.x);*/
	}
	else
	{
		CRSeq crsmat;
		ReadCRSDrSani(crsmat);
		crsmat.x = linearsolverCRS(crsmat.vals,crsmat.col_index,crsmat.row_ptr,crsmat.rows,crsmat.b);
		CRSCourse crsmat_c;
		amgsolverCRS(crsmat, crsmat_c);
	}
	return 0;
}

vector<vector<double> > matrixmaker(int n)
{
	vector<vector<double> > matA( n , vector<double>(n));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "enter: " << "a[" << i << "][" << j << "] : \n";
			cin >> matA[i][j];
		}
	}
	return matA;
}

vector<double> matrixmakerb(int n)
{
	vector<double> matB(n);
	for (int i = 0; i <= n - 1; i++)
	{
		cout << "enter: " << "b[" << i << "]: \n";
		cin >> matB[i];
	}
	cout << "matB [1] is:" << matB[1];
	return matB;
}

vector<double> residual(vector<vector<double>> a, vector<double> x, vector<double> b)
{
	vector<double > au;
	vector<double > res;
	au = mulp(a,x);
	//vector<vector<double>> ali = mulp(first.a,first.x);
	for (int i = 0; i < au.size(); i++) cout << " \n this au is" << au[i] << endl;

	for (int i = 0;i < au.size(); i++)
	{
		res.push_back (au[i] - b[i]);
	}
	
	return res;
}