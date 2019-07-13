#include"Header.h"

double** matrixmaker(int);
double* matrixmakerb(int);
double* linearsolver(double**, double*,int);
void amgsolver(matrix &a);
void prolongation(matrix &a);         

int main()
{
	matrix first;	
	cout << "enter matrix A size:";
	cin >> first.n;
	cout << "\n";
	first.a = matrixmaker(first.n);
	first.b = matrixmakerb(first.n);
	cout << "matA [0][0] after main  is:" << first.a[0][0] << "\n";
	first.x = linearsolver(first.a, first.b, first.n);
	for (int i = 0; i <= (first.n)-1; i++) cout << "the answer:"<<first.x[i]<<"\n";
	amgsolver(first);
	prolongation(first);

	return 0;

}

double** matrixmaker(int n)
{
	double** matA = new double* [n];
	for (int i = 0; i <= n - 1; i++) matA[i] = new double[n];
	for (int i = 0; i <= n - 1; i++)
	{
		for (int j = 0; j <= n - 1; j++)
		{
			cout << "enter: " << "a[" << i << "][" << j << "] : \n";
			cin >> matA[i][j];
		}
	}
	return matA;
}

double* matrixmakerb(int n)
{
	double* matB = new double[n];
	for (int i = 0; i <= n - 1; i++)
	{
		cout << "enter: " << "b[" << i << "]: \n";
		cin >> matB[i];
	}
	cout << "matB [1] is:" << matB[1];
	return matB;
}

double* linearsolver(double** a, double* b, int n)
{
	double* x=new double[n];
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
			x[i] = b[i]*(1/a[i][i]);
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