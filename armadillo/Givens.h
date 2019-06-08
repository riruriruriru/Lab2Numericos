#include <armadillo>
#include <string> // for string class 
#ifndef GIVENS_H // include guard
#define GIVENS_H
using namespace arma;
using namespace std;
	class Givens {
	  public:
		mat Q, R, A,resultado;
	  public:
		void set_values (mat A);
		mat get_Q();
		mat get_R();
		mat get_Resultado();
		sp_mat makeGivens(int m,int i,int j,double xi,double xj);
		void set_result(mat b); 
		void save_res(int type);
	};
#endif
//g++ uwu2.cpp matrix.cpp -o main -larmadillo -O2
