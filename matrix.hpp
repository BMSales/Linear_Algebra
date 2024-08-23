#pragma once
#include <vector>

class Matrix{
private:
	int x;
	int y;
	std::vector<std::vector<int>> data;
public:
	Matrix(){};
	Matrix(int, int);
	void Reset(int, int);
	int Get_X();
	int Get_Y();
	int Get_Data(int, int);
	std::vector<std::vector<int>> Get_Data_Vector();
	void Push_Data(int, int, int);
	void Fill_Random();
	void Print();
	Matrix Mult_Matrix(Matrix);
};
