#include <iostream>
#include <armadillo>
#include <string>
#include <time.h>
#ifndef OBTAIN_TIME_H // include guard
#define OBTAIN_TIME_H
using namespace arma;
using namespace std;
	class obtainTime {
	  public:
		timespec timeLU[2], timeCholesky[2], timeQR[2], timeGivens[2], timeHousholder[2];
		long timeLUSec, timeLUNSec, timeChoSec, timeChoNSec, timeQRSec, timeQRNSec, timeGivSec, timeGivNSec;
	  public:
		void init_time_LU();
		void init_time_Cholesky();
		void init_time_QR();
		void init_time_Givens();
		void init_time_Housholder();
		void end_time_LU();
		void end_time_Cholesky();
		void end_time_QR();
		void end_time_Givens();
		void end_time_Housholder();
		void set_total_timeLU();
		void set_total_timeCholesky();
		void set_total_timeQR();
		void set_total_timeGivens();
		void set_total_timeHouseholder();
		long diff(timespec start, timespec end, int type);
		long get_timeLUSec();
		long get_timeLUNSec();
		long get_timeChoSec();
		long get_timeChoNSec();
		long get_timeQRSec();
		long get_timeQRNSec();
		long get_timeGivSec();
		long get_timeGivNSec(); 
	};
#endif
