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
	int m = this->Q.n_rows;
	//SolY = solve(this->P.t()*this->L,b);
	invQ = inv(this->Q);
	invR = inv(this->R);
	SolY = invQ*b;
	//cout<<"Solucion Y con LU: \n";
	//cout<<SolY;
	//this->resultado = solve(this->U,SolY);
	this->resultado = invR*SolY;
	this->error = norm(eye(m,m)-inv(this->Q*this->R)*this->Q*this->R); // QR
	}
	

void QR::save_res(int type){
	mat aux = zeros(1,1);
	aux(0,0) = this->error;
	if(type == 289){
		this->resultado.save("QR289.dat",raw_binary);
		aux.save("QRError289.dat", raw_binary);
		
		}
	else if(type == 1089){
		this->resultado.save("QR1089.dat",raw_binary);
		aux.save("QRError1089.dat", raw_binary);
		
		}
	else if(type == 4225){
		this->resultado.save("QR4225.dat",raw_binary);
		aux.save("QRError4225.dat", raw_binary);
		
		}
	}
