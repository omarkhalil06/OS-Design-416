all: time-syscall time-signal

time-syscall: time-syscall.c
	gcc -o time-syscall time-syscall.c

time-signal: time-signal.c
	gcc -o time-signal time-signal.c

clean:
	-rm -f time-syscall
	-rm -f time-signal
