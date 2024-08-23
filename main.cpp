#include <cstdlib>
#include <ctime>
#include <vector>
#include "matrix.hpp"

int main(){
	srand(clock());

	Matrix A(2, 3);
	Matrix B(2, 4);
	Matrix C;

	A.Fill_Random();
	B.Fill_Random();

	A.Print();
	B.Print();

	C = A.Mult_Matrix(B);

	C.Print();
}
