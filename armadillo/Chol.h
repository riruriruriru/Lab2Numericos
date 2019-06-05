#include <armadillo>
#include <string> // for string class 
#ifndef CHOL_H // include guard
#define CHOL_H
using namespace arma;
using namespace std;
	class Chol {
	  public:
		mat L, resultado;
	  public:
		void set_values (mat A);
		mat get_L();
		mat get_P();
		mat get_R();
		void set_result(mat b); 
	};
#endif
//g++ uwu2.cpp matrix.cpp -o main -larmadillo -O2
