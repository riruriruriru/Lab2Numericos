#include <armadillo>
#include <string> // for string class 
#ifndef LU_H // include guard
#define LU_H
using namespace arma;
using namespace std;
	class LU {
	  public:
		mat L, U,P, resultado;
		double error;
	  public:
		void set_values (mat A);
		mat get_L();
		mat get_U();
		mat get_P();
		mat get_R();
		void set_result(mat b);
		void save_res(int type); 
	};
#endif
//g++ uwu2.cpp matrix.cpp -o main -larmadillo -O2
