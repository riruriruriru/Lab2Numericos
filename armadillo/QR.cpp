#include <armadillo>
#include <string>
#include "QR.h" 
using namespace arma;
using namespace std;

//QR

void QR::set_values (mat A){
	mat Q, R, resultado;
	qr(Q,R, A);
	this->Q = Q;
	this->R = R;
	}
mat QR::get_R(){
	return this->R;
	}
mat QR::get_Q(){
	return this->Q;
	}
mat QR::get_Resultado(){
	return this->resultado;
	}

void QR::set_result(mat b){
	mat SolY, solXUWU,invQ, invR;
	//SolY = solve(this->P.t()*this->L,b);
	invQ = inv(this->Q);
	invR = inv(this->R);
	SolY = invQ*b;
	//cout<<"Solucion Y con LU: \n";
	//cout<<SolY;
	//this->resultado = solve(this->U,SolY);
	this->resultado = invR*SolY;
	}