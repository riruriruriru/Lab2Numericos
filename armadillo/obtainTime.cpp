#include <iostream>
#include <armadillo>
#include <string>
#include "obtainTime.h"
#include <time.h>
 
using namespace arma;
using namespace std;



long obtainTime::diff(timespec start, timespec end, int type)
{
	timespec temp;
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
void obtainTime::set_total_timeLU(){
	timespec time1, time2;
	time1 = this->timeLU[0];
	time2 = this->timeLU[1];
	this->timeLUSec = this->diff(time1,time2,1);//SEGUNDOS
	this->timeLUNSec = this->diff(time1,time2,2);//NANOSEGUNDOS
	cout<<this->timeLUSec<<":"<<this->timeLUNSec<<endl;
	}
void obtainTime::set_total_timeCholesky(){}
void obtainTime::set_total_timeQR(){}
void obtainTime::set_total_timeGivens(){}
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

