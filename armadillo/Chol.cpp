#include <armadillo>
#include <string>
#include "Chol.h" 
using namespace arma;
using namespace std;

//CHOLESKY UPPER

void Chol::set_values (mat A){
	mat L;
	L = chol(A, "lower");
	this->L = L;
	}
mat Chol::get_L(){
	return this->L;
	}
mat Chol::get_R(){
	return this->resultado;
	}

void Chol::set_result(mat b){
	mat SolY, solXUWU,invL, invLtrans;
	//SolY = solve(this->P.t()*this->L,b);
	invL = inv(this->L);
	invLtrans = inv(this->L.t());
	SolY = invL*b;
	//cout<<"Solucion Y con LU: \n";
	//cout<<SolY;
	//this->resultado = solve(this->U,SolY);
	this->resultado = invLtrans*SolY;
	cout<< this->resultado;
	}
