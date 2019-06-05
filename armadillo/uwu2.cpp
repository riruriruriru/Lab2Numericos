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
	mat solX(3,1);
	mat matrizA = {{1, 1, 1}, {4, 3, -1}, {3, 5, 3}}; 
    mat B(3,1);
    B(0,0) = 1;
    B(1,0) = 6;
    B(2,0) = 4; 
    //I = pinv(A);
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
	mat uwu;
	uwu = m.get_value("A289");
	//cout << uwu;
	LU lu;
	cout<< "UWU\n";
	lu.set_values(matrizA);
	cout << lu.get_L();
	cout << "OWO\n";
	cout << matrizA;
	cout << "OWO\n";
	cout << B;
	cout << "OWO\n";
	cout << solX;
	cout << "SOLUCION: \n";
	solX = solve( matrizA, B );
	cout << solX;
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
