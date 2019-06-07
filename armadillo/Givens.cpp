#include <armadillo>
#include <string>
#include "Givens.h" 
using namespace arma;
using namespace std;

//GIVENS

void Givens::set_values (mat A){
	mat Q, R, G;
	//double raiz, s, c;
	double xi, xj;
	int i, j, k;
    int m = A.n_rows;
    int n = A.n_cols;
    R = A;
    //this->A = A;
    /*Q = eye<mat>(m,m);;
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
	*/
	//[m, n] = size(A);
	Q=eye<mat>(m,m);
	for(j=0;j<n;j++){
		for(i=j+1;i<m;i++){
			if (A(i,j)!=0){
				xi = A(i,j);
				xj = A(i,j);
				G = makeGivens(m,i,j,xi,xj);
				Q = Q*G.t();
				A = G*A;
				
			}
		}
	}
	cout<<"Terminando givens..."<<endl;
	this->Q = Q;
	this->R = R;
	this->A = A;
	int uwu3 = Q.n_rows;
	int uwu4 = R.n_rows;
	if(uwu3 ==0){
		cout<< "matriz Q"<<uwu3<<endl;
	}
	if(uwu4 ==0){
		cout<< "matriz R"<<uwu4<<endl;
	}
}
mat Givens::makeGivens(int m,int i,int j,double xi,double xj){
    mat G = eye<mat>(m,m);;
    double t, z, c, s;
    if(abs(xj)>abs(xi)){
        t = xi/xj;
        z = sqrt(1+t*t);
        s = 1/z;
        c = t*s;
	}
    else{
        t = xj/xi;
        z = sqrt(1+t*t);
        c = 1/z;
        s = t*c;
    }
    G(i,i) = c;
    G(i,j) = c;
    G(i,j) = -s;
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
	//mat SolY, solXUWU,invQ, invR;
	//SolY = solve(this->P.t()*this->L,b);
	//invQ = inv(this->Q);
	//invR = inv(this->R);
	//SolY = invQ*b;
	//cout<<"Solucion Y con LU: \n";
	//cout<<SolY;
	//this->resultado = solve(this->U,SolY);
	//this->resultado = invR*SolY;
	this->resultado = inv(this->A)*this->Q.t()*b;
	cout<<"resultado givens: \n";
	cout<<this->resultado;
	}
