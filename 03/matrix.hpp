#pragma once
#include <iostream>


class row{
	int* row_ptr;
	int size_of_row;
public:
	row(){
		row_ptr = nullptr;
		size_of_row = 0;
	};
	void initialize(const int &);
	int & operator [](const int &)const;
	int* & get_ptr();
};


class matrix{

	private:
		int rows_num, cols_num;
		row * sub_matrix;
	public:
		matrix (const int & , const int &);
		matrix(const matrix &);
		row & operator [](const int &)const;
		void operator *= (const int &);
		int get_rows () const;
		int get_cols () const;
		~matrix();
};

std::ostream & operator << (std::ostream &, const matrix &);
bool operator ==(const matrix &, const matrix &);
matrix  operator + (const matrix &, const matrix &);
void init(row * & , const int &, const int & );