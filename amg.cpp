#include"Header.h"

void amgsolver(matrix &first)//x==u
{
	cout << "\n currently in amg solver: \n";
	//vector<double*> c,f;
		/*for (int i = 0; i <= n - 1; i++)
		{
			c.push_back(&u[i]);
		}
		for (int i = 0; i <= n - 1; i++)
		{
			if (c[i] == &u[i]) cout <<"u is"<<&u[i]<<"   and c is : "<< c[i] <<"the value"<<*c[i]<< "\n";
		}*/


	for (int i = 0; i <= (first.n) - 1; i++)
	{
		bool checker= true ;
		for (int z = 0; z < first.c.size(); z++)
		{
			if (first.c[z] == &first.x[i])
				checker = false;
			cout << "c checker is: " << checker << "\n";

		}
		if (checker == true)
		{
			for (int y = 0; y < first.f.size(); y++)
			{
				if (first.f[y] == &first.x[i])
					checker = false;
				cout << "f checker is: " << checker << "\n";
			}
		}
		if (checker == true)
		{
			first.c.push_back(&first.x[i]);
			first.c_index.push_back(i);

			for (int j = 0; j <= (first.n) - 1; j++)
			{
				bool checker2 = true;
				for (int z = 0; z < first.c.size(); z++)
				{
					if (first.c[z] == &first.x[j])
						checker2 = false;
					cout << "c checker2 is: " << checker2 << "\n";

				}
				if (checker2 == true)
				{
					for (int y = 0; y < first.f.size(); y++)
					{
						if (first.f[y] == &first.x[j])
							checker2 = false;
						cout << "f checker2 is: " << checker2 << "\n";

					}
				}
				cout << "about to enter the f and ch2 is :" << checker2 << "\n";
				if (checker2 == true && i!=j)
				{
					if (first.a[i][j] != 0)
					{
						first.f.push_back(&first.x[j]);
						cout << "yes i entered !!!!";
					}
				}

			}

		}

	}

	for (int z = 0; z < first.c.size() ; z++)
	{
		cout << "u0add : " << &first.x[0] << "u1add : " << &first.x[1] << "u2add : " << &first.x[2] << "this c is : " << *first.c[z] << "\n";
	}
	for (int z = 0; z < first.f.size(); z++)
	{
		cout << "u0add : " << &first.x[0] << "u1add : " << &first.x[1] << "u2add : " << &first.x[2] << "this f is : " << *first.f[z] << "\n";
	}
	cout << "first index of c is" << first.c_index[0] << endl;
	cout << "c size is: " << first.c.size() << endl;

	

    //cout << "the first f is:" << f[0] << "the value is : " << *f[0] << "\n";

}