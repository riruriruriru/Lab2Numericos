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
	//SolY = solve(this->P.t()*this->L,b);
	invL = inv(L);
	invU = inv(U);
	invP = inv(P.t());
	SolY = invL*invP*b;
	//cout<<"Solucion Y con LU: \n";
	//cout<<SolY;
	//this->resultado = solve(this->U,SolY);
	this->resultado = invU*SolY;
	}

void LU::save_res(int type){
	if(type == 289){
		this->resultado.save("LU289.dat",raw_binary);
		}
	else if(type == 1089){
		this->resultado.save("LU1089.dat",raw_binary);
		}
	else if(type == 4225){
		this->resultado.save("LU4225.dat",raw_binary);
		}
	}
