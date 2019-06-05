#include <armadillo>
#include <string> // for string class 
#ifndef MATRIX_H // include guard
#define MATRIX_H
using namespace arma;
using namespace std;
	class Matrix {
	  public:
		mat A289, b289, A1089, b1089, A4225, b4225;
	  public:
		void set_values ();
		mat get_value(string); 
	};
#endif
//g++ uwu2.cpp matrix.cpp -o main -larmadillo -O2
