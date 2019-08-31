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
//******************************************CRS*****CRS************************************
void amgsolverCRS(CRSeq& crsmat, CRSCourse& crsmat_c)
{
	vector<double*> course, fine ;
	vector<double> c_index, all_index;
	vector<short int> check(crsmat.rows, 0);//check=-1  : fine , check=0 : nothing , check=1 : course
	for (int i = 0; i < crsmat.rows; i++)
	{
		if (check[i]==0)
		{
			check[i] = 1;
			course.push_back(&crsmat.x[i]);
			c_index.push_back(i);
			for (int j = crsmat.row_ptr[i] + 1; j < crsmat.row_ptr[i + 1]; j++)
			{
				if (check[crsmat.col_index[j]] == 0)
				{
					check[crsmat.col_index[j]] = -1;
					fine.push_back(&crsmat.x[crsmat.col_index[j]]);
				}
			}
		}
	}
	for (int i = 0; i < c_index.size(); i++)
	{
		cout << "\nindex of course is : " << c_index[i] << endl << "the value is: " << *course[i] << endl;
	}
	unsigned long int c_count = -1, f_count = -1;
	for (unsigned long int i = 0; i < crsmat.rows; i++)
	{
		if (check[i]==1)
		{
			c_count++;
			all_index.push_back(c_count);
		}
		else
		{
			f_count++;
			all_index.push_back(f_count);
		}

	}
	//now finding prolongation factor
	prolong p1,p1t;
	long int c_course_count = -1;
	long int value_count = -1;

	for (unsigned long int i = 0; i < crsmat.rows; i++)
	{
		if (check[i] == 1)
		{
			c_course_count++;
			value_count++;
			p1.val.push_back(1);
			p1.col.push_back(c_course_count);
			p1.row.push_back(value_count);
		}
		else
		{
			p1.row.push_back(value_count + 1);
			unsigned long int sigma = 0;
			for (unsigned long int j = crsmat.row_ptr[i] + 1; j < crsmat.row_ptr[i + 1]; j++)
			{

				if (check[crsmat.col_index[j]] == 1)
				{
					sigma++;
				}
			}
			for (unsigned long int j = crsmat.row_ptr[i]+1; j < crsmat.row_ptr[i+1]; j++)
			{
				
				if (check[crsmat.col_index[j]] == 1)
				{				
					p1.val.push_back(1./sigma);
					p1.col.push_back(all_index[crsmat.col_index[j]]);
					value_count++;
				}
			}
		}
	}
	p1.row.push_back(value_count+1);
	cout << "the value i is: ";
	for (int i = 0; i < p1.val.size(); i++)
	{
		cout <<  p1.val[i] << " ";
	}
	cout << endl;
	cout << "the column i is: ";
	for (int i = 0; i < p1.val.size(); i++)
	{
		cout <<  p1.col[i] << " ";
	}
	cout << endl;
	cout << "the rowptr i is: ";
	for (int i = 0; i < p1.row.size(); i++)
		cout << p1.row[i] << " ";
	//now finding the transpose**********************************************hopefully******************
	p1t.val = p1.val;
	vector<unsigned long int> j_count(course.size(),0);
	for (unsigned long int i = 0; i < crsmat.rows; i++)
	{
		for (unsigned long int j = p1.row[i]; j < p1.row[i + 1]; j++)
		{
			cout << "j is: " << j<<endl;
			j_count[p1.col[j]]++;
			p1t.col.push_back(i);
		}
	}
	for (unsigned long int i = 0; i < j_count.size(); i++)
	{
		for (unsigned long int j = 0; j < i; j++)
			j_count[i] = j_count[i] + j_count[j];
	}
	j_count.insert(j_count.begin(), 0);
	p1t.row = j_count;
	cout << "well courrently the rowptrs are: " << p1t.row[0] << " " << p1t.row[1] << " " <<p1t.row[2]<< endl;
	cout << "well courrently the COLUMNS  are: " << p1t.col[0] << " " << p1t.col[1] << " " << p1t.col[2] << endl;
	cout << "well courrently the vals  are: " << p1t.val[0] << " " << p1t.val[1] << " " << p1t.val[2] << " "<< p1t.val[3]<<" "<< p1t.val[4]<< endl;
    //+++++++++++++++++++++++++++here we compute the crs multiplication as efficient as possible+++++++++
	double value_to_be_added=0;
	for (unsigned long int i = 0; i < (p1t.row.size()) - 1; i++)
	{
		for (unsigned long int j = 0; j < crsmat.rows; j++)
		{
			for (unsigned long int k = p1t.row[i]; k < p1t.row[i + 1]; k++)
			{
				for (unsigned long int l = crsmat.row_ptr[p1t.col[k]]; l < crsmat.row_ptr[p1t.col[k] + 1]; l++)
				{
					if (j == crsmat.col_index[l])
					{
						value_to_be_added += p1t.val[k] * crsmat.vals[l];
						break;
					}
				}
			}
			if (value_to_be_added != 0)
			{
				crsmat_c.vals_c.push_back(value_to_be_added);
				crsmat_c.col_index_c.push_back(j);
				value_to_be_added = 0;
			}
		}
	}
	cout << "a_c almost computed ,check some results:"<<endl;
	cout << "well courrently the vals of a  are: " << crsmat.vals[0] << " " << crsmat.vals[1] << " " << crsmat.vals[2] << " " <<crsmat.col_index[2]<<  endl;
	for (int i = 0; i < crsmat_c.vals_c.size(); i++) cout << "the a-c is:" << crsmat_c.vals_c[i] << endl; 
}    

