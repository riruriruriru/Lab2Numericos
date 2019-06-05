#include <iostream>
#include <armadillo>
#include <string> // for string class 
#include <time.h>
#include "matrix.h"
#include "LU.h"
using namespace std; 
using namespace arma;
timespec diff(timespec start, timespec end);
 

int main(int argc, const char **argv) {	
    //I = pinv(A);
    //Ly = b
    //Ux = y
    //P.t()*L*U*x = b
    //cout << I;
	mat ident = eye(5,5);
	timespec time1, time2;
	int temp;
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time1);
	for (int i = 0; i< 242000000; i++)
		temp+=temp;
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time2);
	cout<<diff(time1,time2).tv_sec<<":"<<diff(time1,time2).tv_nsec<<endl;
	// automatically detect format type while loading
	Matrix m;
	m.set_values();
	mat A289;
	A289 = m.get_value("A289");
	mat solX, b289;
	b289 = m.get_value("b289");
	//cout << uwu;
	LU lu;
	cout<< "UWU\n";
	lu.set_values(A289);
	//cout << lu.get_L();
	cout << "OWO\n";
	cout << solX;
	cout << "SOLUCION: \n";
	solX = solve( A289, b289 );
	//cout << solX;
	mat SolY, solXUWU;
	SolY = solve(lu.get_P().t()*lu.get_L(),b289);
	cout<<"Solucion Y con LU: \n";
	//cout<<SolY;
	solXUWU = solve(lu.get_U(),SolY);
	cout<< "Solucion x con LU: \n";
	//cout<< solXUWU;
	lu.set_result(b289);
	bool boolean = approx_equal(solX, lu.get_R(), "reldiff", 0.002);
	if(boolean == true){
		cout<<"TRUE\n";
		cout<<solXUWU;
		cout<<"\n";
		}
	else{
		cout<<"GALSE";
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
