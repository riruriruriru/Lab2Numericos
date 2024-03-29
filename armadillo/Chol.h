#include <armadillo>
#include <string> // for string class 
#ifndef CHOL_H // include guard
#define CHOL_H
using namespace arma;
using namespace std;
	class Chol {
	  public:
		mat L, resultado;
		double error;
	  public:
		void set_values (mat A);
		mat get_L();
		mat get_P();
		mat get_R();
		void set_result(mat b); 
		void save_res(int type);
	};
#endif
//g++ uwu2.cpp matrix.cpp -o main -larmadillo -O2
