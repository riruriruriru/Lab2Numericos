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
	int cont = 0;
	int n = AA.n_rows;
	int m = AA.n_cols;
	vec bb = b.as_col();
	/*mat::col_iterator col_it     = AA.begin_col(0);  // start of column 1
    mat::col_iterator col_it_end = AA.end_col(m-1);    //   end of column 3
    for(; col_it != col_it_end; ++col_it)
      {
      cout << (*col_it) << endl;
      //(*col_it) = 123.0;
      
      //x(1,cont) = b*(*col_it)/(*col_it)*(*col_it)
      cont++;
      break;
      }
	*/
	cout<<"Solucion min square"<<endl;
	/*for(int i = 0;i<m;i++){
		vec col = AA.col(i).as_col();
		//cout<<"Col tanspose Filas - Columnas: "<< colt.n_rows << "-" << colt.n_cols<<endl;
		//mat col = AA.col(i);
		//cout<<"Col regular Filas - Columnas: "<< col.n_rows << "-" << col.n_cols<<endl;
		//cout<<"B: Filas - Columnas: "<< b.n_rows << "-" << b.n_cols<<endl;
		//mat mul1 =b.t()*col;
		//mat mul2 = colt*col;
		//mat div = mul1/mul2;
		//cout<<"Mul1: Filas - Columnas: "<< mul1.n_rows << "-" << mul1.n_cols<<endl;
		//cout<<"Mul2: Filas - Columnas: "<< mul2.n_rows << "-" << mul2.n_cols<<endl;
		double uwu = as_scalar(bb*col);
		double uwu2 = as_scalar(col*col);
		x(i,0) = uwu/uwu2;
		}*/
	x = inv(AA.t()*AA)*AA.t()*b;
	//cout<<x<<endl;
	cout<<"###################"<<endl;
	this->resultado = x;
	
	
	//cout<< this->resultado;
	}

void MinCuadrados::save_res(int type){
	if(type == 289){
		this->resultado.save("Min289.dat",raw_binary);
		}
	else if(type == 1089){
		this->resultado.save("Min1089.dat",raw_binary);
		}
	else if(type == 4225){
		this->resultado.save("Min4225.dat",raw_binary);
		}
	}
