#include <armadillo>
#include <string>
#include "Givens.h" 
using namespace arma;
using namespace std;

//GIVENS

void Givens::set_values (mat A){
	sp_mat Q, R;
	double raiz, s, c;
	double xi, xj;
	int i=0;
	int j, k;
    int m = A.n_rows;
    int n = A.n_cols;
    R = A;
    Q=Q.eye(m,n);
	
	for(j=0;j<n;j++){
		for(i=j+1;i<m;i++){ 
				if (R(i,j)!=0){
					xi = R(i,j);
					xj = R(i,j);
					sp_mat G = makeGivens(m,i,j,xi,xj);
					
					Q = Q*G.t();
					R = G*R;
					
				} 
			}
		}
		
	this->Q = Q;
	this->R = R;
	this->A = A;
}
sp_mat Givens::makeGivens(int m,int i,int j,double xi,double xj){
    sp_mat G;
    G = G.eye(m,m);
    double t, z, c, s;
    if(abs(xj)>abs(xi)){
        t = xi/xj;
        z = sqrt(1+pow(t,2));
        s = 1/z;
        c = t*s;
	}
    else{
        t = xj/xi;
        z = sqrt(1+pow(t,2));
        c = 1/z;
        s = t*c;
    }
    G(i,i) = c;
    G(i,j) = c;
    G(j,j) = -s;
    G(j,i) = s;
    return G;

}

mat Givens::get_R(){
	return this->R;
	}
mat Givens::get_Q(){
	return this->Q;
	}
mat Givens::get_Resultado(){
	return this->resultado;
	}

void Givens::set_result(mat b){
	int m = this->Q.n_rows;
	this->resultado = inv(this->R)*this->Q.t()*b; //resultado 
	this->error = norm(eye(m,m)-inv(inv(this->R)*this->Q.t())*inv(this->R)*this->Q.t()); //givens error
	}

void Givens::save_res(int type){
	mat aux = zeros(1,1);
	aux(0,0) = this->error;
	if(type == 289){
		this->resultado.save("Archivos/Givens289.dat", raw_binary);
		aux.save("Archivos/GivensError289.dat", raw_binary);
		}
	else if(type == 1089){
		this->resultado.save("Archivos/Givens1089.dat",raw_binary);
		aux.save("Archivos/GivensError1089.dat", raw_binary);
		}
	else if(type == 4225){
		this->resultado.save("Archivos/Givens4225.dat",raw_binary);
		aux.save("Archivos/GivensError4225.dat", raw_binary);
		}
	}
