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
#define PY_SSIZE_T_CLEAN

using namespace std; 
using namespace arma;
timespec diff(timespec start, timespec end);
 

int main(int argc, const char **argv) {	
	//for (int i = 0; i< 242000000; i++)
	//	temp+=temp;
	//clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time2);
	LU lu;
	Chol cholesky;
	QR qr;
	Givens giv;
	obtainTime t;
	Seidel sei;
	
	/*wchar_t *program = Py_DecodeLocale("graficar.py", NULL);
    if (program == NULL) {
        fprintf(stderr, "Fatal error: cannot decode argv[0]\n");
        exit(1);
    }
    Py_SetProgramName(program);  
    Py_Initialize();
    PyRun_SimpleString("from time import time,ctime\n"
                       "print('Today is', ctime(time()))\n");
    if (Py_FinalizeEx() < 0) {
        exit(120);
    }
    PyMem_RawFree(program);
	*/
//using the parameters from your code
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
	t.save_times(289);
	lu.save_res(289);
	cholesky.save_res(289);
	qr.save_res(289);
	giv.save_res(289);
	sei.save_res(289);
	//Fin matriz 289
	
	cout<<"UWU"<<endl;
	bool algo = approx_equal( lu.get_R(), cholesky.get_R(), "reldiff", 0.02 );
	if(algo == true){
		cout<< "resultados iguales uwu\n";
		}
	bool algo2 = approx_equal( lu.get_R(), qr.get_Resultado(), "reldiff", 0.02 );
	if(algo2 == true){
		cout<< "resultados iguales uwu LU y QR\n";
		}
	//cout<<"Resultado QR: \n";
	//cout<<qr.get_Resultado();
	bool algo3 = approx_equal( lu.get_R(), giv.get_Resultado(), "reldiff", 0.02 );
	if(algo3 == true){
		cout<< "resultados iguales uwu LU y GIV\n";
		} 
	bool algo4 = approx_equal( lu.get_R(), sei.get_Resultado(), "reldiff", 0.02 );
	if(algo4 == true){
		cout<< "resultados iguales uwu LU y SEI ultima iteracion\n";
		} 
	bool algo5 = approx_equal( sei.get_resMat().col(93), sei.get_Resultado(), "reldiff", 0.02 );
	if(algo5 == true){
		
		cout<< "resultados sei arreglo [final] y SEI ultima iteracion\n";
		cout<<sei.get_resMat().col(93)<<endl;
		}
	
	
	
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
	//giv.set_values(m.get_value("A4225"));
	//giv.set_result(m.get_value("b4225"));
	t.end_time_Givens();
	t.set_total_timeGivens();
	cout<<"termino givens"<<endl;
	t.init_time_Seidel();
	sei.set_result(m.get_value("A4225"), m.get_value("b4225"), pow(10,-18));
	cout<<"termino seidel"<<endl;
	t.end_time_Seidel();
	t.set_total_timeSeidel();
	t.save_times(4225);
	lu.save_res(289);
	cholesky.save_res(4225);
	qr.save_res(4225);
	//giv.save_res(4225);
	sei.save_res(4225);
	//Fin matriz 4225
	
	//cout<<"Resultado seidel: \n";
	//cout<<sei.get_Resultado()<<endl;
	
	cout<<"inicializando python..."<<endl;
	FILE* cp = fopen("graficar.py", "r");
	Py_Initialize();

	PyRun_SimpleFile(cp, "graficar.py");
	fclose(cp);

	Py_Finalize();  
	
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
