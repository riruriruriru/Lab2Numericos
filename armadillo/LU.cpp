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

void LU::set_result(mat b){
	mat SolY, solXUWU, invL, invU, invP;
	int m = this->L.n_rows;
	invL = inv(L);
	invU = inv(U);
	invP = inv(P.t());
	SolY = invL*invP*b;
	this->resultado = invU*SolY;
	this->error = norm(eye(m,m)-inv(this->L*this->U*this->P)*this->L*this->U*this->P);
	
	}
void LU::save_res(int type){
	mat aux = zeros(1,1);
	aux(0,0) = this->error;
	if(type == 289){
		this->resultado.save("Archivos/LU289.dat",raw_binary);
		aux.save("Archivos/LUError289.dat", raw_binary);
		}
	else if(type == 1089){
		this->resultado.save("Archivos/LU1089.dat",raw_binary);
		aux.save("Archivos/LUError1089.dat", raw_binary);
		}
	else if(type == 4225){
		this->resultado.save("Archivos/LU4225.dat",raw_binary);
		aux.save("Archivos/LUError4225.dat", raw_binary);
		}
	}
