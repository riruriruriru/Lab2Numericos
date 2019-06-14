#include <armadillo>
#include <string>
#include "Seidel.h" 
using namespace arma;
using namespace std;

//Gauss Seidel

void Seidel::set_result(mat A, mat b, double tol){
	int m = A.n_rows;
	int contador = 0;
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
    for(i = 0;i<1000;i++){ 
       jj = inv(D+E) * -F;
       c = inv(D+E) * b;
       x1 = jj*x0 + c;//se calcula la aproximacion de la iteracion actual
       e = norm(x1 - x0, "inf")/norm(x1, "inf");//se calcula el error de la iteracion actual
       ee(0,0) = e;
       soluciones = join_horiz(soluciones, x1); //JOIN //senorm guarda la aproximacion de la iteracion actual
       errores = join_horiz(errores, ee); //Se actualiza el error segun la iteracion actual
       contador++;
       if(e < tol){ //si se alcanza la tolerancia, se finaliza
           break;
       }
       x0 = x1;
    }
    this->iteraciones = zeros(1,1);
    this->iteraciones(0,0) = contador;
    this->error = zeros(1,1);
    this->error(0,0) = e;
    this->err = errores;
	this->resultado = x0;
	this->resMat = soluciones;
	cout<< "Iteraciones"<< this->iteraciones<<endl;
	cout<< "Error"<< this->error<<endl;
	cout<< "Soluciones"<<endl;
	cout<< this->resMat.n_rows<<"-"<<this->resMat.n_cols <<endl;
	cout<< "Errores"<< endl;
	cout<< this->err.n_rows<<"-"<<this->err.n_cols <<endl;
	}
mat Seidel::get_Resultado(){
	return this->resultado;
	}
mat Seidel::get_error(){
	return this->error;
	}
mat Seidel::get_err(){
	return this->err;
	}
mat Seidel::get_resMat(){
	return this->resMat;		
	}
	
void Seidel::save_res(int type){
	if(type == 289){
		this->resultado.save("Archivos/Seidel289Solucion.dat",raw_binary);
		this->iteraciones.save("Archivos/Seidel289Iteraciones.dat",raw_binary);
		this->error.save("Archivos/Seidel289error.dat",raw_binary);
		this->err.save("Archivos/Seidel289Errores.dat",raw_binary);
		this->resMat.save("Archivos/Seidel289Soluciones.dat",raw_binary);
		}
	else if(type == 1089){
		this->resultado.save("Archivos/Seidel1089Solucion.dat",raw_binary);
		this->iteraciones.save("Archivos/Seidel1089Iteraciones.dat",raw_binary);
		this->error.save("Archivos/Seidel1089error.dat",raw_binary);
		this->err.save("Archivos/Seidel1089Errores.dat",raw_binary);
		this->resMat.save("Archivos/Seidel1089Soluciones.dat",raw_binary);
		}
	else if(type == 4225){
		this->resultado.save("Archivos/Seidel4225Solucion.dat",raw_binary);
		this->iteraciones.save("Archivos/Seidel4225Iteraciones.dat",raw_binary);
		this->error.save("Archivos/Seidel4225error.dat",raw_binary);
		this->err.save("Archivos/Seidel4225Errores.dat",raw_binary);
		this->resMat.save("Archivos/Seidel4225Soluciones.dat",raw_binary);
		}
	}
