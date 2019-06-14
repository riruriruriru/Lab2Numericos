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
	invQ = inv(this->Q);
	invR = inv(this->R);
	SolY = invQ*b;
	this->resultado = invR*SolY;
	this->error = norm(eye(m,m)-inv(this->Q*this->R)*this->Q*this->R); // QR
	}
	

void QR::save_res(int type){
	mat aux = zeros(1,1);
	aux(0,0) = this->error;
	if(type == 289){
		this->resultado.save("Archivos/QR289.dat",raw_binary);
		aux.save("Archivos/QRError289.dat", raw_binary);
		
		}
	else if(type == 1089){
		this->resultado.save("Archivos/QR1089.dat",raw_binary);
		aux.save("Archivos/QRError1089.dat", raw_binary);
		
		}
	else if(type == 4225){
		this->resultado.save("Archivos/QR4225.dat",raw_binary);
		aux.save("Archivos/QRError4225.dat", raw_binary);
		
		}
	}
