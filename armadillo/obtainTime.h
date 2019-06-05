#include <armadillo>
#include <string> // for string class
#include <time.h>
#ifndef OBTAIN_TIME_H // include guard
#define OBTAIN_TIME_H
using namespace arma;
using namespace std;
	class obtainTime {
	  public:
		timespec timeLU[4], timeCholesky[4], timeQR[4], timeGivens[4], timeHousholder[4];
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
	};
#endif
