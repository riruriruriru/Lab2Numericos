#include <armadillo>
#include <string>
#include "Chol.h" 
using namespace arma;
using namespace std;

//CHOLESKY LOWER

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
	int m = this->L.n_rows;
	//cout<<"Solucion Y con LU: \n";
	//cout<<SolY;
	//this->resultado = solve(this->U,SolY);
	this->resultado = invLtrans*SolY;
	this->error = norm(eye(m,m)-inv(this->L*this->L.t())*this->L*this->L.t());
	//cout<< this->resultado;
	}

void Chol::save_res(int type){
	mat aux = zeros(1,1);
	aux(0,0) = this->error;
	if(type == 289){
		this->resultado.save("Chol289.dat",raw_binary);
		aux.save("CholError289.dat", raw_binary);
		}
	else if(type == 1089){
		this->resultado.save("Chol1089.dat",raw_binary);
		aux.save("CholError1089.dat", raw_binary);
		}
	else if(type == 4225){
		this->resultado.save("Chol4225.dat",raw_binary);
		aux.save("CholError4225.dat", raw_binary);
		}
	}
