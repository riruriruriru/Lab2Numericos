#include <armadillo>
#include <string> // for string class 
#ifndef SEIDEL_H // include guard
#define SEIDEL_H
using namespace arma;
using namespace std;
	class Seidel {
	  public:
		mat resultado;
	  public:
		mat get_Resultado();
		void set_result(mat A, mat b, double tol); 
	};
#endif
//g++ uwu2.cpp matrix.cpp -o main -larmadillo -O2
