#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

struct timeval before,after;

int main(int argc, char **argv) {
	gettimeofday(&before, NULL);

	int i;
	for (i = 0; i < 100000; i++) {
		getpid();
	}

	gettimeofday(&after, NULL);

	float sec = (after.tv_sec - before.tv_sec);
	float msec = (after.tv_usec - before.tv_usec);
	float total_time = (sec + msec) / 1000;


	printf("Syscalls Performed: %d\n", i);
	printf("Total Elapsed Time: %f ms\n", total_time);
	printf("Average Time Per Syscall: %f ms\n", total_time / 100000);

	return 0;
}
