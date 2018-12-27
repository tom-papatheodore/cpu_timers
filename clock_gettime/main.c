/* -----------------------------------------------------------
 * Simple test code to show the use of clock_gettime as a
 * CPU timer.
 * ----------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdint.h>

#define N 10000000

double A[N];
double B[N];

int main(int argc, char** argv)
{

	double sum = 0.0;
	double tolerance = 1.0e-5;
	double max_value = 1.0;

	// Declare timespec structs and get start time.
	struct timespec start_time, end_time;
	clock_gettime(CLOCK_MONOTONIC_RAW, &start_time);

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

	// Get end time in microseconds
	clock_gettime(CLOCK_MONOTONIC_RAW, &end_time);
    uint64_t delta_us = (end_time.tv_sec - start_time.tv_sec) * 1000000 + (end_time.tv_nsec - start_time.tv_nsec) / 1000;

	// Print elapsed time - converting to seconds
	printf("Elapsed Time (s): %10.7f s\n", (double)delta_us/(double)1000000.0);

	return 0;
}
