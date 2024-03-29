#include <armadillo>
#include <string>
#include "MinCuadrados.h" 
using namespace arma;
using namespace std;


void MinCuadrados::set_values (mat A){
	mat AA;
	mat x;
	this->A = A;
	}
mat MinCuadrados::get_A(){
	return this->A;
	}
mat MinCuadrados::get_Resultado(){
	return this->resultado;
	}

void MinCuadrados::set_result(mat b){

	mat AA = this->A;
	mat x;
	int m = this->A.n_rows;
	x = inv(AA.t()*AA)*AA.t()*b;
	this->resultado = x;
	this->error = norm(eye(m,m)-inv(AA.t()*AA)*AA.t()*this->A);
	}

void MinCuadrados::save_res(int type){
	mat aux = zeros(1,1);
	aux(0,0) = this->error;
	cout<<"Errores min squared: "<<endl;
	cout<<aux<<endl;
	if(type == 289){
		this->resultado.save("Archivos/Min289.dat",raw_binary);
		aux.save("Archivos/MinError289.dat",raw_binary);
		}
	else if(type == 1089){
		this->resultado.save("Archivos/Min1089.dat",raw_binary);
		aux.save("Archivos/MinError1089.dat",raw_binary);
		}
	else if(type == 4225){
		this->resultado.save("Archivos/Min4225.dat",raw_binary);
		aux.save("Archivos/MinError4225.dat",raw_binary);
		}
	}
