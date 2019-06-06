#include <armadillo>
#include <string>
#include "Givens.h" 
using namespace arma;
using namespace std;

//GIVENS

void Givens::set_values (mat A){
	mat Q, R, G;
	double raiz, s, c;
	int i, j, k;
    int m = A.n_rows;
    int n = A.n_cols;
    Q = eye<mat>(m,m);;
    R = A;
    for(i=0;i<n;i++){
        for(k=i+1;k<m;k++){
            if (R(k,i) != 0){
                raiz = sqrt(pow(R(k,i),2) + pow(R(i,i),2));
                s = -R(k,i)/raiz;
                c = R(i,i)/raiz;
                G = eye<mat>(m,m);
                G(i,i) = c;
                G(k,k) = c;
                G(k,i) = -s;
                G(i,k) = s;
                Q = Q*G; // Matriz ortogonal
                R = G.t()*R; // Matriz triangular inferior
			}
		}
		
	}
	this->Q = Q;
	this->R = R;
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
