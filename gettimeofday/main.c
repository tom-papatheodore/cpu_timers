/* -----------------------------------------------------------
 * Simple test code to show the use of gettimeofday as a
 * CPU timer.
 * ----------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/time.h>

#define N 10000000

double A[N];
double B[N];

int main(int argc, char** argv)
{

	double sum = 0.0;
	double tolerance = 1.0e-5;
	double max_value = 1.0;

	struct timeval start_time, stop_time, elapsed_time;
	gettimeofday(&start_time, NULL);	

	for(int i=0; i<N; i++){
		A[i] = (double)rand()/(double)(RAND_MAX/max_value);
		B[i] = (double)rand()/(double)(RAND_MAX/max_value);
		sum = sum + sin(A[i])*sin(A[i]) + cos(B[i])*cos(B[i]);
	}	

	sum = sqrt(sum)/N;

	if(abs(sum - 1.0) > tolerance){
		printf("The value of sum is NOT equal to 1\n");
		return EXIT_FAILURE;
	}

	gettimeofday(&stop_time, NULL);
    timersub(&stop_time, &start_time, &elapsed_time);

	printf("Elapsed Time (s): %10.7f s\n", elapsed_time.tv_sec+elapsed_time.tv_usec/1000000.0);

	return 0;
}
