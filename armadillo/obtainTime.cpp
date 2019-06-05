#include <armadillo>
#include <string>
#include "obtainTime.h"
#include <time.h>
 
using namespace arma;
using namespace std;




void obtainTime::init_time_LU(){
	//clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &this->timeLU[0]);
	}
void obtainTime::init_time_Cholesky(){}
void obtainTime::init_time_QR(){}
void obtainTime::init_time_Givens(){}
void obtainTime::init_time_Housholder(){}
void obtainTime::end_time_LU(){
	//clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &this->timeLU[1]);
	}
void obtainTime::end_time_Cholesky(){}
void obtainTime::end_time_QR(){}
void obtainTime::end_time_Givens(){}
void obtainTime::end_time_Housholder(){}
void obtainTime::set_total_timeLU(){
	
	//cout<<diff(this->timeLU[0],this->timeLU[1]).tv_sec<<":"<<diff(this->timeLU[0],this->timeLU[1]).tv_nsec<<endl;
	//this->timeLU[2] = diff(this->timeLU[0],this->timeLU[1]).tv_sec;//SEGUNDOS
	//this->timeLU[3] = diff(this->timeLU[0],this->timeLU[1]).tv_nsec<<endl;//NANOSEGUNDOS
	}
void obtainTime::set_total_timeCholesky(){}
void obtainTime::set_total_timeQR(){}
void obtainTime::set_total_timeGivens(){}
void obtainTime::set_total_timeHouseholder(){}
