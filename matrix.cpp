#include <iostream>
#include <cstdlib>
#include <vector>
#include "matrix.hpp"

Matrix::Matrix(int row, int col){
	x = row;
	y = col;
	data.assign(x, std::vector<int>(y));
}

void Matrix::Reset(int row, int col){
	x = row;
	y = col;
	data.assign(x, std::vector<int>(y));
}

int Matrix::Get_X(){
	return x;
}

int Matrix::Get_Y(){
	return y;
}

int Matrix::Get_Data(int row, int col){
	return data[row][col];
}

std::vector<std::vector<int>> Matrix::Get_Data_Vector(){
	return data;
}

void Matrix::Push_Data(int row, int col, int num){
	data[row][col] = num;
}

void Matrix::Fill_Random(){
	for (int i = 0; i < x; i++){
		for (int j = 0; j < y; j++){
			data[i][j] = rand() % 6;
		}
	}
}

void Matrix::Print(){
	for (int i = 0; i < x; i++){
		for (int j = 0; j < y; j++){
			std::cout << data[i][j] << " "; 
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

Matrix Matrix::Mult_Matrix(Matrix second_matrix){
	int product_rows = x;
	int product_cols = second_matrix.Get_Y();
	Matrix product_matrix;

	if(y == second_matrix.Get_X()){
		product_matrix.Reset(product_rows, product_cols);
	}
	else{
		std::cout << "ERROR: cannot multiply matrices" << std::endl;
		exit(-1);
	}

	int sum = 0;
	for (int i = 0; i < product_rows; i++){
		for (int j = 0; j < product_cols; j++){
			for (int k = 0; k < y; k++){
				sum += data[i][k] * second_matrix.Get_Data(k, j);
			}
		product_matrix.Push_Data(i, j, sum);
		sum = 0;
		}
	}

	return product_matrix;
}
