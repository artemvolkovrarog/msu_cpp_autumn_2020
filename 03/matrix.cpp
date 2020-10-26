#include <iostream>
#include "matrix.hpp"

void init(row * & sub_matrix, const int & rows_num, const int & cols_num){
	sub_matrix = new row[rows_num];
	if (sub_matrix == nullptr) {
		throw("Error while allocating memory");
	}
	for (int i=0; i<rows_num; i++){
		sub_matrix[i].initialize(cols_num);
	}
}

int* & row::get_ptr(){
	return row_ptr;
}
void row :: initialize (const int & row_size){
	row_ptr = new int [row_size];
	if (row_ptr == nullptr){
		throw ("Error while allocating memory");
	}
	size_of_row = row_size;
}

int & row :: operator [] (const int & pos)const{
	if (pos >= size_of_row){
		throw ("Index of columns is out of range"); 
	} 
	else return row_ptr[pos];
}
matrix::~matrix(){
	if (sub_matrix != nullptr){
		for (int i = 0; i < rows_num; i++){
			if (sub_matrix[i].get_ptr() != nullptr) delete[]sub_matrix[i].get_ptr();
		}
		delete[]sub_matrix;
	}
}
matrix::matrix(const matrix & M){
	rows_num = M.get_rows();
	cols_num = M.get_cols();
	init(sub_matrix, rows_num, cols_num);
	for (int i = 0; i < rows_num; i++){
		for (int j = 0; j < cols_num; j++){
			(*this)[i][j] = M[i][j];
		}
	}
}

matrix :: matrix (const int & rows, const int & cols){
	rows_num = rows;
	cols_num = cols;
	init(sub_matrix, rows_num, cols_num);
}

row & matrix::operator [](const int & pos)const{
	if (pos > rows_num){
		throw ("Index of rows is out of range");
	}
	else return sub_matrix[pos];
}

int matrix::get_rows()const{
	return rows_num;
} 
int matrix::get_cols()const{
	return cols_num;
}

std::ostream & operator << (std::ostream & out, const matrix & M ){
	for (int i = 0; i < M.get_rows(); i++){
		for (int j =0; j < M.get_cols(); j++){
			out << M[i][j] << ' ';
		}
		out << std::endl;
	}
	return out;
}

void matrix:: operator *= (const int & multiplier){
	for (int i = 0; i < rows_num; i++){
		for (int j = 0; j < cols_num; j++){
			(*this)[i][j] *= multiplier;
		}
	}
}

bool operator == (const matrix & M1,const matrix & M2){
	bool fl = true;
	if ((M1.get_rows() != M2.get_rows()) || (M1.get_cols() != M2.get_cols())){
		throw("Error, matrices have different size");
	}
	else{
		for (int i = 0; i < M1.get_rows(); i++){
			for (int j = 0; j < M1.get_cols(); j++){
				if (M1[i][j] != M2[i][j]){
					fl = false;
					break;
				}
				if (!fl) break;
			}
		}
	}
	return fl;
}

matrix operator + (const matrix & M1, const matrix & M2){
	if ((M1.get_rows() != M2.get_rows()) || (M1.get_cols() != M2.get_cols())){
		throw("Error, matrices have different size");
	}
	else{
		matrix Res(M1.get_rows(), M1.get_cols());
		for (int i = 0; i < M1.get_rows(); i++){
			for (int j = 0; j < M1.get_cols(); j++){
				Res[i][j] = M1[i][j] + M2[i][j];
			}
		}
		return Res;
	}
}

