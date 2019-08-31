#include "Header.h"
#include "fstream"
#include "string"

void ReadCRSDrSani(CRSeq& boy)
{
	cout << "enter file address: ";
	string fAdd;
	cin >> fAdd;
	ifstream is(fAdd);
	if (is.is_open()) cout << "it's opened";
	string word;
	is >> word;
	boy.rows = stoi(word);
	is >> word;
	boy.nonzeros = stoi(word);
	for (int i = 0; i < boy.nonzeros; i++)
	{
		is >> word;
		boy.vals.push_back(stod(word));
	}
	for (int i = 0; i < boy.nonzeros; i++)
	{
		is >> word;
		boy.col_index.push_back(stoi(word));
	}
	for (int i = 0; i < boy.rows + 1; i++)
	{
		is >> word;
		boy.row_ptr.push_back(stod(word));
	}
	for (int i = 0; i < boy.rows; i++)
	{
		is >> word;
		boy.b.push_back(stod(word));
	}
	cout << "fully read text!\n";
	cout << "rowptr is:\n";
	for (int i = 0; i < boy.row_ptr.size(); i++)
	{
		cout << boy.row_ptr[i] << " ";
	}
}	