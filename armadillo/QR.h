#include <armadillo>
#include <string> // for string class 
#ifndef QR_H // include guard
#define QR_H
using namespace arma;
using namespace std;
	class QR {
	  public:
		mat Q, R,resultado;
	  public:
		void set_values (mat A);
		mat get_Q();
		mat get_R();
		mat get_Resultado();
		void set_result(mat b); 
		void save_res(int type);
	};
#endif
//g++ uwu2.cpp matrix.cpp -o main -larmadillo -O2
