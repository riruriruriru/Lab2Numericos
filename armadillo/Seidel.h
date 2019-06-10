#include <armadillo>
#include <string> // for string class 
#ifndef SEIDEL_H // include guard
#define SEIDEL_H
using namespace arma;
using namespace std;
	class Seidel {
	  public:
		mat resultado, resMat;
		mat err;
		mat iteraciones;
		mat error;
	  public:
		mat get_error();
		mat get_iter();
		mat get_err();
		mat get_resMat();
		mat get_Resultado();
		void save_res(int type);
		void set_result(mat A, mat b, double tol); 
	};
#endif
//g++ uwu2.cpp matrix.cpp -o main -larmadillo -O2
