#include <armadillo>
#include <string>
#include "Givens.h" 
using namespace arma;
using namespace std;

//GIVENS

void Givens::set_values (mat A){
	mat Q, R;
	//double raiz, s, c;
	double xi, xj;
	int i, j, k;
    int m = A.n_rows;
    int n = A.n_cols;
    R = A;
    Q=Q.eye(m,n);
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
	for(j=0;j<n;j++){
		for(i=j+1;i<m;i++){
			if (R(i,j)!=0){
				xi = R(i,j);
				xj = R(i,j);
				mat G = makeGivens(m,i,j,xi,xj);
				Q = Q*G.t();
				R = G*R;
				
			}
		}
	}
/*[m, n] = size(A);
Q=eye(m);
contGivens = 0;
contAux = 0;
for j=1:n
    for i=1(j+1):m;
        if A(i,j)~=0
            xi = A(i,j);
            xj = A(i,j);
            [G,contAux] = makeGivens(m,i,j,xi,xj);
            Q = Q*G';
            A = G*A;
            [n1,m1] = size(A);
            [n2,m2] = size(Q);
            [n3,m3] = size(G);
            contGivens = contGivens+2 + contAux + (n1*m1)+(n2*m2)+(n3*m3);
        end
    end
end
%r = triu(A);

X=inv(A) * Q' * b;
*/	
	cout<<"Terminando givens..."<<endl;
	this->Q = Q;
	this->R = R;
	this->A = A;
}
mat Givens::makeGivens(int m,int i,int j,double xi,double xj){
    mat G;
    G = G.eye(m,m);
    double t, z, c, s;
    //raiz = sqrt(pow(R(k,i),2) + pow(R(i,i),2));
    //s = -R(k,i)/raiz;
    //c = R(i,i)/raiz;
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
	//mat SolY, solXUWU,invQ, invR;
	//SolY = solve(this->P.t()*this->L,b);
	//invQ = inv(this->Q);
	//invR = inv(this->R);
	//SolY = invQ*b;
	//cout<<"Solucion Y con LU: \n";
	//cout<<SolY;
	//this->resultado = solve(this->U,SolY);
	//this->resultado = invR*SolY;
	this->resultado = inv(this->R)*this->Q.t()*b;
	cout<<"resultado givens: \n";
	cout<<this->resultado;
	}
