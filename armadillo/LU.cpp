#include <armadillo>
#include <string>
#include "LU.h" 
using namespace arma;
using namespace std;

//LU Doolittle

void LU::set_values (mat A){
	mat L,U,P;
	lu(L, U, P, A);
	this->L = L;
	this->U = U;
	this->P = P;
	}
mat LU::get_L(){
	return this->L;
	}
mat LU::get_U(){
	return this->U;
	}
mat LU::get_P(){
	return this->P;
	}
mat LU::get_R(){
	return this->resultado;
	}

void LU::set_result(mat A, mat B){
	return;
	}
