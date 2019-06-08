#include <armadillo>
#include <string>
#include "Seidel.h" 
using namespace arma;
using namespace std;

//Gauss Seidel

void Seidel::set_result(mat A, mat b, double tol){
	int m = A.n_rows;
    int n = A.n_cols;
    mat D, E, F, x0;
    int i, j, aux = 1;
    D = zeros(n,m);
    E = zeros(n,m);
    F = zeros(n,m);
    for(i = 0; i<n;i++){
       D(i, i) = A(i, i);
       for(j = 0;j< aux;j++){
          E(i, j) = A(i, j); 
          F(j, i) = A(j, i);
       }
       E(i, i) = 0;
       F(i, i) = 0;
       aux = aux + 1;
       
    }
    x0 = zeros(n,1);
    mat errores, soluciones, x1, jj, c;
    mat ee;
    ee = zeros(1,1);
    double e;
    x1 = zeros(n,1);
    errores = zeros(1,n);
    soluciones = zeros(n,1);
    for(i = 0;i<1000;i++){ //CAMBIAR A 1000 ITERACIONES
       jj = inv(D+E) * -F;
       c = inv(D+E) * b;
       x1 = jj*x0 + c;//se calcula la aproximacion de la iteracion actual
       //cout<<"X1:" <<endl;
       //cout<<x1<<endl;
       //cout<<"X0:" <<endl;
       //cout<<x0<<endl;
       //cout<<"X1-X0:" <<endl;
       //cout<<x1-x0<<endl;
       //cout<<"INF"<<endl;
       //cout<<datum::inf<<endl;
       e = norm(x1 - x0, "inf")/norm(x1, "inf");//se calcula el error de la iteracion actual
       
       ee(0,0) = e;
       soluciones = join_horiz(soluciones, x1); //JOIN //senorm guarda la aproximacion de la iteracion actual
       errores = join_horiz(errores, ee); //Se actualiza el error segun la iteracion actual
       if(e < tol){ //si se alcanza la tolerancia, se finaliza
           break;
       }
       x0 = x1;
    }
    
    /*    [n ,n] = size(A);
	
    D = zeros(n, n); %Se crean las matrices D, E y F
    E = zeros(n, n);
    F = zeros(n, n);
    aux = 1;
    contSeidel = 0;
    for i = 1 : n
       D(i, i) = A(i, i);
       for j = 1 : aux
          E(i, j) = A(i, j); 
          F(j, i) = A(j, i);
       end
       E(i, i) = 0;
       F(i, i) = 0;
       aux = aux + 1;
       
    end
    x0 = zeros(n ,1);
    soluciones = [];
    errores = [];
    for i = 1 : 1000
       j = inv(D+E) * -F;
       c = inv(D+E) * b;
       x1 = j*x0 + c;%se calcula la aproximacion de la iteracion actual
       e = norm(x1 - x0, inf)/norm(x1, inf);%se calcula el error de la iteracion actual
       soluciones = [soluciones, x1]; %se guarda la aproximacion de la iteracion actual
       errores = [errores, e]; %Se actualiza el error segun la iteracion actual
       [aa,bb] = size(j);
       [a1,b1] = size(c);
       [a2,b2] = size(e);
       contSeidel = contSeidel+2+(a1*b1)+(aa*bb);
       if(e < tol) %si se alcanza la tolerancia, se finaliza
           break
       end
       x0 = x1;
    end
contSeidel = contSeidel+2;
	*/
	this->resultado = x0;
	}
mat Seidel::get_Resultado(){
	return this->resultado;
	}
void Seidel::save_res(int type){
	if(type == 289){
		this->resultado.save("Seidel289.dat");
		}
	else if(type == 1089){
		this->resultado.save("Seidel1089.dat");
		}
	else if(type == 4225){
		this->resultado.save("Seidel4225.dat");
		}
	}
