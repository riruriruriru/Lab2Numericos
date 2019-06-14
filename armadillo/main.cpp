#include "python3.6/Python.h"
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
#include "MinCuadrados.h"
#define PY_SSIZE_T_CLEAN

using namespace std; 
using namespace arma;
timespec diff(timespec start, timespec end);
 

int main(int argc, const char **argv) {	
	LU lu;
	Chol cholesky;
	QR qr;
	Givens giv;
	obtainTime t;
	Seidel sei;
	MinCuadrados squared;
	Matrix m;
	m.set_values();
	//Matriz 289
	t.init_time_LU();
	lu.set_values(m.get_value("A289"));
	lu.set_result(m.get_value("b289"));
	t.end_time_LU();
	t.set_total_timeLU();
	t.init_time_Cholesky();
	cholesky.set_values(m.get_value("A289"));
	cholesky.set_result(m.get_value("b289"));
	t.end_time_Cholesky();
	t.set_total_timeCholesky();
	t.init_time_QR();
	qr.set_values(m.get_value("A289"));
	qr.set_result(m.get_value("b289"));
	t.end_time_QR();
	t.set_total_timeQR();
	t.init_time_Givens();
	giv.set_values(m.get_value("A289"));
	giv.set_result(m.get_value("b289"));
	t.end_time_Givens();
	t.set_total_timeGivens();
	cout<<"termino givens"<<endl;
	t.init_time_Seidel();
	sei.set_result(m.get_value("A289"), m.get_value("b289"), pow(10,-18));
	cout<<"termino seidel"<<endl;
	t.end_time_Seidel();
	t.set_total_timeSeidel();
	t.init_time_LS();
	squared.set_values(m.get_value("A289"));
	squared.set_result(m.get_value("b289"));
	t.end_time_LS();
	t.set_total_timeLS();
	squared.save_res(289);
	t.save_times(289);
	lu.save_res(289);
	cholesky.save_res(289);
	qr.save_res(289);
	giv.save_res(289);
	sei.save_res(289);
	//Fin matriz 289
	
	
	//Inicio matriz 1089
	t.init_time_LU();
	lu.set_values(m.get_value("A1089"));
	lu.set_result(m.get_value("b1089"));
	t.end_time_LU();
	t.set_total_timeLU();
	t.init_time_Cholesky();
	cholesky.set_values(m.get_value("A1089"));
	cholesky.set_result(m.get_value("b1089"));
	t.end_time_Cholesky();
	t.set_total_timeCholesky();
	t.init_time_QR();
	qr.set_values(m.get_value("A1089"));
	qr.set_result(m.get_value("b1089"));
	t.end_time_QR();
	t.set_total_timeQR();
	t.init_time_Givens();
	giv.set_values(m.get_value("A1089"));
	giv.set_result(m.get_value("b1089"));
	t.end_time_Givens();
	t.set_total_timeGivens();
	cout<<"termino givens"<<endl;
	t.init_time_Seidel();
	sei.set_result(m.get_value("A1089"), m.get_value("b1089"), pow(10,-18));
	cout<<"termino seidel"<<endl;
	t.end_time_Seidel();
	t.set_total_timeSeidel();
	t.init_time_LS();
	squared.set_values(m.get_value("A1089"));
	squared.set_result(m.get_value("b1089"));
	t.end_time_LS();
	t.set_total_timeLS();
	squared.save_res(1089);
	t.save_times(1089);
	lu.save_res(1089);
	cholesky.save_res(1089);
	qr.save_res(1089);
	giv.save_res(1089);
	sei.save_res(1089);
	//Fin matriz 1089
	//Inicio matriz 4225
	t.init_time_LU();
	lu.set_values(m.get_value("A4225"));
	lu.set_result(m.get_value("b4225"));
	t.end_time_LU();
	t.set_total_timeLU();
	t.init_time_Cholesky();
	cholesky.set_values(m.get_value("A4225"));
	cholesky.set_result(m.get_value("b4225"));
	t.end_time_Cholesky();
	t.set_total_timeCholesky();
	t.init_time_QR();
	qr.set_values(m.get_value("A4225"));
	qr.set_result(m.get_value("b4225"));
	t.end_time_QR();
	t.set_total_timeQR();
	t.init_time_Givens(); 
	giv.set_values(m.get_value("A4225"));
	giv.set_result(m.get_value("b4225"));
	t.end_time_Givens(); 
	t.set_total_timeGivens(); 
	t.init_time_Seidel();
	sei.set_result(m.get_value("A4225"), m.get_value("b4225"), pow(10,-18));
	t.end_time_Seidel();
	t.set_total_timeSeidel();
	t.init_time_LS();
	squared.set_values(m.get_value("A4225"));
	squared.set_result(m.get_value("b4225"));
	t.end_time_LS();
	t.set_total_timeLS();
	squared.save_res(4225);
	t.save_times(4225);
	lu.save_res(4225);
	cholesky.save_res(4225);
	qr.save_res(4225);
	giv.save_res(4225); 
	sei.save_res(4225);
	
	//Fin matriz 4225
	

	cout<<"inicializando python..."<<endl;
	FILE* cp = fopen("graficar.py", "r");
	Py_Initialize();

	PyRun_SimpleFile(cp, "graficar.py");
	fclose(cp);

	Py_Finalize();  
	
	return 0;
	
 }

