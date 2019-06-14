#include <iostream>
#include <armadillo>
#include <string>
#include "obtainTime.h"
#include <time.h>
 
using namespace arma;
using namespace std;



unsigned long long obtainTime::diff(timespec start, timespec end, int type)
{
	timespec temp;
	//cout<<"Nanosegundos: "<<end.tv_nsec<<endl;
	if ((end.tv_nsec-start.tv_nsec)<0) {
		temp.tv_sec = end.tv_sec-start.tv_sec-1;
		temp.tv_nsec = 1000000000+end.tv_nsec-start.tv_nsec;
	} else {
		temp.tv_sec = end.tv_sec-start.tv_sec;
		temp.tv_nsec = end.tv_nsec-start.tv_nsec;
	}
	if(type == 1){
		return temp.tv_sec;
		}
	else{
		return temp.tv_nsec;
		}
	
}
void obtainTime::init_time_LS(){
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &this->timeLS[0]);
	}
void obtainTime::end_time_LS(){
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &this->timeLS[1]);
	}
long obtainTime::get_time_LSSec(){
	return this->timeLSSec;
	}
long obtainTime::get_time_LSNSec(){
	return this->timeLSNSec;
	}
void obtainTime::set_total_timeLS(){
	timespec time1, time2;
	time1 = this->timeLS[0];
	time2 = this->timeLS[1];
	this->timeLSSec = this->diff(time1,time2,1);//SEGUNDOS
	this->timeLSNSec = this->diff(time1,time2,2);//NANOSEGUNDOS
	cout<<"Tiempo Minimos Cuadrados segundos-nanosegundos: "<<this->timeLSSec<<":"<<this->timeLSNSec<<endl;
	}

void obtainTime::init_time_LU(){
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &this->timeLU[0]);
	}
void obtainTime::init_time_Cholesky(){
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &this->timeCholesky[0]);
	}
void obtainTime::init_time_QR(){
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &this->timeQR[0]);
	}
void obtainTime::init_time_Givens(){
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &this->timeGivens[0]);
	}
void obtainTime::init_time_Seidel(){
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &this->timeSeidel[0]);
	}

void obtainTime::end_time_LU(){
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &this->timeLU[1]);
	}
void obtainTime::end_time_Cholesky(){
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &this->timeCholesky[1]);
	}
void obtainTime::end_time_QR(){
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &this->timeQR[1]);
	}
void obtainTime::end_time_Givens(){
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &this->timeGivens[1]);
	}
void obtainTime::end_time_Seidel(){
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &this->timeSeidel[1]);
	}
void obtainTime::set_total_timeLU(){
	timespec time1, time2;
	time1 = this->timeLU[0];
	time2 = this->timeLU[1];
	this->timeLUSec = this->diff(time1,time2,1);//SEGUNDOS
	this->timeLUNSec = this->diff(time1,time2,2);//NANOSEGUNDOS
	cout<<"Tiempo LU segundos-nanosegundos: "<<this->timeLUSec<<":"<<this->timeLUNSec<<endl;
	}
void obtainTime::set_total_timeCholesky(){
	timespec time1, time2;
	time1 = this->timeCholesky[0];
	time2 = this->timeCholesky[1];
	this->timeChoSec = this->diff(time1,time2,1);//SEGUNDOS
	this->timeChoNSec = this->diff(time1,time2,2);//NANOSEGUNDOS
	cout<<"Tiempo Cholesky segundos-nanosegundos: "<<this->timeChoSec<<":"<<this->timeChoNSec<<endl;
	}
void obtainTime::set_total_timeQR(){
	timespec time1, time2;
	time1 = this->timeQR[0];
	time2 = this->timeQR[1];
	this->timeQRSec = this->diff(time1,time2,1);//SEGUNDOS
	this->timeQRNSec = this->diff(time1,time2,2);//NANOSEGUNDOS
	cout<<"Tiempo QR segundos-nanosegundos: "<<this->timeQRSec<<":"<<this->timeQRNSec<<endl;
	}
void obtainTime::set_total_timeGivens(){
	timespec time1, time2;
	time1 = this->timeGivens[0];
	time2 = this->timeGivens[1];
	this->timeGivSec = this->diff(time1,time2,1);//SEGUNDOS
	this->timeGivNSec = this->diff(time1,time2,2);//NANOSEGUNDOS
	cout<<"Tiempo Givens segundos-nanosegundos: "<<this->timeGivSec<<":"<<this->timeGivNSec<<endl;
	}
void obtainTime::set_total_timeSeidel(){
	timespec time1, time2;
	time1 = this->timeSeidel[0];
	time2 = this->timeSeidel[1];
	this->timeSeiSec = this->diff(time1,time2,1);//SEGUNDOS
	this->timeSeiNSec = this->diff(time1,time2,2);//NANOSEGUNDOS
	cout<<"Tiempo Seidel segundos-nanosegundos: "<<this->timeSeiSec<<":"<<this->timeSeiNSec<<endl;
	
	}
long obtainTime::get_timeLUSec(){
	return this->timeLUSec;
	}
long obtainTime::get_timeLUNSec(){
	return this->timeLUNSec;
	}
long obtainTime::get_timeChoSec(){
	return this->timeChoSec;
	}
long obtainTime::get_timeChoNSec(){
	return this->timeChoNSec;
	}
long obtainTime::get_timeQRSec(){
	return this->timeQRSec;
	}
long obtainTime::get_timeQRNSec(){
	return this->timeQRNSec;
	}
long obtainTime::get_timeGivSec(){
	return this->timeGivSec;
	}
long obtainTime::get_timeGivNSec(){
	return this->timeGivNSec;
	}

long obtainTime::get_timeSeiSec(){
	return this->timeSeiSec;
	}
long obtainTime::get_timeSeiNSec(){
	return this->timeSeiNSec;
	}
void obtainTime::save_times(int type){
	vec tSec = zeros<vec>(6);
	vec tNSec = zeros<vec>(6);
	tSec(0) = this->timeLUSec;
	tSec(1) = this->timeChoSec;
	tSec(2) = this->timeQRSec;
	tSec(3) = this->timeLSSec;
	tSec(4) = this->timeGivSec;
	tSec(5) = this->timeSeiSec;
	
	tNSec(0) = this->timeLUNSec;
	tNSec(1) = this->timeChoNSec;
	tNSec(2) = this->timeQRNSec;
	tNSec(3) = this->timeLSNSec;
	tNSec(4) = this->timeGivNSec;
	tNSec(5) = this->timeSeiNSec;
	
	cout<< "Arreglo segundos: LU-CHO-QR-LS-GIV-SEI"<<endl;
	cout<< tSec<<endl;
	cout<< "Arreglo nano segundos: LU-CHO-QR-LS-GIV-SEI"<<endl;
	cout<< tNSec<<endl;
	if(type == 289){
		tSec.save("Archivos/timeSegundos289.dat", raw_binary);
		tNSec.save("Archivos/timeNanoSegundos289.dat", raw_binary);
		}
	else if(type == 1089){
		tSec.save("Archivos/timeSegundos1089.dat", raw_binary);
		tNSec.save("Archivos/timeNanoSegundos1089.dat", raw_binary);
		}
	else if(type == 4225){
		tSec.save("Archivos/timeSegundos4225.dat", raw_binary);
		tNSec.save("Archivos/timeNanoSegundos4225.dat", raw_binary);
		}
	}

