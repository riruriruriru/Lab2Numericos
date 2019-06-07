#include <iostream>
#include <armadillo>
#include <string> // for string class 
#include <time.h>
#include "matrix.h"
#include "LU.h"
#include "obtainTime.h"
#include "Chol.h"
#include "QR.h"
#include "Givens.h"
#include "Seidel.h"
using namespace std; 
using namespace arma;
timespec diff(timespec start, timespec end);
 

int main(int argc, const char **argv) {	
	timespec time1, time2;
	int temp;
	//for (int i = 0; i< 242000000; i++)
	//	temp+=temp;
	//clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time2);
	LU lu;
	Chol cholesky;
	QR qr;
	Givens giv;
	obtainTime t;
	Seidel sei;
	Matrix m;
	m.set_values();
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time1);
	t.init_time_LU();
	lu.set_values(m.get_value("A289"));
	lu.set_result(m.get_value("b289"));
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time2);
	t.end_time_LU();
	t.set_total_timeLU();
	cout<<diff(time1,time2).tv_sec<<":"<<diff(time1,time2).tv_nsec<<endl;//SEGUNDOS Y NANOSEGUNDOS
	cholesky.set_values(m.get_value("A289"));
	cholesky.set_result(m.get_value("b289"));
	qr.set_values(m.get_value("A289"));
	qr.set_result(m.get_value("b289"));
	giv.set_values(m.get_value("A289"));
	giv.set_result(m.get_value("b289"));
	sei.set_result(m.get_value("A289"), m.get_value("b289"), pow(10,-18));
	//cout<<"Resultado seidel: \n";
	//cout<<sei.get_Resultado()<<endl;
	cout<<"UWU"<<endl;
	bool algo = approx_equal( lu.get_R(), cholesky.get_R(), "reldiff", 0.02 );
	if(algo == true){
		cout<< "resultados iguales uwu\n";
		}
	bool algo2 = approx_equal( lu.get_R(), qr.get_Resultado(), "reldiff", 0.02 );
	if(algo2 == true){
		cout<< "resultados iguales uwu LU y QR\n";
		}
	cout<<"Resultado QR: \n";
	cout<<qr.get_Resultado();
	bool algo3 = approx_equal( lu.get_R(), giv.get_Resultado(), "reldiff", 0.02 );
	if(algo3 == true){
		cout<< "resultados iguales uwu LU y GIV\n";
		} 
	bool algo4 = approx_equal( lu.get_R(), sei.get_Resultado(), "reldiff", 0.02 );
	if(algo4 == true){
		cout<< "resultados iguales uwu LU y SEI ultima iteracion\n";
		} 
	
	return 0;
	
 }


timespec diff(timespec start, timespec end)
{
	timespec temp;
	if ((end.tv_nsec-start.tv_nsec)<0) {
		temp.tv_sec = end.tv_sec-start.tv_sec-1;
		temp.tv_nsec = 1000000000+end.tv_nsec-start.tv_nsec;
	} else {
		temp.tv_sec = end.tv_sec-start.tv_sec;
		temp.tv_nsec = end.tv_nsec-start.tv_nsec;
	}
	return temp;
}
