#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <signal.h>

static int signal_count = 0;
struct timeval before, after;

void handle_sigfpe(int signum) {
	signal_count++;
	
	if (signal_count == 100000) {
		gettimeofday(&after, NULL);
		
		float sec = (after.tv_sec - before.tv_sec);
		float usec = (after.tv_usec - before.tv_usec);

		// solution for negative time
		if (usec < 0) usec += 1000000;

		float time = (sec + usec) / 1000;		
		
		printf("Exceptions Occurred: %d\n", signal_count);
		printf("Total Elapsed Time: %f ms\n", time);
		printf("Average Time Per Exception: %f ms\n", time / 100000);
		exit(0);
	}
}

int main(int argc, char **argv) {
	int x = 5;
	int y = 0;
	int z;

	gettimeofday(&before, NULL);
	signal(SIGFPE, handle_sigfpe);
	z = x / y;
	y = z; // gets rid of warning
	return 0;
}
