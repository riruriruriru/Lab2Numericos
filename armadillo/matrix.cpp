#include <iostream>
#include <armadillo>
#include <time.h>
#include <string> // for string class 
#include "matrix.h"
using namespace std;
using namespace arma;
void Matrix::set_values () {
	this->A289.load("../armadillo/sistemas/289x289/A289.dat");
	this->b289.load("../armadillo/sistemas/289x289/b289.dat");
	this->A1089.load("../armadillo/sistemas/1089x1089/A1089.dat");
	this->b1089.load("../armadillo/sistemas/1089x1089/b1089.dat");
	this->A4225.load("../armadillo/sistemas/4225x4225/A4225.dat");
	this->b4225.load("../armadillo/sistemas/4225x4225/b4225.dat");
}
mat Matrix::get_value(string s){
	if((s.compare("A289")) == 0){
		return this->A289;
		}
	if((s.compare("b289")) == 0){
		return this->b289;
		}
	if((s.compare("A1089")) == 0){
		return this->A1089;
		}
	if((s.compare("b1089")) == 0){
		return this->b1089;
		}
	if((s.compare("A4225")) == 0){
		return this->A4225;
		}
	if((s.compare("b4225")) == 0){
		return this->b4225;
		}
	
}
