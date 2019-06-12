#include <armadillo>
#include <string> // for string class 
#ifndef MINCUADRADOS_H // include guard
#define MINCUADRADOS_H
using namespace arma;
using namespace std;
	class MinCuadrados {
	  public:
		mat resultado;
		mat A;
		double error;
	  public:
		mat get_A();
		mat get_Resultado();
		void set_values(mat A);
		void save_res(int type);
		void set_result(mat b); 
	};
#endif
//g++ uwu2.cpp matrix.cpp -o main -larmadillo -O2
